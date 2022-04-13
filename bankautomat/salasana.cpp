#include "salasana.h"
#include "ui_salasana.h"

Salasana::Salasana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salasana)
{
    ui->setupUi(this);
}

Salasana::~Salasana()
{
    delete ui;
}

void Salasana::on_btnSulje_clicked()
{
    this->close();
}

