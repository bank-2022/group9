#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>
#include <QTimer>
#include "QSerialPort"
#include "QDebug"
QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pKirjaudu = new kirjaudu;
    timer = new QTimer(this);
    ui->setupUi(this);
    serial = new QSerialPort(this);
    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    //serial->write("ok");
    connect(serial,SIGNAL(readyRead()),this,SLOT(serialRecieved()));


    connect(timer, SIGNAL(timeout()), this, SLOT(closeKirjaudu()));
    timer->start(30000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pKirjaudu;
    serial->close();
}

void MainWindow::closeKirjaudu()
{
    pKirjaudu->close();
}

void MainWindow::on_btnLogin_clicked()
{
    if(pKirjaudu->PINcount >= 3){
        pKirjaudu->pLocked->show();
    }
    else{
        std::cout << "Kortti syotetty" << std::flush;
        std::cout << std::endl;
        pKirjaudu->show();
    }
}
void MainWindow::serialRecieved()
{
    QByteArray ba;
    ba = serial->readAll();
    qDebug()<<ba;

    pKirjaudu->show();
}
