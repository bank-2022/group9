#ifndef LOGIN_H
#define LOGIN_H

#include "korttimain.h"
#include "myurl.h"

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnContinue_clicked();
    void loginSlot(QNetworkReply *reply);

private:
    Ui::Login *ui;
    QString Kortinnumero;
    QString PINkoodi;

    KorttiMain *pKorttiMain;
    MyUrl *pMyUrl;
    QString base_url;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QByteArray token;
};

#endif // LOGIN_H
