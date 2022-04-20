#include "login.h"
#include "ui_login.h"

#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    pMyUrl = new MyUrl;
    base_url = pMyUrl->getBase_url();
}

Login::~Login()
{
    delete ui;
    ui=nullptr;

    delete pKorttiMain;
    pKorttiMain = nullptr;
}

void Login::on_btnContinue_clicked()
{
    //qDebug() << "base_url = " + base_url;

    Kortinnumero = ui->lineNumero->text();
    PINkoodi = ui->linePIN->text();

    QJsonObject jsonObj; //luodaan JSON objekti ja lisätään data
    jsonObj.insert("kortinnumero", Kortinnumero);
    jsonObj.insert("PINkoodi", PINkoodi);

    QNetworkRequest request((base_url + "/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void Login::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << response_data;
    token = "Bearer " + response_data;

    pKorttiMain = new KorttiMain(Kortinnumero, PINkoodi, token);
    pKorttiMain->show();
}

