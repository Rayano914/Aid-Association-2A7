#include "mainwindow.h"
#include "connexion.h"
#include <QtDebug>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;
    bool test=c.createconnexion();
    if(test==true)
    {
        w.show();
        //m.show();
      //d.show();


      qDebug()<<"connection reussite";          /*     */
      //QMessageBox::information(nullptr,QObject::tr("database is open"),
        //                       QObject::tr("Connection successfull\n""click ok to exit"),QMessageBox::Ok);
    }
    else
    {
        qDebug()<<"connection failed";
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("Connection failed\n""click cancel to exit"),QMessageBox::Cancel);
    }
    return a.exec();
}
