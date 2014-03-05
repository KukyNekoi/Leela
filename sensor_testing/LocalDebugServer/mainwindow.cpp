#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "libs/server.h"
#include "libs/serverthread.h"
#include <sstream>
#include <QCoreApplication>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::angle(int angle){
    ui->dataPane->appendPlainText("Angle: " + QString::number(angle) +"°");
}

void MainWindow::on_connectButton_clicked()
{
    //this->s_thread = new ServerThread();
    this->s_thread.setPort(ui->portSpinner->value());

    QObject::connect(&s_thread, SIGNAL(printDebugData(QString)), this, SLOT(printDebugData(QString)), Qt::QueuedConnection);
    QObject::connect(&s_thread, SIGNAL(printStatusData(QString)), this, SLOT(printStatusData(QString)), Qt::QueuedConnection);
    QObject::connect(&s_thread, SIGNAL(sendData(double, double,double)), this, SLOT(getData(double, double, double)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(drawData(double, double,double)), ui->myGLWidget, SLOT(drawData(double, double,double)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(setZero()), ui->myGLWidget, SLOT(setZero()), Qt::QueuedConnection);
    QObject::connect(ui->myGLWidget, SIGNAL(angle(int)), this, SLOT(angle(int)), Qt::QueuedConnection);



    //not used
//    QObject::connect(&s_thread, SIGNAL(sendData(QString)), this, SLOT(writeData(QString)), Qt::QueuedConnection);
//    QObject::connect(&s_thread, SIGNAL(waitForClient(int)), this, SLOT(waitForClient(int)), Qt::QueuedConnection);

    if(!s_thread.isEngaged()){
        s_thread.start();
    }
    else{
        s_thread.quit();
        s_thread.start();
    }



    ui->stopButton->setEnabled(true);
    ui->connectButton->setEnabled(false);
    //s_thread.quit();
    //s_thread.wait();
}

void MainWindow::on_stopButton_clicked()
{
    s_thread.disengage();
    ui->statusPane->appendPlainText("Servidor cerrado.");
    ui->stopButton->setEnabled(false);
    ui->connectButton->setEnabled(true);
}

void MainWindow::printDebugData(QString data){
    ui->dataPane->appendPlainText(data);
    //ui->dataPane->appendPlainText("\n");
}
void MainWindow::printStatusData(QString data){
    ui->statusPane->appendPlainText(data);
    //ui->statusPane->appendPlainText("\n");
}


void MainWindow::getData(double x, double y, double z){
    //std::cout << "event triggered!" << std::endl;
    //ui->dataPane->clear();
    ui->dataPane->appendPlainText("");
    ui->dataPane->appendPlainText("x: " +  QString::number(x));
    ui->dataPane->appendPlainText("y: " +  QString::number(y));
    ui->dataPane->appendPlainText("z: " +  QString::number(z));
    emit drawData(x,y,z);
}

void MainWindow::on_zeroButton_clicked()
{
    emit setZero();
}
