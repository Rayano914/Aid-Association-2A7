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
    Employe(QString,QString,QString,QString,QString,int);
    //Employe(const Employe &);
    //Employe &operator=(const Employe &);
    ~Employe();

    //Mutateurs
    void set_id(QString id){id_employe=id;}
    void set_nom(QString nom){this->nom=nom;}
    void set_prenom(QString prenom){this->prenom=prenom;}
    void set_specialite(QString spec){specialite=spec;}
    void set_mail(QString mail){this->mail=mail;}
    void set_age(int age){this->age=age;}
    //Acesseurs
    QString get_id(){return id_employe;}
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_specialite(){return specialite;}
    QString get_mail(){return mail;}
    int get_age(){return age;}

   //Cruds
   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(QString id_employe);
   bool modifier();
   QSqlQueryModel * afficherValeur(QString valeur);

   //metiers
   bool  telechargerPDF();

   QSqlQueryModel * rechercher(QString);


private:
    QString id_employe;
    QString nom;
    QString prenom;
    QString specialite;
    QString mail;
    int age;

};

#endif // EMPLOYE_H
