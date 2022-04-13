#include "kirjaudu.h"
#include "ui_kirjaudu.h"
#include <iostream>

kirjaudu::kirjaudu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kirjaudu)
{
    ui->setupUi(this);

    this->close();
    pPaavalikko = new paavalikko;
}

kirjaudu::~kirjaudu()
{
    delete ui;
    delete pPaavalikko;
}

void kirjaudu::on_pushButton_clicked()
{
    std::cout << "Jatka" << std::flush;
    std::cout << std::endl;
    pPaavalikko->show();
}

void kirjaudu::closeKirjaudu()
{
    this->close();
}

