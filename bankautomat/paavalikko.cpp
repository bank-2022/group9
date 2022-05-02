#include "mysingleton.h"
#include "paavalikko.h"
#include "ui_paavalikko.h"

#include <QDebug>
#include <qmessagebox.h>

paavalikko::paavalikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paavalikko)
{
    ui->setupUi(this);
    pNosto = new Nosto;
    pSaldo = new Saldo;
    pSalasana = new Salasana;
    pTapahtumat = new Tapahtumat;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showData()));
    timer->start(1);
}

paavalikko::~paavalikko()
{
    delete ui;
    delete pNosto;
    delete pSaldo;
    delete pTapahtumat;
    delete pSalasana;

    pNosto = nullptr;
    pSaldo = nullptr;
    pTapahtumat = nullptr;
    pSalasana = nullptr;
}

void paavalikko::showData()
{
    MySingleton *pMySingleton = MySingleton::getInstance();

    ui->labelAsiakas->setText(pMySingleton->getNimi());
}

void paavalikko::closeTapahtumat()
{
    pTapahtumat->close();
}

void paavalikko::closeNosto()
{
    pNosto->close();
}

void paavalikko::closeSalasana()
{
    pSalasana->close();
}

void paavalikko::on_btnSaldo_clicked()
{
    pSaldo->show();
}

void paavalikko::on_btnNosto_clicked()
{
    pNosto->show();
    connect(timer, SIGNAL(timeout()), this, SLOT(closeNosto()));
    timer->start(10000);
}

void paavalikko::on_btnKirjauduUlos_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,
                                            "Kirjaudu ulos", "Kirjaudutaanko ulos?",
                                            QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes) {
            paavalikko::close();
        }
}

void paavalikko::on_btnVaihdaSalasana_clicked()
{
    pSalasana->show();
    connect(timer, SIGNAL(timeout()), this, SLOT(closeSalasana()));
    timer->start(10000);
}

void paavalikko::on_btnSelaaTapahtumia_clicked()
{
    pTapahtumat->show();
    connect(timer, SIGNAL(timeout()), this, SLOT(closeTapahtumat()));
    timer->start(30000);
}

