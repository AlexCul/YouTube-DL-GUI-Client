#include <QApplication>

#include "app.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    App window;

    // Delete system titlebar
    window.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    window.show();
    return app.exec();
}
