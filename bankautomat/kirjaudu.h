#ifndef KIRJAUDU_H
#define KIRJAUDU_H

#include <QDialog>
#include <string>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "paavalikko.h"
#include "wrongpin.h"
#include "locked.h"
#include "myurl.h"


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
    MyUrl *pMyUrl;
    QString base_url;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;

};

#endif // KIRJAUDU_H
