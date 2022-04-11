#include "mainui.h"
#include "ui_mainui.h"

Mainui::Mainui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mainui)
{
    ui->setupUi(this);
}

Mainui::~Mainui()
{
    delete ui;
}

void Mainui::on_btnCredits_clicked()
{

}


void Mainui::on_btnTransactions_clicked()
{

}


void Mainui::on_btnNostarahaa_clicked()
{

}


void Mainui::on_btnLogout_clicked()
{

}


void Mainui::on_btnChangepass_clicked()
{

}

