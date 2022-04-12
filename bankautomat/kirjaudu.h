#ifndef KIRJAUDU_H
#define KIRJAUDU_H

#include <QDialog>

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
};

#endif // KIRJAUDU_H
