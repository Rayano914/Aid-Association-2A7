#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QDate>
class Historique
{
public:
    Historique();
    void save_txt(QString,QString,QString,QString,QString,QString,QString,QString);
    QString imp_hist();


private:
    QString ch;
};

#endif // HISTORIQUE_H


