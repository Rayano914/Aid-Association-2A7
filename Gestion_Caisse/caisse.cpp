#include "caisse.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
 caisse::caisse ()
{
    id_operation=0;
    date_operation=0;
    type_operation="";
    montant=0;

}
caisse::caisse(int id_operation, int date_operation ,  QString type_operation, int montant)
{
    this->id_operation=id_operation;
    this->date_operation=date_operation;
    this->type_operation=type_operation;
    this->montant=montant;



}
int caisse::getid_operation(){return id_operation;}
int caisse::getdate_operation(){return date_operation;}
QString caisse::gettype_operation(){return type_operation;}
int caisse::getmontant(){return montant;}

void caisse::setid_operation(int id_operation){this->id_operation=id_operation;}
void caisse::setdate_operation(int date_operation){this->date_operation=date_operation;}
void caisse::settype_operation(QString type_operation){this->type_operation=type_operation;}

void caisse::setmontant(int montant){this->montant=montant;}






bool caisse::ajouter()
{

    QString date_operations = QString::number(date_operation);

QString id_string = QString::number(id_operation);
QString montants = QString::number(montant);

QSqlQuery query;
query.prepare("insert into caisse (id_operation,date_operation,type_operation,montant)"
              "values (:id_operation,:date_operation,:type_operation,:montant)");

query.bindValue(":id_operation", id_string);
query.bindValue(":date_operation", date_operations );
query.bindValue(":type_operation", type_operation );
query.bindValue(":montant", montants );





return  query.exec();

}
bool caisse::supprimer(int id)
                                                                          {
    QSqlQuery query;
    query.prepare("Delete from caisse where id_operation=:id_operation");

    query.bindValue(0, id);

    return query.exec();



}
QSqlQueryModel* caisse::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT * FROM caisse ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_operation"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_operation"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_operation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("montant"));


return model;
}
bool caisse::modifier(){
    QSqlQuery query1;
    QString id_string = QString::number(id_operation);

    query1.prepare("UPDATE caisse set id_operation=:id_operation,date_operation=:date_operation,type_operation=:type_operation,montant=:montant");

    query1.bindValue(":id", id_string);
    query1.bindValue(":date_operation", date_operation );

    query1.bindValue(":type_operation", type_operation );
    query1.bindValue(":montant", montant );




    return (query1.exec());
}
