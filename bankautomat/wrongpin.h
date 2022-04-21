#ifndef WRONGPIN_H
#define WRONGPIN_H

#include <QDialog>

namespace Ui {
class WrongPIN;
}

class WrongPIN : public QDialog
{
    Q_OBJECT

public:
    explicit WrongPIN(QWidget *parent = nullptr);
    ~WrongPIN();

    QString PIN = "pinkoodi";

private:
    Ui::WrongPIN *ui;
};

#endif // WRONGPIN_H
