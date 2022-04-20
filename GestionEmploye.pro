QT       +=core gui sql axcontainer qml quick widgets quickwidgets
    quick
QT       += core gui sql\

TRANSLATIONS += eng.ts
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
OTHER_FILES += qml/main.qml
SOURCES += \
    connection.cpp \
    employe.cpp \
    equipements.cpp \
    historique.cpp \
    login.cpp \
    mail/emailaddress.cpp \
    mail/mimeattachment.cpp \
    mail/mimecontentformatter.cpp \
    mail/mimefile.cpp \
    mail/mimehtml.cpp \
    mail/mimeinlinefile.cpp \
    mail/mimemessage.cpp \
    mail/mimemultipart.cpp \
    mail/mimepart.cpp \
    mail/mimetext.cpp \
    mail/quotedprintable.cpp \
    mail/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp \
    patient.cpp \
    qrcode.cpp \
    resources.cpp \
    secformdialog.cpp \
    src/calandar.cpp \
    src/event.cpp \
    src/sqleventmodel.cpp

HEADERS += \
    connection.h \
    employe.h \
    equipements.h \
    historique.h \
    login.h \
    mail/SmtpMime \
    mail/emailaddress.h \
    mail/mimeattachment.h \
    mail/mimecontentformatter.h \
    mail/mimefile.h \
    mail/mimehtml.h \
    mail/mimeinlinefile.h \
    mail/mimemessage.h \
    mail/mimemultipart.h \
    mail/mimepart.h \
    mail/mimetext.h \
    mail/quotedprintable.h \
    mail/smtpclient.h \
    mainwindow.h \
    patient.h \
    qrcode.h \
    secformdialog.h \
    src/event.h \
    src/qtquickcontrolsapplication.h \
    src/sqleventmodel.h

FORMS += \
    mainwindow.ui \
    secformdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    auto_QRcode/AAA.JPG \
    auto_QRcode/Hassani.JPG \
    auto_QRcode/RA.JPG \
    auto_QRcode/Rayan.JPG \
    auto_QRcode/VV.JPG \
    auto_QRcode/ali.JPG \
    auto_QRcode/fggg.JPG \
    auto_QRcode/jjj.JPG \
    auto_QRcode/kk.JPG \
    auto_QRcode/nnh.JPG \
    auto_QRcode/ray.JPG \
    auto_QRcode/rlllll.JPG \
    auto_QRcode/rn.JPG \
    images/eventindicator.png \
    qml/main.qml \
    src/src.pri

RESOURCES += \
    resources.qrc \
    translation.qrc
