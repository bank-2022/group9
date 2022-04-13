#include "wrongpin.h"
#include "ui_wrongpin.h"

WrongPIN::WrongPIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WrongPIN)
{
    ui->setupUi(this);
}

WrongPIN::~WrongPIN()
{
    delete ui;
}
