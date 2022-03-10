#include "activite.h"
#include <QSqlQuery>
#include <QDebug>


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

bool activite::modifier(int id_activite)
{
    QSqlQuery query;
    QString  id_activite_string=QString::number( id_activite);

    query.prepare("UPDATE activite SET id_activite=:id_activite, titre= :titre, date_activite=:date_activite,localisation=:localisation,type_activite=:type_activite where id_activite=:id_activite");
    query.bindValue(":id_activite", id_activite_string);
    query.bindValue(":titre", titre);
    query.bindValue(":date_activite", date_activite);
    query.bindValue(":localisation", localisation);
    query.bindValue(":type_activite", type_activite);
    return query.exec();

}
activite activite::SelectModif(int id_activite)
{

    QSqlQuery query;
    QString res=QString::number(id_activite);
    query.prepare("Select * from activite where id_activite=:id_activite");
    query.bindValue(":id_activite",res);
    query.exec();
    query.next();
    int id_activiteVal=query.value(0).toInt();
    QString titreVal=query.value(1).toString();
    QDate date_activiteVal=query.value(2).toDate();
    QString localisationVal=query.value(3).toString();
    QString type_activiteVal=query.value(4).toString();

    activite a(id_activiteVal,titreVal,date_activiteVal,localisationVal,type_activiteVal);

    return a;
}
QSqlQueryModel * activite::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM ACTIVITE WHERE id_activite LIKE'%"+rech+"%' or titre LIKE'%"+rech+"%'  or date_activite LIKE'%"+rech+"%' or type_activite LIKE'%"+rech+"%' or localisation LIKE'%"+rech+"%'");
    return model;
}

QSqlQueryModel * activite::Trititre(QString titre)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from ACTIVITE ORDER BY titre "+titre);  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_activite"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("localisation"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_activite"));

return model ;
}


QSqlQueryModel * activite::Tritype_act(QString nom)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from ACTIVITE ORDER BY type_activite "+nom);  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_activite"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("localisation"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_activite"));

return model ;
}


QSqlQueryModel * activite::Trilocalisation(QString nom)//cls=ASC ou DESC
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from ACTIVITE ORDER BY LOCALISATION "+nom);  //comme un tableau de données en ligne , on l affiche sur table view
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_activite"));//set header data titre les colonnes
model->setHeaderData(3,Qt::Horizontal,QObject::tr("localisation"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_activite"));

return model ;
}
