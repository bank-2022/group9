#include "mysingleton.h"
#include "tapahtumat.h"
#include "ui_tapahtumat.h"

#include <QTimer>

Tapahtumat::Tapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tapahtumat)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(showData()));
    timer->start(1);
}

Tapahtumat::~Tapahtumat()
{
    delete ui;

    ui=nullptr;
}

void Tapahtumat::showData()
{
    MySingleton *pMySingleton = MySingleton::getInstance();

    ui->labelTunnus->setText(pMySingleton->getTunnus());
    ui->labelNimi->setText(pMySingleton->getNimi());
    ui->labelOsoite->setText(pMySingleton->getLahiOsoite());
    ui->labelPuhelin->setText(pMySingleton->getPuhelin());
    ui->labelSaldo->setText(pMySingleton->getSaldo());
}

void Tapahtumat::closeThis()
{
    this->close();
}


void Tapahtumat::on_btnSulje_clicked()
{
    this->close();
}

