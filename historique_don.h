#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historique_don
{
public:

    historique_don();
    void save_txt(QString,QString,QString,QString,QString);
    QString hist();


private:
    QString ch;
};

#endif // HISTORIQUE_H
