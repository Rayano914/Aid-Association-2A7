#include "connection.h"
//Test Tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("nada");//inserer nom de l'utilisateur
db.setPassword("ramy");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
