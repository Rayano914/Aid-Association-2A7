#include "connection.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("aid_association");
db.setUserName("rayan1");//inserer nom de l'utilisateur
db.setPassword("esprit20");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
int Connection::Authentification(QString nom_utilisateur,QString mdp)
{
    QSqlQuery query;
    QString spec;


    query.prepare("select *from EMPLOYE where nom_utilisateur=? and mdp=?");

    query.addBindValue(nom_utilisateur);
    query.addBindValue(mdp);


    if(query.exec())
        {
            int count=0;
            while(query.next())
            {
                count++;
                spec=query.value(3).toString();
            }
            qDebug()<<count;
            if(count==1)
            {
                if (spec=="Directeur")
                return 7;
                else
                if (spec=="tresorier")
                return 13;
                else
                if (spec=="Responsable Logistiques")
                return 11;
                else
                if (spec=="Responsable Patients")
                return 14;
             }
            if(count<1)
            {
                return 0;
            }

        }
        else
        {
            return 0;
        }
    return 0;
}
