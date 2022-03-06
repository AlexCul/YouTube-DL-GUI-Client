#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

#include <QtConcurrent/QtConcurrent>
#include <QFileDialog>
#include <QFuture>

#include "app.h"
#include "ui_app.h"
#include "terminal_functions.h"
using namespace std;


App::App(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::App)
{
    ui->setupUi(this);
}

App::~App()
{
    delete ui;
}

void App::on_close_btn_clicked()
{
    close();
}

void App::on_minimize_btn_clicked()
{
    showMinimized();
}

void App::on_browse_btn_clicked()
{
    QString* path_to_file = new QString(QFileDialog::getExistingDirectory(this, "Browse...", "/home/"));
    // If user didn't choose a directory, we save the same path
    if (*path_to_file == NULL) {
        cout << "We do nothing then\n";
    } else {
        ui->path_to_file_ln_edit->setText(*path_to_file);
    }
    delete path_to_file;
}

void App::on_install_btn_clicked()
{
    // If user tries to install some video with no directory to do it
    if (ui->path_to_file_ln_edit->text() == NULL) {
        ui->path_to_file_ln_edit->setText("../installed/");
    }
    string* link = new string(ui->video_and_playlist_ln_edit->text().toStdString());
    string* directory = new string(ui->path_to_file_ln_edit->text().toStdString());
    vector<string>* parameters = new vector<string>({});
    if (ui->best_all_checkbox->isChecked()) {
        parameters->push_back(" -f bestvideo+bestaudio/best ");
    }
    string* command = new string(installing_command_creating(*link, *directory, *parameters));
    delete link;
    delete directory;
    delete parameters;
    QFuture<void>* installing_thread = new QFuture(QtConcurrent::run(installing_function, *command));
    delete command;
    delete installing_thread;
}
