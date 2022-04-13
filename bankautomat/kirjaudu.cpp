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
    pWrongPIN = new WrongPIN;
    pLocked = new Locked;
}

kirjaudu::~kirjaudu()
{
    delete ui;
}

void kirjaudu::on_pushButton_clicked()
{
    QString y = ui->PINKentta->text();

    string x = "1234";

    if(PINcount >= 3){
        pLocked->show();
        this->close();
    }
    else{
        if(x == y.toStdString() && PINcount < 3)
        {
            std::cout << "Hyvaksytty" << std::flush;
            std::cout << std::endl;
            pPaavalikko->show();
        }
        else
        {
            PINcount++;
            std::cout << "Hylatty" << std::flush;
            std::cout << std::endl;
            std::cout << PINcount << std::flush;
            std::cout << std::endl;
            pWrongPIN->show();
        }

        if(PINcount == 3){
            pWrongPIN->close();
            pLocked->show();
            this->close();
        }
    }
}

void kirjaudu::closeKirjaudu()
{
    this->close();
}

