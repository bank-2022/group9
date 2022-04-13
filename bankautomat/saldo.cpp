#include "saldo.h"
#include "ui_saldo.h"

Saldo::Saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saldo)
{
    ui->setupUi(this);

    QString s = QString::number(saldo, 'saldo', 2);

    ui->saldoLabel->setText(s);
}

Saldo::~Saldo()
{
    delete ui;
}
