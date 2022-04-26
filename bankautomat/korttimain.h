#ifndef KORTTIMAIN_H
#define KORTTIMAIN_H


#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class KorttiMain;
}

class KorttiMain : public QDialog
{
    Q_OBJECT

public:

    explicit KorttiMain(QString kortNumero, QString kortPIN, QByteArray token, QWidget *parent = nullptr);
    ~KorttiMain();

private slots:
    void dataSlot(QNetworkReply *reply);

private:
    Ui::KorttiMain *ui;

    MyUrl *pMyUrl;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString numero;
    QString PIN;
    QByteArray webtoken;

};

#endif // KORTTIMAIN_H
