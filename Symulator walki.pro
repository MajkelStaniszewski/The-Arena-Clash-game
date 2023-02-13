QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BigBen.cpp \
    Charakter.cpp \
    GameManager.cpp \
    GameMap.cpp \
    Mercenary.cpp \
    RPGDices.cpp \
    Team.cpp \
    Vector(Player).cpp \
    Warrior.cpp \
    gui.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BigBen.h \
    Charakter.h \
    GameManager.h \
    GameMap.h \
    Mercenary.h \
    RPGDices.h \
    Team.h \
    Tile.h \
    TilePoint.h \
    Vector(Player).h \
    Warrior.h \
    gui.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
