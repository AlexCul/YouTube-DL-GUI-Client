#include <iostream>
#include <string>
#include <unistd.h>

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
    if (*path_to_file == NULL) {
        *path_to_file = ui->path_to_file_ln_edit->text();
    }
    ui->path_to_file_ln_edit->setText(*path_to_file);
    delete path_to_file;
}

void App::on_install_btn_clicked()
{
    string* link = new string(ui->video_and_playlist_ln_edit->text().toStdString());
    string* directory = new string(ui->path_to_file_ln_edit->text().toStdString());
    QFuture<void> thread = QtConcurrent::run(installing_function, *link, *directory);
    delete link, directory;
}

