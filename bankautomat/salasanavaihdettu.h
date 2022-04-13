#ifndef SALASANAVAIHDETTU_H
#define SALASANAVAIHDETTU_H

#include <QDialog>

namespace Ui {
class SalasanaVaihdettu;
}

class SalasanaVaihdettu : public QDialog
{
    Q_OBJECT

public:
    explicit SalasanaVaihdettu(QWidget *parent = nullptr);
    ~SalasanaVaihdettu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SalasanaVaihdettu *ui;
};

#endif // SALASANAVAIHDETTU_H
