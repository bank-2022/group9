#include "tapahtumat2.h"
#include "ui_tapahtumat2.h"

Tapahtumat2::Tapahtumat2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tapahtumat2)
{
    ui->setupUi(this);
}

Tapahtumat2::~Tapahtumat2()
{
    delete ui;
}
