#include "korttimain.h"
#include "ui_korttimain.h"

KorttiMain::KorttiMain(QString kortPIN, QByteArray token, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KorttiMain)
{
    ui->setupUi(this);

    //ui->labelSavedNumero->setText(token);
    //ui->labelSavedPIN->setText(kortPIN);
}

KorttiMain::~KorttiMain()
{
    delete ui;
}
