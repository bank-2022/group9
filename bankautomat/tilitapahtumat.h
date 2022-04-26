#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class TiliTapahtumat;
}

class TiliTapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit TiliTapahtumat(QString tiTilinumero, QString tiKortinnumero, QString tiPJK, QString tiTapahtuma, float tiSumma, QByteArray token, QWidget *parent = nullptr);
    ~TiliTapahtumat();

private slots:
    void dataSlot(QNetworkReply *reply);

private:
    Ui::TiliTapahtumat *ui;

    MyUrl *pMyUrl;

    QNetworkAccessManager *dataManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QString tilinumero;
    QString kortinnumero;
    QString PJK;
    QString tapahtuma;
    float summa;
    QByteArray webtoken;
};

#endif // TILITAPAHTUMAT_H
