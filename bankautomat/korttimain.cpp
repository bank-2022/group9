#include "korttimain.h"
#include "ui_korttimain.h"

#include <QDebug>

KorttiMain::KorttiMain(QString kortNumero, QString kortPIN, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KorttiMain)
{
    ui->setupUi(this);

    pMyUrl = new MyUrl;

    PIN = kortPIN;
    numero = kortNumero;
    webtoken = token;
}

KorttiMain::~KorttiMain()
{
    delete ui;
}

void KorttiMain::on_btnKorttiData_clicked()
{
    QString site_url=pMyUrl->getBase_url() + "/kortti/" + numero;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    dataManager = new QNetworkAccessManager(this);
    connect(dataManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(dataSlot(QNetworkReply*)));
    reply = dataManager->get(request);

    ui->textEdit->setText(response_data);
}

void KorttiMain::dataSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << response_data;
}
