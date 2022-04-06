#include "equipements.h"
#include <QSqlQuery>



equipements::equipements()
{
    id_equipement=111111;
    type_equipement="abc";
    prix=11111;
    nombre=5;
    id_operation=0;
}

equipements::equipements(int id,QString e,int p,int n,int op)
{
    id_equipement=id;
    type_equipement=e;
    prix=p;
    nombre=n;
    id_operation=op;
}

equipements::~equipements()
{

}

//CRUDs
bool equipements::ajouter()
{
    QSqlQuery query;


    query.prepare("insert into equipement (id_equipement, type_equipement, prix, nombre,id_operation)" "values(:id_equipement, :type_equipement, :prix, :nombre, :id_operation)");

    //Création des variables liées
    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":type_equipement",type_equipement);
    query.bindValue(":prix",prix);
    query.bindValue(":nombre",nombre);
    query.bindValue(":id_operation",id_operation);



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
    query.prepare("update equipement set id_equipement=:id_equipement, type_equipement=:type_equipement, prix=:prix, nombre=:nombre, id_operation=:id_operation where id_equipement=:id_equipement");

    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":type_equipement",type_equipement);
    query.bindValue(":prix",prix);
    query.bindValue(":nombre",nombre);
    query.bindValue(":id_operation",id_operation);


    return query.exec();
}

QSqlQueryModel *equipements::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPEMENT WHERE id_equipement LIKE'%"+rech+"%' or type_equipement LIKE'%"+rech+"%' or prix  LIKE'%"+rech+"%' or nombre  LIKE'%"+rech+"%'");
    return model;
}

QSqlQueryModel * equipements::tri_prix()
{   QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT order by prix");
    return model;
}


QSqlQueryModel * equipements::tri_id()
{   QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT order by id_equipement");
    return model;
}



QSqlQueryModel * equipements::tri_nombre()
{   QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EQUIPEMENT order by nombre");
    return model;
}


