#ifndef SALASANA_H
#define SALASANA_H

#include <QDialog>

#include "salasanavaihdettu.h"
#include "wrongpin.h"

namespace Ui {
class Salasana;
}

class Salasana : public QDialog
{
    Q_OBJECT

public:
    explicit Salasana(QWidget *parent = nullptr);
    ~Salasana();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Salasana *ui;
    SalasanaVaihdettu * pVaihdettu;

    WrongPIN * pWrongPIN;
};

#endif // SALASANA_H
