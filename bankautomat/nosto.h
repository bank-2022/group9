#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>

namespace Ui {
class Nosto;
}

class Nosto : public QDialog
{
    Q_OBJECT

public:
    explicit Nosto(QWidget *parent = nullptr);
    ~Nosto();

public slots:
    void showData();

private slots:
    void on_btn20_clicked();

    void on_btn40_clicked();

    void on_btn60_clicked();

    void on_btn100_clicked();

    void on_btn200_clicked();

    void on_btn500_clicked();

    void on_btnSulje_clicked();

private:
    Ui::Nosto *ui;

    QTimer *timer;
};

#endif // NOSTO_H
