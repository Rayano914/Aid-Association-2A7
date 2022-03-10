#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <iostream>
#include <QSqlQueryModel>

using namespace std;



class EmployeData;

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString);
    //Employe(const Employe &);
    //Employe &operator=(const Employe &);
    ~Employe();

    //Mutateurs
    void set_id(int id){id_employe=id;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_specialite(QString spec){specialite=spec;}
    void set_mail(QString mail){this->mail=mail;}
    //Acesseurs
    int get_id(){return id_employe;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_specialite(){return specialite;}
    QString get_mail(){return mail;}

   //Cruds
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int cin_e);
   bool modifier();
   QSqlQueryModel * afficherValeur(QString valeur);

   //metiers
   bool  telechargerPDF();

   QSqlQueryModel * rechercher(QString);


private:
    int id_employe;
    QString nom;
    QString prenom;
    QString specialite;
    QString mail;

};

#endif // EMPLOYE_H
