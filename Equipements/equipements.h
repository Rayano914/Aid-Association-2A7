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
    equipements(int,QString,int,int);
    //equipements(const equipements &);
    //equipements &operator=(const equipements &);
    ~equipements();

    //Mutateurs
    void set_id(int id){id_equipement=id;}
    void set_type_equipement(QString type_equipement){this->type_equipement=type_equipement;}
    void set_prix(int prix){this->prix=prix;}
    void set_nombre(int nombre){this->nombre=nombre;}
    //Acesseurs
    int get_id(){return id_equipement;}
    QString get_type_equipement(){return type_equipement;}
    int get_prix(){return prix;}
    int get_nombre(){return nombre;}

   //Cruds
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int cin_e);
   bool modifier();


private:
    int id_equipement;
    QString type_equipement;
    int prix;
    int nombre;

};

#endif // equipements_H
