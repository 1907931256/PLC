#-------------------------------------------------
#
# Project created by QtCreator 2017-08-03T12:18:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PLC_IDE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    setup_widget.cpp \
    qout.cpp \
    qchaxun.cpp \
    qw_dakai.cpp \
    qw_xinjian.cpp \
    compilecodewin.cpp

HEADERS  += mainwindow.h \
    setup_widget.h \
    qout.h \
    qchaxun.h \
    qw_dakai.h \
    qw_xinjian.h \
    compilecodewin.h

FORMS    += mainwindow.ui \
    setup_widget.ui \
    qout.ui \
    qchaxun.ui \
    qw_dakai.ui \
    qw_xinjian.ui \
    compilecodewin.ui

RESOURCES += \
    ck.qrc
