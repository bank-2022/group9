#ifndef TAPAHTUMAT_H
#define TAPAHTUMAT_H

#include <QDialog>

namespace Ui {
class Tapahtumat;
}

class Tapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tapahtumat(QWidget *parent = nullptr);
    ~Tapahtumat();

public slots:
    void showData();
    void closeThis();

private slots:
    void on_btnSulje_clicked();

private:
    Ui::Tapahtumat *ui;

    QTimer *timer;
};

#endif // TAPAHTUMAT_H
