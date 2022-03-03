#ifndef ACTIVITES_H
#define ACTIVITES_H

#include <QString>
#include<QDate>
#include<QSqlQuery>
#include <QSqlQueryModel>

class activite
{

public:
    activite();
    activite(int id_activite, QString titre, int date_activite,QString localisation, QString type_activite);

    bool ajouter();
    QSqlQueryModel * afficher();
bool supprimer(int id_activite);
bool modifier();

    int getid_activite();
    QString gettitre();
    int getdate_activite();
    QString getlocalisation();

    QString gettype_activite();

    void setid_activite(int);
    void settitre(QString);
     void setdate_activite(int);
    void setlocalisation(QString);
    void settype_activite(QString);



private:
    int id_activite;
    QString localisation,titre,type_activite;
    int date_activite;
};




#endif // ACTIVITES_H
