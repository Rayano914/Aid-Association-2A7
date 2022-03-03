#include "equipements.h"
#include <QSqlQuery>



equipements::equipements()
{
    id_equipement=111111;
    type_equipement="abc";
    prix=11111;
    nombre=5;
}

equipements::equipements(int id,QString e,int p,int n)
{
    id_equipement=id;
    type_equipement=e;
    prix=p;
    nombre=n;
}

equipements::~equipements()
{

}

//CRUDs
bool equipements::ajouter()
{
    QSqlQuery query;


    query.prepare("insert into equipement (id_equipement, type_equipement, prix, nombre)" "values(:id_equipement, :type_equipement, :prix, :nombre)");

    //Création des variables liées
    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":type_equipement",type_equipement);
    query.bindValue(":prix",prix);
    query.bindValue(":nombre",nombre);



    return query.exec();//exec() envoie la requete pour l'exécuter

}

//AFFICHER--------------------------------------------------------------------------------------

QSqlQueryModel * equipements::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select *from equipement");
   // model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));


    return model;
}

//SUPPRIMER--------------------------------------------------------------------------------------

bool equipements::supprimer(int id_equipement)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("Delete from equipement where id_equipement=:id_equipement");
    query.bindValue(":id_equipement",id_equipement);

    return query.exec();

}

//MODIFIER--------------------------------------------------------------------------------------

bool equipements::modifier()
{
    QSqlQuery query;
    query.prepare("update equipement set id_equipement=:id_equipement, type_equipement=:type_equipement, prix=:prix, nombre=:nombre where id_equipement=:id_equipement");

    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":type_equipement",type_equipement);
    query.bindValue(":prix",prix);
    query.bindValue(":nombre",nombre);


    return query.exec();
}

