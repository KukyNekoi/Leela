#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <libs/serverthread.h>
#include "libs/server.h"
#include "gl/myglwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();
    void on_stopButton_clicked();
    void printStatusData(QString data);
    void printDebugData(QString data);
    void getData(double x, double y, double z);
    void angle(int angle);

    void on_zeroButton_clicked();

signals:
    void drawData(double x, double y, double z);
    void setZero();

private:
    ServerThread s_thread;
    Ui::MainWindow *ui;
    std::Server *serverInstance;
    std::vector<int> clientVector;
};

#endif // MAINWINDOW_H
