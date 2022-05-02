#include "mysingleton.h"

MySingleton* MySingleton::instance = nullptr;



const QString &MySingleton::getNimi() const
{
    return nimi;
}

void MySingleton::setNimi(const QString &newNimi)
{
    nimi = newNimi;
}

const QString &MySingleton::getLahiOsoite() const
{
    return lahiOsoite;
}

void MySingleton::setLahiOsoite(const QString &newLahiOsoite)
{
    lahiOsoite = newLahiOsoite;
}



const QByteArray &MySingleton::getWebtoken() const
{
    return webtoken;
}

void MySingleton::setWebtoken(const QByteArray &newWebtoken)
{
    webtoken = newWebtoken;
}

const QString &MySingleton::getTilinumero() const
{
    return tilinumero;
}

void MySingleton::setTilinumero(const QString &newTilinumero)
{
    tilinumero = newTilinumero;
}



const QString &MySingleton::getNumero() const
{
    return numero;
}

void MySingleton::setNumero(const QString &newNumero)
{
    numero = newNumero;
}

const QString &MySingleton::getPIN() const
{
    return PIN;
}

void MySingleton::setPIN(const QString &newPIN)
{
    PIN = newPIN;
}

const QString &MySingleton::getTilinumero2() const
{
    return tilinumero2;
}

void MySingleton::setTilinumero2(const QString &newTilinumero2)
{
    tilinumero2 = newTilinumero2;
}

const QString &MySingleton::getKortinnumero2() const
{
    return kortinnumero2;
}

void MySingleton::setKortinnumero2(const QString &newKortinnumero2)
{
    kortinnumero2 = newKortinnumero2;
}

const QString &MySingleton::getPJK() const
{
    return PJK;
}

void MySingleton::setPJK(const QString &newPJK)
{
    PJK = newPJK;
}

const QString &MySingleton::getTapahtuma() const
{
    return tapahtuma;
}

void MySingleton::setTapahtuma(const QString &newTapahtuma)
{
    tapahtuma = newTapahtuma;
}



const QString &MySingleton::getTunnus() const
{
    return tunnus;
}

void MySingleton::setTunnus(const QString &newTunnus)
{
    tunnus = newTunnus;
}

const QString &MySingleton::getSaldo() const
{
    return saldo;
}

void MySingleton::setSaldo(const QString &newSaldo)
{
    saldo = newSaldo;
}

const QString &MySingleton::getPuhelin() const
{
    return puhelin;
}

void MySingleton::setPuhelin(const QString &newPuhelin)
{
    puhelin = newPuhelin;
}

const QString &MySingleton::getSumma() const
{
    return summa;
}

void MySingleton::setSumma(const QString &newSumma)
{
    summa = newSumma;
}

MySingleton* MySingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MySingleton();
    }

    return instance;
}
