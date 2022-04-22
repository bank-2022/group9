#ifndef ASIAKASMAIN_H
#define ASIAKASMAIN_H

#include "korttimain.h"
#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class AsiakasMain;
}

class AsiakasMain : public QDialog
{
    Q_OBJECT

public:
    explicit AsiakasMain(int asTunnus, QString asNimi, QString asLahiOsoite, int asPuh, QByteArray token, QWidget *parent = nullptr);
    ~AsiakasMain();

private slots:
    void dataSlot(QNetworkReply *reply);

private:
    Ui::AsiakasMain *ui;

    MyUrl *pMyUrl;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;

    int tunnus;
    QString nimi;
    QString lahiOsoite;
    int puhelin;
    QByteArray webtoken;
};

#endif // ASIAKASMAIN_H
