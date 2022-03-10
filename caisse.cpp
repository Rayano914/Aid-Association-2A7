#include "caisse.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
//constructeur par defaut:
 caisse::caisse ()
{
    id_operation=0;
    date_operation="01/01/2022";
    type_operation="";
    montant=0;

}
 //constructeur parametre:
caisse::caisse(int id_operation, QString date_operation ,  QString type_operation, int montant)
{
    this->id_operation=id_operation;
    this->date_operation=date_operation;

    this->type_operation=type_operation;
    this->montant=montant;


}

int caisse::getid_operation(){return id_operation;}
QString caisse::getdate_operation(){return date_operation;}
QString caisse::gettype_operation(){return type_operation;}
int caisse::getmontant(){return montant;}

void caisse::setid_operation(int id_operation){this->id_operation=id_operation;}
void caisse::setdate_operation(QString date_operation){this->date_operation=date_operation;}
void caisse::settype_operation(QString type_operation){this->type_operation=type_operation;}

void caisse::setmontant(int montant){this->montant=montant;}




//--------------------------------------crud--------------------------------------------------------------
//ajouter:

bool caisse::ajouter()
{


QSqlQuery query;
query.prepare("insert into caisse (id_operation,date_operation,type_operation,montant)"
              "values (:id_operation,:date_operation,:type_operation,:montant)");

query.bindValue(":id_operation", id_operation);
query.bindValue(":date_operation", date_operation );
query.bindValue(":type_operation", type_operation );
query.bindValue(":montant", montant );





return  query.exec();

}
//suprrimer:
bool caisse::supprimer(int id_operation)
                                                                          {
    QSqlQuery query;
    query.prepare("Delete from caisse where id_operation=:id_operation");

    query.bindValue(":id_operation", id_operation);

    return query.exec();



}
//afficher:
QSqlQueryModel* caisse::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT * FROM caisse ");



return model;
}
//modifier:
bool caisse::modifier(){
    QSqlQuery query;
    QString id_string = QString::number(id_operation);

    query.prepare("update caisse set id_operation=:id_operation,date_operation=:date_operation,type_operation=:type_operation,montant=:montant where id_operation=:id_operation");

    query.bindValue(":id_operation", id_operation);
    query.bindValue(":date_operation", date_operation );

    query.bindValue(":type_operation", type_operation );
    query.bindValue(":montant", montant );




    return (query.exec());
}
