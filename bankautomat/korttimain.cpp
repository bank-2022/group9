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

    QString site_url=pMyUrl->getBase_url() + "/kortti/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    dataManager = new QNetworkAccessManager(this);
    connect(dataManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(dataSlot(QNetworkReply*)));
    reply = dataManager->get(request);

}

KorttiMain::~KorttiMain()
{
    delete ui;
}


void KorttiMain::dataSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();

        //tietokannan muuttujat
        QString kortinnumero;
        QString PINkoodi;

        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();

            kortinnumero=QString(json_obj["kortinnumero"].toString());
            PINkoodi=QString(json_obj["PINkoodi"].toString());
        }

        qDebug()<< "Kortin numero:" <<kortinnumero;
        qDebug()<< "PIN:" << PINkoodi;

        reply->deleteLater();
        dataManager->deleteLater();

}

