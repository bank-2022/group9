#include "salasanavaihdettu.h"
#include "ui_salasanavaihdettu.h"

SalasanaVaihdettu::SalasanaVaihdettu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalasanaVaihdettu)
{
    ui->setupUi(this);
}

SalasanaVaihdettu::~SalasanaVaihdettu()
{
    delete ui;
}

void SalasanaVaihdettu::on_pushButton_clicked()
{
    this->close();
}

