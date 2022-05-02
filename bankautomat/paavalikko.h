#ifndef PAAVALIKKO_H
#define PAAVALIKKO_H

#include <QDialog>

#include "nosto.h"
#include "saldo.h"
#include "salasana.h"
#include "korttimain.h"
#include "tapahtumat.h"

namespace Ui {
class paavalikko;
}

class paavalikko : public QDialog
{
    Q_OBJECT

public:
    explicit paavalikko(QWidget *parent = nullptr);
    ~paavalikko();

public slots:
    void closeSaldo();

private slots:
    void on_btnSaldo_clicked();

    void on_btnNosto_clicked();

    void on_btnKirjauduUlos_clicked();

    void on_btnVaihdaSalasana_clicked();

    void on_btnSelaaTapahtumia_clicked();

private:
    Ui::paavalikko *ui;
    Nosto *pNosto;
    Saldo *pSaldo;
    Tapahtumat *pTapahtumat;
    Salasana *pSalasana;
    QTimer *timer;
};

#endif // PAAVALIKKO_H
