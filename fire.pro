
QT       += core gui network svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fire
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    app/main.cpp \
    model/fire.cpp \
    model/percentage.cpp \
    model/state.cpp \
    model/temperature.cpp \
    model/variable.cpp \
    monitor/addressbar.cpp \
    monitor/card.cpp \
    monitor/errorpage.cpp \
    monitor/monitor.cpp \
    receiver/receiver.cpp

HEADERS += \
    model/fire.h \
    model/percentage.h \
    model/state.h \
    model/temperature.h \
    model/variable.h \
    monitor/addressbar.h \
    monitor/card.h \
    monitor/errorpage.h \
    monitor/monitor.h \
    receiver/receiver.h

FORMS += \
    monitor/monitor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fire.qrc
