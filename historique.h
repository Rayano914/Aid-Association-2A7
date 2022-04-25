#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historique
{
public:

    historique();
    void enregistrer_txt(QString,QString,QString,QString,QString,QString);
    QString imprimer_hist();
    void save_txt(QString,QString,QString,QString,QString);
    QString hist();
    QString imp_hist();
    void save(QString);
    QString imp();
    void save_t(QString,QString,QString,QString,QString,QString);


private:
    QString chaine,ch;
};

#endif // HISTORIQUE_H
