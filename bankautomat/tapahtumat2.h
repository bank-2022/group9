#ifndef TAPAHTUMAT2_H
#define TAPAHTUMAT2_H

#include <QDialog>

namespace Ui {
class Tapahtumat2;
}

class Tapahtumat2 : public QDialog
{
    Q_OBJECT

public:
    explicit Tapahtumat2(QWidget *parent = nullptr);
    ~Tapahtumat2();

private:
    Ui::Tapahtumat2 *ui;
};

#endif // TAPAHTUMAT2_H
