#include "activite.h"
#include <QSqlQuery>



activite::activite()
{
    id_activite=111111;
    titre="abc";
    date_activite.toString("yyyy/dd/mm");
    localisation="abc";
    type_activite="abc";

}

activite::activite(int id, QString t,QDate d,QString l, QString a)
{
    id_activite=id;
    titre=t;
    date_activite=d;
    localisation=l;
    type_activite=a;

}

activite::~activite()
{

}

//CRUDs
bool activite::ajouter()
{
    QSqlQuery query;


    query.prepare("insert into activite (id_activite, titre, date_activite, localisation,type_activite)" "values(:id_activite, :titre, :date_activite, :localisation,:type_activite)");

    //Création des variables liées
    query.bindValue(":id_activite",id_activite);
    query.bindValue(":titre",titre);
    query.bindValue(":date_activite",date_activite);
    query.bindValue(":localisation",localisation);
    query.bindValue(":type_activite",type_activite);





    return query.exec();//exec() envoie la requete pour l'exécuter

}

//AFFICHER--------------------------------------------------------------------------------------

QSqlQueryModel * activite::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select *from activite");
   // model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));


    return model;
}

//SUPPRIMER--------------------------------------------------------------------------------------

bool activite::supprimer(int id_activite)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("Delete from activite where id_activite=:id_activite");
    query.bindValue(":id_activite",id_activite);

    return query.exec();

}

//MODIFIER--------------------------------------------------------------------------------------

bool activite::modifier(int id_act)
{
    QSqlQuery query;
    QString  id_activite_string=QString::number( id_activite);

    query.prepare("UPDATE activite SET titre= :titre, date_activite=:date_activite,localisation= :localisation,type_activite=:type_activite where id_activite=:id_activite");
    query.bindValue(":id_activite", id_activite_string);
    query.bindValue(":titre", titre);
    query.bindValue(":date_activite", date_activite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":type_activite", type_activite);
    return query.exec();

}


