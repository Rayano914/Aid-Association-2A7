#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test");
db.setUserName("ghada");//inserer nom de l'utilisateur
db.setPassword("ramy");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
