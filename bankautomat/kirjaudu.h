#ifndef KIRJAUDU_H
#define KIRJAUDU_H

#include <QDialog>
#include <string>
#include "paavalikko.h"
#include "wrongpin.h"
#include "locked.h"

using namespace std;
#include "paavalikko.h"

namespace Ui {
class kirjaudu;
}

class kirjaudu : public QDialog
{
    Q_OBJECT

public:
    explicit kirjaudu(QWidget *parent = nullptr);
    ~kirjaudu();

private slots:
    void on_pushButton_clicked();

public slots:
    void closeKirjaudu();

private:
    Ui::kirjaudu *ui;
    QTimer * pQTimer;
    paavalikko * pPaavalikko;
    WrongPIN * pWrongPIN;
    Locked * pLocked;

    string password = "1234";
    int PINcount = 0;
};

#endif // KIRJAUDU_H
