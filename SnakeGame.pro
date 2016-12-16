#-------------------------------------------------
#
# Project created by QtCreator 2016-12-15T14:13:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnakeGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snake.cpp \
    apple.cpp

HEADERS  += mainwindow.h \
    snake.h \
    apple.h

FORMS    += mainwindow.ui
