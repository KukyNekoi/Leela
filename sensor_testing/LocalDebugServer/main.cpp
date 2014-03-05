#include "mainwindow.h"
#include <QApplication>
#include <libs/server.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //qRegisterMetaType<std::magdata_t>("<std::magdata_t");
    w.show();

    return a.exec();
}
