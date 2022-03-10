#ifndef ACTIVITE_H
#define ACTIVITE_H
#include "QDate"
#include <QString>
#include <iostream>
#include <QSqlQueryModel>

using namespace std;





class activite
{
public:
    activite();
   activite(int,QString,QDate,QString,QString);

    ~activite();

    //Mutateurs
    void set_id(int id){id_activite=id;}
    void set_titre(QString titre){this->titre=titre;}
    void set_date_activite(QDate date_activite){this->date_activite=date_activite;}
    void set_localisation(QString localisation){this->localisation=localisation;}
    void set_type_activite(QString type_activite){this->type_activite=type_activite;}
    //Acesseurs
    int get_id(){return id_activite;}
    QString get_titre(){return titre;}
   QDate get_date_activite(){return date_activite;}
    QString get_localisation(){return localisation;}
    QString get_type_activite(){return type_activite;}

   //Cruds
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int id_act);
   bool modifier(int id_act);




private:
    int id_activite;
    QString type_activite,titre,localisation;
   QDate date_activite;


};

#endif // activite_H
