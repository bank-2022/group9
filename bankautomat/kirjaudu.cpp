#include "kirjaudu.h"
#include "mysingleton.h"
#include "ui_kirjaudu.h"

#include <iostream>
#include <qdebug.h>

kirjaudu::kirjaudu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kirjaudu)
{
    ui->setupUi(this);

    this->close();

    pPaavalikko = new paavalikko();
    pWrongPIN = new WrongPIN;
    pLocked = new Locked;

    pMyUrl = new MyUrl;
    base_url = pMyUrl->getBase_url();

    timer = new QTimer(this);
}

kirjaudu::~kirjaudu()
{
    delete ui;
    delete pPaavalikko;
    delete pKorttiMain;


    ui=nullptr;

    pKorttiMain = nullptr;
    pPaavalikko=nullptr;
}

void kirjaudu::on_pushButton_clicked()
{
    QString y = ui->PINKentta->text();

    if("000001" == y && PINcount < 3)
    {
        std::cout << "Hyvaksytty" << std::flush;
        std::cout << std::endl;
        PINcount = 0;
        this->close();
        pPaavalikko->show();
        connect(timer, SIGNAL(timeout()), this, SLOT(closeKirjaudu()));
        timer->start(30000);
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

    //Kortinnumero = ui->NumeroKentta->text();

    QJsonObject jsonObj; //luodaan JSON objekti ja lisätään data
    jsonObj.insert("kortinnumero", "1001");
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
    MySingleton *pMySingleton = MySingleton::getInstance();
    pMySingleton->setWebtoken(token);

    ui->PINKentta->setText("");

    pKorttiMain = new KorttiMain(Kortinnumero, PINkoodi, token);
    //pKorttiMain->show();

    pTili = new Tili(Tilinumero, Saldo, token);

    pAsiakas = new Asiakas(Tunnus, Nimi, LahiOsoite, Puhelin, token);

    pTiliTapahtumat = new TiliTapahtumat(Tilinumero2, Kortinnumero2, PJK, Tapahtuma, Summa, token);
}

void kirjaudu::closeKirjaudu()
{
    pPaavalikko->close();
}
