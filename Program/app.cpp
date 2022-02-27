#include "app.h"
#include "ui_app.h"
#include <iostream>
#include <string>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
using namespace std;


void installing_function(string link) {
    string command = "youtube-dl " + link + " -o ../installed/" + link;
    cout << system(command.c_str());
}

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

void App::on_install_btn_clicked()
{
    string link = ui->video_and_playlist_ln_edit->text().toStdString();
    QFuture<void> thread = QtConcurrent::run(installing_function, link);
}

