QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer svg serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    camera.cpp \
    connection.cpp \
    exportexcel.cpp \
    heat.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    qrcodegeneratordemo.cpp \
    qrcodegeneratorworker.cpp \
    qrwidget.cpp \
    rec.cpp \
    reclamation.cpp \
    reservation.cpp \
    salles.cpp \
    smtp.cpp \
    stat_salle.cpp \
    workspace.cpp

HEADERS += \
    arduino.h \
    camera.h \
    connection.h \
    exportexcel.h \
    heat.h \
    mainwindow.h \
    qrcode.h \
    qrwidget.h \
    rec.h \
    reclamation.h \
    reservation.h \
    salles.h \
    smtp.h \
    stat_salle.h \
    workspace.h

FORMS += \
    camera.ui \
    mainwindow.ui \
    rec.ui \
    stat_salle.ui \
    workspace.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
