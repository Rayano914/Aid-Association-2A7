#include "activites.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
 activite::activite ()
{
    id_activite=0;
    titre="";
    date_activite=0;
    localisation="";
    type_activite="";

}
activite::activite(int id_activite, QString titre , int date_activite, QString localisation, QString type_activite)
{
    this->id_activite=id_activite;
    this->titre=titre;
    this->date_activite=date_activite;
    this->localisation=localisation;
    this->type_activite=type_activite;



}
int activite::getid_activite(){return id_activite;}
QString activite::gettitre(){return titre;}
int activite::getdate_activite(){return date_activite;}
QString activite::getlocalisation(){return localisation;}
QString activite::gettype_activite(){return type_activite;}

void activite::setid_activite(int id_activite){this->id_activite=id_activite;}
void activite::settitre(QString titre){this->titre=titre;}
void activite::setdate_activite(int date_activite){this->date_activite=date_activite;}
void activite::setlocalisation(QString localisation){this->localisation=localisation;}

void activite::settype_activite(QString type_activite){this->type_activite=type_activite;}






bool activite::ajouter()
{

QString id_string = QString::number(id_activite);
QString date_activites = QString::number(date_activite);
QSqlQuery query;
query.prepare("insert into ACTIVITE (id_activite,titre,date_activite,localisation,type_activite)"
              "values (:id_activite,:titre,:date_activite,:localisation,:type_activite)");

query.bindValue(":id_activite", id_string);
query.bindValue(":titre", titre );
query.bindValue(":date_activite", date_activites );
query.bindValue(":localisation", localisation );
query.bindValue(":type_activite", type_activite );





return  query.exec();

}
bool activite::supprimer(int id)
                                                                          {
    QSqlQuery query;
    query.prepare("Delete from ACTIVITE where id_activite=:id_activite");

    query.bindValue(0, id);

    return query.exec();



}
QSqlQueryModel* activite::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT * FROM ACTIVITE ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ACTIVITE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TITRE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_ACTIVITE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("LOCALISATION"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_ACTIVITE"));


return model;
}
bool activite::modifier(){
    QSqlQuery query1;
    QString id_string = QString::number(id_activite);

    query1.prepare("UPDATE ACTIVITE set id_activite=:id_activite,titre=:titre,date_activite=:date_activite,localisation=:localisation,type_activite=:type_activite");

    query1.bindValue(":id", id_string);
    query1.bindValue(":titre", titre );
    query1.bindValue(":date_activite", date_activite );
    query1.bindValue(":localisation", localisation );
    query1.bindValue(":type_activite", type_activite );




    return (query1.exec());
}
