TEMPLATE = app
TARGET = software

QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    mainwindow.cpp

HEADERS += \
    window.h \
    mainwindow.h

DISTFILES += \
    eaglesLogo.png

RESOURCES += \
    logo.qrc

win32: LIBS += -L$$PWD/'../../../../Program Files (x86)/MySQL/MySQL Connector C 6.1/lib/' -llibmysql

INCLUDEPATH += $$PWD/'../../../../Program Files (x86)/MySQL/MySQL Connector C 6.1/include'
DEPENDPATH += $$PWD/'../../../../Program Files (x86)/MySQL/MySQL Connector C 6.1/include'
