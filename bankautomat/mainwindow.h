#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kirjaudu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void closeKirjaudu();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
    kirjaudu * pKirjaudu;
    QTimer * timer;
};
#endif // MAINWINDOW_H
