#include "mainwindow.h"

#include <QtSql>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString serverName = "LOCALHOST\\SQLEXPRESS";
    QString dbName = "test";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setConnectOptions();

    QString dsn = QString("DRIVER={SQL Native Client};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);

    db.setDatabaseName(dsn);

    if(db.open()){
        qDebug() << "Opened";
        db.close();
    }
    else{
        qDebug() << "Error =" << db.lastError().text();
    }

    return a.exec();
}
