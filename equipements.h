#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H

#include <QString>
#include <iostream>
#include <QSqlQueryModel>

using namespace std;





class equipements
{
public:
    equipements();
    equipements(int,QString,int,int,int);

    ~equipements();

    //Mutateurs
    void set_id(int id){id_equipement=id;}
    void set_type_equipement(QString type_equipement){this->type_equipement=type_equipement;}
    void set_prix(int prix){this->prix=prix;}
    void set_nombre(int nombre){this->nombre=nombre;}
      void set_id_operation(int id_operation){this->id_operation=id_operation;}
    //Acesseurs
    int get_id(){return id_equipement;}
    QString get_type_equipement(){return type_equipement;}
    int get_prix(){return prix;}
    int get_nombre(){return nombre;}
    int get_id_operation(){return id_operation;}
   //Cruds
   bool ajouter();
   QSqlQueryModel * afficher_equipement();
   bool supprimer(int cin_e);
   bool modifier();
   //Metiers
   QSqlQueryModel * rechercher(QString);
   QSqlQueryModel * tri_prix();
   QSqlQueryModel * tri_id();
   QSqlQueryModel * tri_nombre();



private:
    int id_equipement;
    QString type_equipement;
    int prix;
    int nombre;
    int id_operation;

};

#endif // equipements_H
