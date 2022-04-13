#include "locked.h"
#include "ui_locked.h"

Locked::Locked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Locked)
{
    ui->setupUi(this);
}

Locked::~Locked()
{
    delete ui;
}
