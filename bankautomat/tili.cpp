#include "mysingleton.h"
#include "tili.h"
#include "ui_tili.h"

#include <QDebug>

Tili::Tili(QString tiTilinumero, float tiSaldo, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tili)
{
    ui->setupUi(this);

    pMyUrl = new MyUrl;

    tilinumero = tiTilinumero;
    saldo = tiSaldo;
    webtoken = token;

    QString site_url=pMyUrl->getBase_url() + "/tili/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    dataManager = new QNetworkAccessManager(this);
    connect(dataManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(dataSlot(QNetworkReply*)));
    reply = dataManager->get(request);
}

Tili::~Tili()
{
    delete ui;
}

void Tili::dataSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();

        //tietokannan muuttujat
        QString tilinumero;
        QString saldo;

        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();

            tilinumero=QString(json_obj["tilinumero"].toString());
            saldo=QString::number(json_obj["saldo"].toDouble());
        }

        MySingleton *pMySingleton = MySingleton::getInstance();
        pMySingleton->setTilinumero(tilinumero);

        qDebug() << "Tilinumero:" <<tilinumero;
        qDebug()<< "Saldo:" << saldo;

        reply->deleteLater();
        dataManager->deleteLater();
}
