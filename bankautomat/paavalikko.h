#ifndef PAAVALIKKO_H
#define PAAVALIKKO_H

#include <QDialog>

namespace Ui {
class paavalikko;
}

class paavalikko : public QDialog
{
    Q_OBJECT

public:
    explicit paavalikko(QWidget *parent = nullptr);
    ~paavalikko();

private slots:
    void on_btnSaldo_clicked();

    void on_btnTapahtumat_clicked();

    void on_btnNosto_clicked();

    void on_btnKirjauduUlos_clicked();

    void on_btnVaihdaSalasana_clicked();

private:
    Ui::paavalikko *ui;
};

#endif // PAAVALIKKO_H
