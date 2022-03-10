#ifndef Caisse_H
#define Caisse_H
#include <QString>
#include<QSqlQuery>
#include <QSqlQueryModel>

class caisse
{

public:
    caisse();
    caisse(int id_operation, QString date_operation ,QString type_operation, int montant);

    bool ajouter();
    QSqlQueryModel * afficher();
bool supprimer(int id_operation );
bool modifier();

    int getid_operation ();
    QString getdate_operation();
    QString gettype_operation();
    int getmontant();

    void setid_operation (int);
    void setdate_operation(QString);
    void settype_operation(QString);
    void setmontant(int);



private:
    int id_operation ;
    QString date_operation;
    QString type_operation;
     int montant;

};

#endif // Caisse_H
