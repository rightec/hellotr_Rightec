#-------------------------------------------------
#
# Project created by QtCreator 2022-03-21T19:31:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hellotr_Rightec
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
        templatew1.cpp \
        templatew2.cpp \
        templatew3.cpp

HEADERS += \
        customnamespace.h \
        mainwindow.h \
        templatew1.h \
        templatew2.h \
        templatew3.h

FORMS += \
        mainwindow.ui \
        templatew1.ui \
        templatew2.ui \
        templatew3.ui

TRANSLATIONS = hellotr_en.ts hellotr_sp.ts hellotr_fr.ts hellotr_it.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
