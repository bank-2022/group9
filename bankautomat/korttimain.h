#ifndef KORTTIMAIN_H
#define KORTTIMAIN_H

#include <QDialog>

namespace Ui {
class KorttiMain;
}

class KorttiMain : public QDialog
{
    Q_OBJECT

public:
    explicit KorttiMain(QString kortPIN, QByteArray token, QWidget *parent = nullptr);
    ~KorttiMain();

private:
    Ui::KorttiMain *ui;
};

#endif // KORTTIMAIN_H
