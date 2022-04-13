#include "paavalikko.h"
#include "ui_paavalikko.h"


paavalikko::paavalikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paavalikko)
{
    ui->setupUi(this);
    pNosto = new Nosto;
    pSaldo = new Saldo;
    pTapahtumat = new Tapahtumat;
    pSalasana = new Salasana;
    pVahvistus = new vahvistus;
}

paavalikko::~paavalikko()
{
    delete ui;
    delete pNosto;
    delete pSaldo;
    delete pTapahtumat;
    delete pSalasana;
    delete pVahvistus;
}

void paavalikko::on_btnSaldo_clicked()
{
pSaldo->show();
}


void paavalikko::on_btnTapahtumat_clicked()
{
pTapahtumat->show();
}


void paavalikko::on_btnNosto_clicked()
{
pNosto->show();
}


void paavalikko::on_btnKirjauduUlos_clicked()
{
pVahvistus->show();
}


void paavalikko::on_btnVaihdaSalasana_clicked()
{
pSalasana->show();
}

