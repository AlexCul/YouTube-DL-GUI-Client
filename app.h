#ifndef APP_H
#define APP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget *parent = nullptr);
    ~App();

private slots:
    void on_close_btn_clicked();

    void on_minimize_btn_clicked();

    void on_install_btn_clicked();

private:
    Ui::App *ui;
};
#endif // APP_H
