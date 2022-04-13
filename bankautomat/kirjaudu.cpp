#include "kirjaudu.h"
#include "ui_kirjaudu.h"
#include <iostream>

kirjaudu::kirjaudu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kirjaudu)
{
    ui->setupUi(this);

    this->close();
}

kirjaudu::~kirjaudu()
{
    delete ui;
}

void kirjaudu::on_pushButton_clicked()
{
    std::cout << "Jatka" << std::flush;
    std::cout << std::endl;
}

void kirjaudu::closeKirjaudu()
{
    this->close();
}

