#-------------------------------------------------
#
# Project created by QtCreator 2018-03-10T23:57:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProyectoIA1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    duthread.cpp \
    minmax.cpp \
    nodo.cpp

HEADERS += \
    mainwindow.hpp \
    duthread.hpp \
    minmax.hpp \
    nodo.hpp

FORMS += \
        mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++11

DISTFILES += \
    images/mario_left.png \
    images/mario_right.png \
    mario.png \
    file.txt \
    prueba11.txt \
    images/chess-black.png \
    images/chess-white.png \
    images/fruit.png

OTHER_FILES += \
    file.txt \
    images/wall.png \
    images/marioflor.png
