#include "connexion.h"
#include "QSqlDatabase"

connexion::connexion()
{

}

bool connexion::createconnexion(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("nour");
    db.setPassword("nour");
    if(db.open())
    {
        test=true;
    }

    return test;

}
