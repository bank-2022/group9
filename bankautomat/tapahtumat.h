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

private:
    Ui::Tapahtumat *ui;
};

#endif // TAPAHTUMAT_H
