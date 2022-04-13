#ifndef VAHVISTUS_H
#define VAHVISTUS_H

#include <QDialog>

namespace Ui {
class vahvistus;
}

class vahvistus : public QDialog
{
    Q_OBJECT

public:
    explicit vahvistus(QWidget *parent = nullptr);
    ~vahvistus();

private slots:
    void on_btnKylla_clicked();

    void on_btnEi_clicked();

private:
    Ui::vahvistus *ui;
};

#endif // VAHVISTUS_H
