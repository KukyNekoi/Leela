#-------------------------------------------------
#
# Project created by QtCreator 2014-03-02T15:52:36
#
#-------------------------------------------------

QT       += core gui opengl
#CONFIG   += c++11
QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocalDebugServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    libs/serverthread.cpp \
    libs/server.cpp \
    gl/myglwidget.cpp

HEADERS  += mainwindow.h \
    libs/serverthread.h \
    libs/server.h \
    gl/myglwidget.h

FORMS    += mainwindow.ui
