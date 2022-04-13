#include "tapahtumat.h"
#include "ui_tapahtumat.h"

Tapahtumat::Tapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tapahtumat)
{
    ui->setupUi(this);
}

Tapahtumat::~Tapahtumat()
{
    delete ui;
}

void Tapahtumat::on_btnSulje_clicked()
{
    this->close();
}

