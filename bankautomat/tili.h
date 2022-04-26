#ifndef TILI_H
#define TILI_H

#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Tili;
}

class Tili : public QDialog
{
    Q_OBJECT

public:
    explicit Tili(QString tiTilinumero, float tiSaldo, QByteArray token, QWidget *parent = nullptr);
    ~Tili();

private slots:
    void dataSlot(QNetworkReply *reply);

private:
    Ui::Tili *ui;

    MyUrl *pMyUrl;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString tilinumero;
    float saldo;
    QByteArray webtoken;
};

#endif // TILI_H
