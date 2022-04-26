#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kirjaudu.h"
#include "login.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

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

    void serialRecieved();
    void on_btnLogin_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    kirjaudu * pKirjaudu;
    QTimer * timer;

    Login * pLogin;
    QSerialPort *serial;
    //QString ba2;
};
#endif // MAINWINDOW_H
