#include "don.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

don::don()
{
id_don=0;
nom_donateur="";
prenom_donateur="";
type_don="";
mail_donateur="";
}
don::don(int id_don,QString nom_donateur,QString prenom_donateur,QString type_don,QString mail_donateur)
{
    this->id_don=id_don;
    this->nom_donateur=nom_donateur;
    this->prenom_donateur=prenom_donateur;
    this->type_don=type_don;
    this->mail_donateur=mail_donateur;

}
int don::getid_don()
{return id_don;}


QString don::getnom_donateur(){return nom_donateur;}
QString don::getprenom_donateur(){return  prenom_donateur;}
QString don::gettype_don(){return type_don;}
QString don::getmail_donateur(){return mail_donateur;}


void don::setnom_donateur(QString nom_donateur){
    this->nom_donateur=nom_donateur;
}
void don::setprenom_donateur(QString prenom_donateur){
    this->prenom_donateur=prenom_donateur;
}
void don::settype_don(QString type_don){
    this->type_don=type_don;
}
void don::setmail_donateur(QString mail_donateur){
    this->mail_donateur=mail_donateur;
}
void don::setid_don(int id_don){
    this->id_don=id_don;
}
QSqlQueryModel * don::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from don order by ID_DON");
    return model;
}
QSqlQueryModel * don::tritype()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from don order by TYPE_DON");
    return model;
}
QSqlQueryModel * don::trinom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from don order by NOM_DONATEUR");
    return model;
}

bool don::ajouter_don(){



    QSqlQuery query;
    QString id_don_string= QString ::number(id_don);


          query.prepare("INSERT INTO don (ID_DON,NOM_DONATEUR,PRENOM_DONATEUR,TYPE_DON,MAIL_DONATEUR) "
                        "VALUES (:ID_DON, :NOM_DONATEUR,:PRENOM_DONATEUR,:TYPE_DON,:MAIL_DONATEUR)");


          query.bindValue(0, id_don_string);
          query.bindValue(1, nom_donateur);
          query.bindValue(2, prenom_donateur);
          query.bindValue(3, type_don);
          query.bindValue(4, mail_donateur);




    return query.exec();
}


QSqlQueryModel * don::afficher_don()
{


    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM don");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_DON"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_DONATEUR"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_DONATEUR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE_DON"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL_DONATEUR"));

    return model;

}
bool don::supprimer_don(int ID_DON){

    QSqlQuery query;
    don d;


    query.prepare("Delete from don where ID_DON=:ID_DON");
    query.bindValue(":ID_DON", ID_DON);

    return query.exec();
                                        }


QSqlQueryModel * don::search(QString rech){

    QSqlQueryModel *model= new QSqlQueryModel();
      model->setQuery("SELECT * FROM don WHERE ID_DON  LIKE'%"+rech+"%' or NOM_DONATEUR  LIKE'%"+rech+"%' or PRENOM_DONATEUR  LIKE'%"+rech+"%' or TYPE_DON  LIKE'%"+rech+"%' ");
      return model;

}

QString don::searchcin(QString cin){

    QSqlQuery query;
    query.prepare("SELECT * FROM patient WHERE CIN =:cin ");
    query.bindValue(":cin", cin);
    if (query.exec()&&query.next())
       {
        return query.value(1).toString();
    }

      return "false";

}

bool don::modifier_don(int id_don){

    QSqlQuery query;





          query.prepare("UPDATE don SET ID_DON=:ID_DON,NOM_DONATEUR=:NOM_DONATEUR,PRENOM_DONATEUR=:PRENOM_DONATEUR,TYPE_DON=:TYPE_DON,MAIL_DONATEUR=:MAIL_DONATEUR WHERE ID_DON=:ID_DON");

          query.bindValue(":ID_DON", id_don);
          query.bindValue(":NOM_DONATEUR", nom_donateur);
          query.bindValue(":PRENOM_DONATEUR", prenom_donateur);
          query.bindValue(":TYPE_DON", type_don);
          query.bindValue(":MAIL_DONATEUR", mail_donateur);





          return query.exec();


}


