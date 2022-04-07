#ifndef Caisse_H
#define Caisse_H
#include <QString>
#include<QSqlQuery>
#include <QSqlQueryModel>

class caisse
{

public:
    caisse();
    caisse(int id_operation, QString date_operation ,QString type_operation, int montant,QString details);
    caisse( QString date_operation ,QString type_operation, int montant,QString details);

    bool ajouter();
    QSqlQueryModel * afficher();
bool supprimer(int id_operation );
bool modifier(int);
caisse SelectModif(int);
QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * calculatrice();
    QSqlQueryModel * showid();

    int getid_operation ();
    QString getdate_operation();
    QString gettype_operation();
    int getmontant();
    QString getdetails();

    void setid_operation (int);
    void setdate_operation(QString);
    void settype_operation(QString);
    void setmontant(int);
    void setdetails(QString);


private:
    int id_operation ;
    QString date_operation;
    QString type_operation;
    int montant;
    QString details;

};

#endif // Caisse_H
