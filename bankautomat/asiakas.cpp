#include "asiakas.h"
#include "ui_asiakas.h"

#include <QDebug>

Asiakas::Asiakas(int asTunnus, QString asNimi, QString asLahiosoite, int asPuhelin, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Asiakas)
{
    ui->setupUi(this);

    pMyUrl = new MyUrl;

    tunnus = asTunnus;
    nimi = asNimi;
    lahiOsoite = asLahiosoite;
    puhelin = asPuhelin;
    webtoken = token;

    QString site_url=pMyUrl->getBase_url() + "/asiakas/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    dataManager = new QNetworkAccessManager(this);
    connect(dataManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(dataSlot(QNetworkReply*)));
    reply = dataManager->get(request);
}

Asiakas::~Asiakas()
{
    delete ui;
}

void Asiakas::dataSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();

        //tietokannan muuttujat
        QString tunnus;
        QString nimi;
        QString lahiOsoite;
        QString puhelin;

        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            tunnus=QString::number(json_obj["tunnus"].toInt());
            nimi=QString(json_obj["nimi"].toString());
            lahiOsoite=QString(json_obj["lähiosoite"].toString());
            puhelin=QString::number(json_obj["puhelinnumero"].toInt());
        }

        qDebug() << "Tunnus:" <<tunnus;
        qDebug()<< "Nimi:" << nimi;
        qDebug() << "Osoite:" <<lahiOsoite;
        qDebug()<< "Puhelinnumero:" << puhelin;

        reply->deleteLater();
        dataManager->deleteLater();
}
