#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

TiliTapahtumat::TiliTapahtumat(QString tiTilinumero, QString tiKortinnumero, QString tiPJK, QString tiTapahtuma, float tiSumma, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TiliTapahtumat)
{
    ui->setupUi(this);

    pMyUrl = new MyUrl;

    tilinumero = tiTilinumero;
    kortinnumero = tiKortinnumero;
    PJK = tiPJK;
    tapahtuma = tiTapahtuma;
    summa = tiSumma;
    webtoken = token;

    QString site_url=pMyUrl->getBase_url() + "/tilitapahtumat/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    dataManager = new QNetworkAccessManager(this);
    connect(dataManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(dataSlot(QNetworkReply*)));
    reply = dataManager->get(request);
}

TiliTapahtumat::~TiliTapahtumat()
{
    delete ui;
}

void TiliTapahtumat::dataSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();

        //tietokannan muuttujat
        QString tilinumero;
        QString kortinnumero;
        QString PJK;
        QString tapahtuma;
        QString summa;

        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();

            tilinumero=QString(json_obj["tilinumero"].toString());
            kortinnumero=QString(json_obj["kortinnumero"].toString());
            PJK=QString(json_obj["päivämäärä_ja_kellonaika"].toString());
            tapahtuma=QString(json_obj["tapahtuma"].toString());
            summa=QString::number(json_obj["summa"].toDouble());
        }

        qDebug() << "Tilinumero:" <<tilinumero;
        qDebug()<< "Kortin numero:" << kortinnumero;
        qDebug() << "Päivämäärä ja kellonaika:" <<PJK;
        qDebug()<< "tapahtuma:" << tapahtuma;
        qDebug()<< "Summa:" << summa;

        reply->deleteLater();
        dataManager->deleteLater();
}
