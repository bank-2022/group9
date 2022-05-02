#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "paavalikko.h"
#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Asiakas;
}

class Asiakas : public QDialog
{
    Q_OBJECT

public:
    explicit Asiakas(int asTunnus, QString asNimi, QString asLahiosoite, int asPuhelin, QByteArray token, QWidget *parent = nullptr);
    ~Asiakas();

private slots:
    void dataSlot(QNetworkReply *reply);

private:
    Ui::Asiakas *ui;

    MyUrl *pMyUrl;

    paavalikko *pPaavalikko;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;

    int tunnus;
    QString nimi;
    QString lahiOsoite;
    int puhelin;
    QByteArray webtoken;
};

#endif // ASIAKAS_H
