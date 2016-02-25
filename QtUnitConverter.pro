# Файл проекта

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtUnitConverter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    units.cpp

HEADERS  += mainwindow.h \
    units.h

FORMS    += mainwindow.ui

CONFIG   += c++11
