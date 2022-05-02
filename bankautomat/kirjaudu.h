#ifndef KIRJAUDU_H
#define KIRJAUDU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "paavalikko.h"
#include "wrongpin.h"
#include "locked.h"
#include "myurl.h"
#include "asiakas.h"
#include "tili.h"
#include "tilitapahtumat.h"

using namespace std;

namespace Ui {
class kirjaudu;
}

class kirjaudu : public QDialog
{
    Q_OBJECT

public:
    explicit kirjaudu(QWidget *parent = nullptr);
    ~kirjaudu();

    int PINcount = 0;
    Locked * pLocked;

private slots:
    void on_pushButton_clicked();
    void loginSlot(QNetworkReply *reply);

public slots:
    void closeKirjaudu();

private:
    Ui::kirjaudu *ui;
    QTimer * pQTimer;
    paavalikko * pPaavalikko;
    WrongPIN * pWrongPIN;

    KorttiMain *pKorttiMain;
    QString Kortinnumero;
    QString PINkoodi;

    Tili *pTili;
    QString Tilinumero;
    float Saldo;

    Asiakas *pAsiakas;
    int Tunnus;
    QString Nimi;
    QString LahiOsoite;
    int Puhelin;

    TiliTapahtumat *pTiliTapahtumat;
    QString Tilinumero2;
    QString Kortinnumero2;
    QString PJK;
    QString Tapahtuma;
    float Summa;

    MyUrl *pMyUrl;
    QString base_url;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
};

#endif // KIRJAUDU_H
