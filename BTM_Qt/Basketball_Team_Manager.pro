#-------------------------------------------------
#
# Project created by QtCreator 2018-11-15T09:36:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Basketball_Team_Manager
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    calendar.cpp \
    training.cpp \
    preparation.cpp \
    display.cpp \
    mainmenu.cpp \
    startmenu.cpp \
    teaminfo.cpp \
    market.cpp \
    League.cpp \
    Player.cpp \
    Team.cpp \
    User.cpp \
    nextgame.cpp \
    GameEngine/gameengine.cpp \
    tactics.cpp
    preparation_ingame.cpp \
    tactic_ingame.cpp

HEADERS += \
        mainwindow.h \
    calendar.h \
    training.h \
    preparation.h \
    display.h \
    mainmenu.h \
    startmenu.h \
    teaminfo.h \
    market.h \
    League.h \
    Player.h \
    Team.h \
    User.h \
    nextgame.h \
    GameEngine/gameengine.h \
    tactics.h
    preparation_ingame.h \
    tactic_ingame.h

FORMS += \
        mainwindow.ui \
    calendar.ui \
    training.ui \
    preparation.ui \
    calendar.ui \
    training.ui \
    preparation.ui \
    startmenu.ui \
    mainmenu.ui \
    teaminfo.ui \
    market.ui \
    nextgame.ui \
    tactics.ui
    preparation_ingame.ui \
    tactic_ingame.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res_file.qrc
