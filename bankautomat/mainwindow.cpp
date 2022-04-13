#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <iostream>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pKirjaudu = new kirjaudu;
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(closeKirjaudu()));
    timer->start(30000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pKirjaudu;
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
