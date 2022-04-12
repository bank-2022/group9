#include "paavalikko.h"
#include "ui_paavalikko.h"

paavalikko::paavalikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paavalikko)
{
    ui->setupUi(this);
}

paavalikko::~paavalikko()
{
    delete ui;
}

void paavalikko::on_btnSaldo_clicked()
{

}


void paavalikko::on_btnTapahtumat_clicked()
{

}


void paavalikko::on_btnNosto_clicked()
{

}


void paavalikko::on_btnKirjauduUlos_clicked()
{

}


void paavalikko::on_btnVaihdaSalasana_clicked()
{

}

