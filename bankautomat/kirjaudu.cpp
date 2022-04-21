#include "kirjaudu.h"
#include "ui_kirjaudu.h"
#include <iostream>

#include <qdebug.h>

kirjaudu::kirjaudu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kirjaudu)
{
    ui->setupUi(this);

    this->close();

    pPaavalikko = new paavalikko;
    pWrongPIN = new WrongPIN;
    pLocked = new Locked;

    pMyUrl = new MyUrl;
    base_url = pMyUrl->getBase_url();
}

kirjaudu::~kirjaudu()
{
    delete ui;
    delete pPaavalikko;

    delete pKorttiMain;
    pKorttiMain = nullptr;
}

void kirjaudu::on_pushButton_clicked()
{
    QString y = ui->PINKentta->text();


    if(pWrongPIN->PIN == y && PINcount < 3)
    {
        std::cout << "Hyvaksytty" << std::flush;
        std::cout << std::endl;
        PINcount = 0;
        this->close();
        pPaavalikko->show();
    }
    else
    {
        ui->PINKentta->setText("");
        PINcount++;
        std::cout << "Hylatty" << std::flush;
        std::cout << std::endl;
        std::cout << PINcount << std::flush;
        std::cout << std::endl;
        pWrongPIN->show();
    }
    if(PINcount == 3){
        ui->PINKentta->setText("");
        pWrongPIN->close();
        pLocked->show();
        this->close();
    }

    //qDebug() << "base_url = " + base_url;

    //Kortinnumero = ui->lineNumero->text();
    PINkoodi = ui->PINKentta->text();

    QJsonObject jsonObj; //luodaan JSON objekti ja lisätään data
    jsonObj.insert("kortinnumero", "0001");
    jsonObj.insert("PINkoodi", PINkoodi);

    QNetworkRequest request((base_url + "/login"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
}

void kirjaudu::loginSlot(QNetworkReply *reply)
{
    response_data = reply->readAll();
    qDebug() << response_data;
    token = "Bearer " + response_data;

    ui->PINKentta->setText("");
    //pKorttiMain = new KorttiMain(PINkoodi, token);
    //pKorttiMain->show();

}

void kirjaudu::closeKirjaudu()
{
    this->close();
}

