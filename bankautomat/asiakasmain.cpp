#include "asiakasmain.h"
#include "ui_asiakasmain.h"

AsiakasMain::AsiakasMain(int asTunnus, QString asNimi, QString asLahiOsoite, int asPuh, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AsiakasMain)
{
    ui->setupUi(this);

    tunnus = asTunnus;
    nimi = asNimi;
    lahiOsoite = asLahiOsoite;
    puhelin = asPuh;
    webtoken = token;

    QString site_url=pMyUrl->getBase_url() + "/asiakas/";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webtoken));
    //WEBTOKEN LOPPU

    dataManager = new QNetworkAccessManager(this);
    connect(dataManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(dataSlot(QNetworkReply*)));
    reply = dataManager->get(request);
}

AsiakasMain::~AsiakasMain()
{
    delete ui;
}

void AsiakasMain::dataSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();

        //tietokannan muuttujat
        QString nimi;

        foreach (const QJsonValue &value, json_array) {
            QJsonObject json_obj = value.toObject();
            nimi+=QString(json_obj["nimi"].toString());
        }

        qDebug()<<nimi;
}
