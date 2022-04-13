#ifndef SALASANA_H
#define SALASANA_H

#include <QDialog>

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
    void on_btnSulje_clicked();

private:
    Ui::Salasana *ui;
};

#endif // SALASANA_H
