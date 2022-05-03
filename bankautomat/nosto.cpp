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

    pMyUrl = new MyUrl;
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
    MySingleton *pMySingleton = MySingleton::getInstance();

    QString tilinumero = pMySingleton->getTilinumero();

    QJsonObject jsonObj;
    jsonObj.insert("saldo", 20.1f);
    jsonObj.insert("tilinumero", tilinumero);

    QString site_url=pMyUrl->getBase_url()="http://ipv4.fiddler:3000/tili/10/";
    QNetworkRequest request((site_url));

    //BASIC AUTENTIKOINTI ALKU
    QString credentials="admin:1234";
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", pMySingleton->getWebtoken() );
    //BASIC AUTENTIKOINTI LOPPU

    putManager = new QNetworkAccessManager(this);
    connect(putManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(updateSaldo(QNetworkReply*)));

    reply = putManager->put(request, QJsonDocument(jsonObj).toJson());
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

void Nosto::updateSaldo(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    putManager->deleteLater();
}

