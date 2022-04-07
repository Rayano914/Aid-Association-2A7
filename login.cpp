#include "login.h"
#include <QString>
#include <QSqlQuery>


using namespace std;

login::login()
{
    nom_utilisateur="admin";
    mdp="admin";
    code = "_";
}

login::login(QString nom_utilisateur,QString mdp)
{
    this->nom_utilisateur=nom_utilisateur;
    this->mdp=mdp;
}

QSqlQueryModel * login::affichernom_utilisateur()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString query="select NOM_UTILISATEUR from EMPLOYE";


    model->setQuery(query);

    return model;
}

bool login::ajouterLogin(QString id_employe)
{
    QSqlQuery query;

    query.prepare("update EMPLOYE set nom_utilisateur=:nom_utilisateur,mdp=:mdp where id_employe=:id_employe");

    //Création des variables liées
    query.bindValue(":nom_utilisateur",nom_utilisateur);
    query.bindValue(":mdp",mdp);
    query.bindValue(":id_employe",id_employe);


    return query.exec();//exec() envoie la requete pour l'exécuter

}

bool login::modifierLogin()
{
    QSqlQuery query;
    query.prepare("update EMPLOYE set mdp=:mdp where nom_utilisateur=:nom_utilisateur");

    query.bindValue(":nom_utilisateur",nom_utilisateur);
    query.bindValue(":mdp",mdp);

    return query.exec();
}
