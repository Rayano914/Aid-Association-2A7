#ifndef DON_H
#define DON_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class don
{
    int id_don;
    QString nom_donateur,prenom_donateur,type_don,mail_donateur;

 public:
    //Constructeurs
     don();
     don(int,QString,QString,QString,QString);
     //Getters
     int getid_don();
     QString getnom_donateur();
      QString getprenom_donateur();
       QString gettype_don();
       QString getmail_donateur();

       //Setters
       void setnom_donateur(QString nom);
       void setprenom_donateur(QString prenom);
       void settype_don(QString type_maladie);
       void setmail_donateur(QString type_maladie);
       void setid_don(int id );


         bool ajouter_don();
         QSqlQueryModel * afficher_don();
         bool recherche(int);
         bool modifier_don(int);
         bool supprimer_don(int);
};

#endif // DON_H
