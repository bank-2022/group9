#include "mysingleton.h"
#include "saldo.h"
#include "ui_saldo.h"
#include <QTimer>

Saldo::Saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saldo)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(showData()));
        timer->start(100);


    QString s = QString::number(saldo, 'saldo', 2);

    ui->saldoLabel->setText(s + " €");
}

Saldo::~Saldo()
{
    delete ui;
}

void Saldo::showData()
{
    MySingleton *pMySingleton = MySingleton::getInstance();

    ui->label_Tunnus->setText(pMySingleton->getTunnus());
    ui->label_Nimi->setText(pMySingleton->getNimi());
    ui->label_Osoite->setText(pMySingleton->getLahiOsoite());
    ui->saldoLabel->setText(pMySingleton->getSaldo());
}









void Saldo::on_CloseSaldo_clicked()
{
    this->close();
}

