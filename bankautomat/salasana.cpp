#include "salasana.h"
#include "ui_salasana.h"
#include <QDebug>

Salasana::Salasana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salasana)
{
    ui->setupUi(this);

    pVaihdettu = new SalasanaVaihdettu;


    pWrongPIN = new WrongPIN;


    ui->label1->setText("");
    ui->label2->setText("");
    ui->label3->setText("");

    ui->label1->setStyleSheet("QLabel {color : red; }");
    ui->label2->setStyleSheet("QLabel {color : red; }");
    ui->label3->setStyleSheet("QLabel {color : red; }");
}

Salasana::~Salasana()
{
    delete ui;
}

void Salasana::on_pushButton_2_clicked()
{
    this->close();
}

void Salasana::on_pushButton_clicked()
{
    bool cooldown = false;


    qDebug() << "Nykyinen salasana: " << pWrongPIN->PIN;


    QString vanhaSalis = ui->lineVanha->text();
    QString uusi1 = ui->lineUusi1->text();
    QString uusi2 = ui->lineUusi2->text();


    if(vanhaSalis == pWrongPIN->PIN && uusi1 == uusi2 && uusi1 != NULL && uusi2 != NULL && vanhaSalis != uusi1 && vanhaSalis != uusi2){
        pWrongPIN->PIN = uusi1;
        qDebug() << "Salasana vaihdettu: " << pWrongPIN->PIN;
        qDebug() << "Nykyinen salasana: " << pWrongPIN->PIN;


        this->close();
        pVaihdettu->show();
    }


    if(vanhaSalis != pWrongPIN->PIN && !cooldown){
        qDebug() << "Vanha salasana vaarin";
        ui->label1->setText("Vanha salasana väärin");

    }
    else{
        ui->label1->setText("");
    }

    if(uusi1 != uusi2){
        qDebug() << "Uusi salasana ei tasmaa";
        ui->label2->setText("Uusi salasana ei täsmää");
        ui->label3->setText("Uusi salasana ei täsmää");
    }
    else{
        ui->label2->setText("");
        ui->label3->setText("");
    }

    if(uusi1 == NULL){
        ui->label2->setText("Kenttä ei voi olla tyhjä");
    }

    if(uusi2 == NULL){
        ui->label3->setText("Kenttä ei voi olla tyhjä");
    }

    if(vanhaSalis == uusi1 && vanhaSalis == uusi2 && uusi1 != NULL && uusi2 != NULL){
        qDebug() << "Uusi salasana ei voi olla entinen salasanasi";
        ui->label1->setText("Uusi salasana ei voi olla entinen salasanasi");
    }
}

