QT       += core gui sql\
   quick serialport charts


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

SOURCES += \
    OrangeSMS.cpp \
    activite.cpp \
    arduino.cpp \
    caisse.cpp \
    connection.cpp \
    don.cpp \
    duscene.cpp \
    employe.cpp \
    equipements.cpp \
    excel.cpp \
    gifanimation.cpp \
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
    notif.cpp \
    stat_caisse.cpp

HEADERS += \
    OrangeSMS.h \
    activite.h \
    arduino.h \
    caisse.h \
    connection.h \
    don.h \
    duscene.h \
    employe.h \
    equipements.h \
    excel.h \
    gifanimation.h \
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
    notif.h \
    stat_caisse.h

FORMS += \
    mainwindow.ui \
    stat_caisse.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    translation.qrc
