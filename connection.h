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
<<<<<<< HEAD
    QSqlDatabase db;
=======
>>>>>>> 908e8bae17dca09ea0cbf44857754ce143348170
};

#endif // CONNECTION_H
