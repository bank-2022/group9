#include "vahvistus.h"
#include "ui_vahvistus.h"

vahvistus::vahvistus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vahvistus)
{
    ui->setupUi(this);
}

vahvistus::~vahvistus()
{
    delete ui;
}

void vahvistus::on_btnKylla_clicked()
{

}


void vahvistus::on_btnEi_clicked()
{
    this->close();
}

