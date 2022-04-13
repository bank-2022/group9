#ifndef PAAVALIKKO_H
#define PAAVALIKKO_H

#include <QDialog>
#include "nosto.h"
#include "saldo.h"
#include "tapahtumat.h"
#include "salasana.h"

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
    Nosto *pNosto;
    Saldo *pSaldo;
    Tapahtumat *pTapahtumat;
    Salasana *pSalasana;
};

#endif // PAAVALIKKO_H
