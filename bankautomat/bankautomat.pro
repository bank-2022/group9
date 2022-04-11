QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    changepassword.cpp \
    login.cpp \
    main.cpp \
    mainui.cpp \
    mainwindow.cpp \
    nosto.cpp \
    saldo.cpp \
    transactions.cpp

HEADERS += \
    changepassword.h \
    login.h \
    mainui.h \
    mainwindow.h \
    nosto.h \
    saldo.h \
    transactions.h

FORMS += \
    changepassword.ui \
    login.ui \
    mainui.ui \
    mainwindow.ui \
    nosto.ui \
    saldo.ui \
    transactions.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
