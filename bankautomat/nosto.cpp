#include "mysingleton.h"
#include "nosto.h"
#include "ui_nosto.h"

#include <qtimer.h>

Nosto::Nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nosto)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(showData()));
    timer->start(1);
}

Nosto::~Nosto()
{
    delete ui;
}

void Nosto::showData()
{
    MySingleton *pMySingleton = MySingleton::getInstance();

    ui->labelTunnus->setText(pMySingleton->getTunnus());
    ui->labelNimi->setText(pMySingleton->getNimi());
    ui->labelOsoite->setText(pMySingleton->getLahiOsoite());
    ui->labelPuhelin->setText(pMySingleton->getPuhelin());
    ui->labelSaldo->setText(pMySingleton->getSaldo());
}

void Nosto::on_btn20_clicked()
{

}


void Nosto::on_btn40_clicked()
{

}


void Nosto::on_btn60_clicked()
{

}


void Nosto::on_btn100_clicked()
{

}


void Nosto::on_btn200_clicked()
{

}


void Nosto::on_btn500_clicked()
{

}


void Nosto::on_btnSulje_clicked()
{
    this->close();
}

