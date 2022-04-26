#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
class patient
{
    int cin,age,num_chambre,contact_famille;
    QString nom,prenom,type_maladie,image;
    QDate rendez_vous;
public:
    patient();
    patient(int,QString,QString,int,QDate,QString,int,int,QString);
    //Getters
    int getcin();
    int getage();
    int getnum_chambre();
    int getcontact_famille();
    QString getnom();
     QString getprenom();
      QString gettype_maladie();
      QDate getrendez_vous();

      //Setters
      void setnom(QString nom);
      void setprenom(QString prenom);
      void settype_maladie(QString type_maladie);
      void setcin(int cin );
      void setage(int age );
      void setnum_chambre(int num_chambre );
        void setcontact_famille(int contact_famille );
        void setrendez_vous(QDate rendez_vous);
        void setimage(QString image);

        bool ajouter_patient();
        QSqlQueryModel * afficher_patient();
          QSqlQueryModel * afficher_C(QDate RENDEZ_VOUS);
                 QSqlQueryModel * afficher_C2();
        QSqlQueryModel * afficher_combo();
        bool recherche(int);
        bool modifier_patient();
        bool supprimer_patient(int);
        bool DateValide(QDate Rendez_vous);
        bool chaine_Valid(QString chaine);
        QSqlQueryModel *search(QString rech);
        QSqlQueryModel *trier(QString x);
        QSqlQueryModel *trierdesc(QString x);

};

#endif // PATIENT_H
