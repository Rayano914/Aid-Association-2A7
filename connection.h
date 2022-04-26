#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
    int Authentification(QString nom_utilisateur,QString mdp);
    QSqlDatabase db;
};

#endif // CONNECTION_H
