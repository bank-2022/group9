#ifndef LOCKED_H
#define LOCKED_H

#include <QDialog>

namespace Ui {
class Locked;
}

class Locked : public QDialog
{
    Q_OBJECT

public:
    explicit Locked(QWidget *parent = nullptr);
    ~Locked();

private:
    Ui::Locked *ui;
};

#endif // LOCKED_H
