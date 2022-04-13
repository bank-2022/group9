QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    kirjaudu.cpp \
    locked.cpp \
    main.cpp \
    mainwindow.cpp \
    nosto.cpp \
    paavalikko.cpp \
    salasana.cpp \
    salasanavaihdettu.cpp \
    saldo.cpp \
    tapahtumat.cpp \
    wrongpin.cpp

HEADERS += \
    kirjaudu.h \
    locked.h \
    mainwindow.h \
    nosto.h \
    paavalikko.h \
    salasana.h \
    salasanavaihdettu.h \
    saldo.h \
    tapahtumat.h \
    wrongpin.h

FORMS += \
    kirjaudu.ui \
    locked.ui \
    mainwindow.ui \
    nosto.ui \
    paavalikko.ui \
    salasana.ui \
    salasanavaihdettu.ui \
    saldo.ui \
    tapahtumat.ui \
    wrongpin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
