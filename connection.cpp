#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("nada");//inserer nom de l'utilisateur
db.setPassword("ramy");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
