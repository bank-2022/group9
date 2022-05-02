#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <qstring.h>

class MySingleton
{
private:
    static MySingleton* instance;

    QByteArray webtoken;

    //kortti
    QString numero;
    QString PIN;

    // asiakas
    int tunnus;
    QString nimi;
    QString lahiOsoite;
    int puhelin;

    // tili
    QString tilinumero;
    float saldo;

    // tilitapahtumat
    QString tilinumero2;
    QString kortinnumero2;
    QString PJK;
    QString tapahtuma;
    float summa;

public:
    static MySingleton* getInstance();
    int getTunnus() const;
    void setTunnus(int newTunnus);
    const QString &getNimi() const;
    void setNimi(const QString &newNimi);
    const QString &getLahiOsoite() const;
    void setLahiOsoite(const QString &newLahiOsoite);
    int getPuhelin() const;
    void setPuhelin(int newPuhelin);
    const QByteArray &getWebtoken() const;
    void setWebtoken(const QByteArray &newWebtoken);
    const QString &getTilinumero() const;
    void setTilinumero(const QString &newTilinumero);
    float getSaldo() const;
    void setSaldo(float newSaldo);
    const QString &getNumero() const;
    void setNumero(const QString &newNumero);
    const QString &getPIN() const;
    void setPIN(const QString &newPIN);
    const QString &getTilinumero2() const;
    void setTilinumero2(const QString &newTilinumero2);
    const QString &getKortinnumero2() const;
    void setKortinnumero2(const QString &newKortinnumero2);
    const QString &getPJK() const;
    void setPJK(const QString &newPJK);
    const QString &getTapahtuma() const;
    void setTapahtuma(const QString &newTapahtuma);
    float getSumma() const;
    void setSumma(float newSumma);
};

#endif // MYSINGLETON_H
