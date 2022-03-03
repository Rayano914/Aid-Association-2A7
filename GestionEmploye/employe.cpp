#include "employe.h"
#include <QSqlQuery>



Employe::Employe()
{
    id_employe=111111;
    nom="GHADA";
    prenom="GHADA";
    specialite="TEST";
    mail="test@gmail.com";
}

Employe::Employe(int id,QString n,QString p,QString s,QString m)
{
    id_employe=id;
    nom=n;
    prenom=p;
    specialite=s;
    mail=m;
}

Employe::~Employe()
{

}

//CRUDs
bool Employe::ajouter()
{
    QSqlQuery query;
    //QString res_ = QString::number(cin);

    query.prepare("insert into employe (id_employe, nom, prenom, mail, specialite)" "values(:id_employe, :nom, :prenom, :mail, :specialite)");

    //Création des variables liées
    query.bindValue(":id_employe",id_employe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":specialite",specialite);


    return query.exec();//exec() envoie la requete pour l'exécuter

}

//AFFICHER--------------------------------------------------------------------------------------

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select *from employe");
   // model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));


    return model;
}

//SUPPRIMER--------------------------------------------------------------------------------------

bool Employe::supprimer(int id_employe)
{
    QSqlQuery query;
    //QString res=QString::number(id);
    query.prepare("Delete from employe where id_employe=:id_employe");
    query.bindValue(":id_employe",id_employe);

    return query.exec();

}

//MODIFIER--------------------------------------------------------------------------------------

bool Employe::modifier()
{
    QSqlQuery query;
    query.prepare("update employe set id_employe=:id_employe, nom=:nom, prenom=:prenom, mail=:mail, specialite=:specialite where id_employe=:id_employe");

    query.bindValue(":id_employe",id_employe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":specialite",specialite);

    return query.exec();
}

