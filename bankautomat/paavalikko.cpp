#include "mysingleton.h"
#include "paavalikko.h"
#include "ui_paavalikko.h"

#include <QDebug>

paavalikko::paavalikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paavalikko)
{
    ui->setupUi(this);
    pNosto = new Nosto;
    pSaldo = new Saldo;
    pSalasana = new Salasana;
    pTapahtumat = new Tapahtumat;


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

void paavalikko::on_btnSaldo_clicked()
{
    pSaldo->show();

    //MySingleton *pMySingleton = MySingleton::getInstance();
    //ui->labelTilinumero->setText(pMySingleton->getTilinumero());
}

void paavalikko::on_btnNosto_clicked()
{
    pNosto->show();
}

void paavalikko::on_btnKirjauduUlos_clicked()
{

}

void paavalikko::on_btnVaihdaSalasana_clicked()
{
    pSalasana->show();
}


void paavalikko::on_btnSelaaTapahtumia_clicked()
{
    pTapahtumat->show();
}

