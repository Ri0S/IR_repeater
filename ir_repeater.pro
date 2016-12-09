#-------------------------------------------------
#
# Project created by QtCreator 2016-12-09T07:32:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ir_repeater
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    repeater.cpp

HEADERS  += widget.h \
    irrev.h

FORMS    += widget.ui

LIBS += -lwiringPi\
        -lpthread
CONFIG += c++11
