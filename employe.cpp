#include "employe.h"
#include <QSqlQuery>
#include <QPdfWriter>
#include <QPainter>
#include "QMessageBox"
#include "mail/SmtpMime"


Employe::Employe()
{
    id_employe="";
    nom="GHADA";
    prenom="GHADA";
    specialite="TEST";
    mail="test@gmail.com";
    age=0;


}

Employe::Employe(QString id,QString n,QString p,QString s ,QString m,int a)
{
    id_employe=id;
    nom=n;
    prenom=p;
    specialite=s;
    mail=m;
    age=a;


}

Employe::~Employe()
{

}

//CRUDs
bool Employe::ajouter()
{
    QSqlQuery query;
    //QString res_ = QString::number(cin);

    query.prepare("insert into employe (id_employe, nom, prenom, age, specialite, mail)" "values(:id_employe, :nom, :prenom, :age, :specialite, :mail)");

    //Création des variables liées
    query.bindValue(":id_employe",id_employe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":specialite",specialite);
    query.bindValue(":mail",mail);




    return query.exec();//exec() envoie la requete pour l'exécuter

}

//AFFICHER--------------------------------------------------------------------------------------

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select ID_EMPLOYE,NOM,PRENOM,AGE,MAIL,SPECIALITE from employe");
   //model->setHeaderData(3,Qt::Horizontal,QObject::tr("MAIL"));
   //model->setHeaderData(4,Qt::Horizontal,QObject::tr("SPECIALITE"));
/*

       QSqlQueryModel* model=new QSqlQueryModel();
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
             model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
             model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
             model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUM_TEL"));
             model->setHeaderData(8, Qt::Horizontal, QObject::tr("FONCTION"));
             model->setHeaderData(9, Qt::Horizontal, QObject::tr("SALAIRE"));
       return model;

   }*/

    return model;
}

//SUPPRIMER--------------------------------------------------------------------------------------

bool Employe::supprimer(QString id_employe)
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
    query.prepare("update employe set id_employe=:id_employe, nom=:nom, prenom=:prenom, age=:age, mail=:mail, specialite=:specialite where id_employe=:id_employe");

    query.bindValue(":id_employe",id_employe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":mail",mail);
    query.bindValue(":specialite",specialite);



    return query.exec();
}

QSqlQueryModel * Employe::afficherValeur(QString valeur)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString ch1="select ";
    QString query=" from employe";
    query=ch1+valeur+query;


    model->setQuery(query);

    return model;
}
bool  Employe::telechargerPDF(){


                      QPdfWriter pdf("C:\\Users\\Ghada\\Desktop\\TEST.pdf");


                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.drawPixmap(QRect(7300,400,2500,2000),QPixmap("C:\\Users\\Ghada\\Downloads\\logoprojet.png"));
                          painter.setPen(Qt::darkRed);
                          painter.setFont(QFont("Arial", 30));
                          painter.drawText(960,1540,"LISTE DES EMPLOYES");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial",14));
                          painter.drawRect(100,100,7300,2600);
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial",11));
                          painter.drawText(200,3300,"CIN Employe");
                          painter.drawText(1300,3300,"Nom");
                          painter.drawText(2200,3300,"Prenom");
                          painter.drawText(3200,3300,"Age");
                          painter.drawText(4400,3300,"Spécialité");
                          painter.drawText(5400,3300,"Mail");



                          QSqlQuery query;
                          query.prepare("select ID_EMPLOYE,NOM,PRENOM,AGE,SPECIALITE,MAIL from employe");

                          bool test = query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1300,i,query.value(2).toString());
                              painter.drawText(2200,i,query.value(3).toString());
                              painter.drawText(3200,i,query.value(1).toString());
                              painter.drawText(4200,i,query.value(4).toString());
                              painter.drawText(5400,i,query.value(5).toString());


                             i = i + 500;}



                    return test;

}


QSqlQueryModel *Employe::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE WHERE ID_EMPLOYE  LIKE'%"+rech+"%' or NOM  LIKE'%"+rech+"%' or MAIL  LIKE'%"+rech+"%' or SPECIALITE  LIKE'%"+rech+"%'or PRENOM  LIKE'%"+rech+"%'");
    return model;
}

