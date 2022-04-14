#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kirjaudu.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //hienoo työtä jätkät

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void closeKirjaudu();

private slots:
    void serialRecieved();
    void on_btnLogin_clicked();

private:
    Ui::MainWindow *ui;
    kirjaudu * pKirjaudu;
    QTimer * timer;
    QSerialPort *serial;
};
#endif // MAINWINDOW_H
