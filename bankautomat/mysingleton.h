#ifndef MYSINGLETON_H
#define MYSINGLETON_H

#include <qstring.h>

class MySingleton
{
private:
    static MySingleton* instance;

    QByteArray webtoken;

    // kortti
    QString numero;
    QString PIN;

    // asiakas
    QString tunnus;
    QString nimi;
    QString lahiOsoite;
    QString puhelin;

    // tili
    QString tilinumero;
    QString saldo;

    // tilitapahtumat
    QString tilinumero2;
    QString kortinnumero2;
    QString PJK;
    QString tapahtuma;
    QString summa;

public:
    static MySingleton* getInstance();
    const QString &getNimi() const;
    void setNimi(const QString &newNimi);
    const QString &getLahiOsoite() const;
    void setLahiOsoite(const QString &newLahiOsoite);
    const QByteArray &getWebtoken() const;
    void setWebtoken(const QByteArray &newWebtoken);
    const QString &getTilinumero() const;
    void setTilinumero(const QString &newTilinumero);
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
    const QString &getTunnus() const;
    void setTunnus(const QString &newTunnus);
    const QString &getPuhelin() const;
    void setPuhelin(const QString &newPuhelin);
    const QString &getSumma() const;
    void setSumma(const QString &newSumma);
    const QString &getSaldo() const;
    void setSaldo(const QString &newSaldo);
};

#endif // MYSINGLETON_H
