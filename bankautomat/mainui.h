#ifndef MAINUI_H
#define MAINUI_H

#include <QDialog>

namespace Ui {
class Mainui;
}

class Mainui : public QDialog
{
    Q_OBJECT

public:
    explicit Mainui(QWidget *parent = nullptr);
    ~Mainui();

private slots:
    void on_btnCredits_clicked();

    void on_btnTransactions_clicked();

    void on_btnNostarahaa_clicked();

    void on_btnLogout_clicked();

    void on_btnChangepass_clicked();

private:
    Ui::Mainui *ui;
};

#endif // MAINUI_H
