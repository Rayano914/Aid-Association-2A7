#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "mainwindow.h"
#include <QTranslator>
#include <QInputDialog>
#include "mail/SmtpMime"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QTranslator t;
    QStringList languages;
    languages << "Français"<< "Anglais";
    QString lang=QInputDialog::getItem(NULL,"Select Language","Language",languages);
    if(lang=="Anglais")
    {
        t.load(":/anglais.qm");
    }if(lang !="Français")
    {
        a.installTranslator(&t);
    }

    Connection c;
            bool test=c.createconnect();
            MainWindow w;
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("connection successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

                w.show();

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("connection failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);


     w.show();

    return a.exec();

}





