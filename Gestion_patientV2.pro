QT += core gui sql axcontainer qml quick widgets quickwidgets
QT       += core gui sql printsupport multimedia charts serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

include(src/src.pri)
include(../shared/shared.pri)

OTHER_FILES += qml/main.qml


target.path = $$[QT_INSTALL_EXAMPLES]/quickcontrols/controls/calendar
INSTALLS += target

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
    connection.cpp \
    historique.cpp \
    main.cpp \
    gestion_patient.cpp \
    patient.cpp \
    qrcode.cpp \
secformdialog.cpp \
arduino.cpp



HEADERS += \
    connection.h \
    gestion_patient.h \
    historique.h \
    patient.h \
    qrcode.h \
secformdialog.h \
arduino.h


FORMS += \
    gestion_patient.ui \
secformdialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    image/re.png
