#-------------------------------------------------
#
# Project created by QtCreator 2021-12-23T22:09:45
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += concurrent
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imageCompare
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    database.cpp

HEADERS  += widget.h \
    database.h

FORMS    += widget.ui

CONFIG += c++11
CONFIG += thread

RESOURCES += \
    reso.qrc

win32: RC_ICONS = mishka.ico
