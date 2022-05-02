#ifndef SALDO_H
#define SALDO_H

#include <QDialog>

namespace Ui {
class Saldo;
}

class Saldo : public QDialog
{
    Q_OBJECT

public:
    explicit Saldo(QWidget *parent = nullptr);
    ~Saldo();

private slots:
    void on_btnSulje_clicked();

private:
    Ui::Saldo *ui;

    float saldo = 2094.42f;
};

#endif // SALDO_H
