#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T09:26:30
#
#-------------------------------------------------

QT       += core \
                  gui \
                  serialport \
                  charts \
                  sql \
                  axcontainer \
                  multimedia

!MobileBuild {4
QT += \
    printsupport \
    serialport \
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Drones
TEMPLATE = app

include(./MAVLinkLib.pri)
INCLUDEPATH +=./libs/mavlink/include/mavlink/v1.0

SOURCES += main.cpp\
        mainwindow.cpp \
    linkmanager.cpp \
    SerialCommunication.cpp \
    Vehicle.cpp \
    QuadApplication.cpp \
    Toolbox.cpp \
    VehicleManager.cpp \
    attitude_indicator.cpp \
    audio_worker.cpp \


HEADERS  += mainwindow.h \
    linkmanager.h \
    SerialCommunication.h \
    Vehicle.h \
    QuadApplication.h \
    Toolbox.h \
    VehicleManager.h \
    attitude_indicator.h \
    audio_worker.h \

FORMS    += mainwindow.ui

UI_DIR  += E:/baseModule-12.17
RESOURCES += \
    attitude.qrc


