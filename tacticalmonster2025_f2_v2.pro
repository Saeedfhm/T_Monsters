#-------------------------------------------------
#
# Project created by QtCreator 2025-04-11T11:33:56
#
#-------------------------------------------------

QT       += core gui widgets  multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tacticalmonster2025_f1_v18
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
    floating.cpp \
    flying.cpp \
    grounded.cpp \
        main.cpp \
        mainwindow.cpp \
    second.cpp \
    gallerypage.cpp \
    login.cpp \
    game_page.cpp \
    hexagonitem.cpp \
    agent.cpp \
    waterwalking.cpp

HEADERS += \
    floating.h \
    flying.h \
    grounded.h \
        mainwindow.h \
    second.h \
    gallerypage.h \
    login.h \
    game_page.h \
    hexagonitem.h \
    agent.h \
    waterwalking.h

FORMS += \
        mainwindow.ui \
    second.ui \
    gallerypage.ui \
    login.ui \
    game_page.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

