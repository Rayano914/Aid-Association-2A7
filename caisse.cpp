#include "caisse.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
//constructeur par defaut:
 caisse::caisse ()
{
    id_operation=0;
    date_operation="01/01/2022";
    type_operation="";
    montant=0;
    details="";

}
 //constructeur parametre:
caisse::caisse(int id_operation, QString date_operation ,  QString type_operation, int montant,QString details)
{
    this->id_operation=id_operation;
    this->date_operation=date_operation;
    this->type_operation=type_operation;
    this->montant=montant;
    this->details=details;


}

int caisse::getid_operation(){return id_operation;}
QString caisse::getdate_operation(){return date_operation;}
QString caisse::gettype_operation(){return type_operation;}
int caisse::getmontant(){return montant;}
QString caisse::getdetails(){return details;}


void caisse::setid_operation(int id_operation){this->id_operation=id_operation;}
void caisse::setdate_operation(QString date_operation){this->date_operation=date_operation;}
void caisse::settype_operation(QString type_operation){this->type_operation=type_operation;}

void caisse::setmontant(int montant){this->montant=montant;}
void caisse::setdetails(QString details){this->details=details;}




//--------------------------------------crud--------------------------------------------------------------
//ajouter:

bool caisse::ajouter()
{


QSqlQuery query;
query.prepare("insert into caisse (id_operation,date_operation,type_operation,montant,details)"
              "values (:id_operation,:date_operation,:type_operation,:montant,:details)");
//creation des variables liées:
query.bindValue(":id_operation", id_operation);
query.bindValue(":date_operation", date_operation );
query.bindValue(":type_operation", type_operation );
query.bindValue(":montant", montant );
query.bindValue(":details", details );

return  query.exec(); //envoie la requete pour l'executer

}

//suprrimer:
bool caisse::supprimer(int id_operation)
                                                                          {
    QSqlQuery query;
    query.prepare("Delete from caisse where id_operation=:id_operation");

    query.bindValue(":id_operation", id_operation);

    return query.exec();



}


//afficher:
QSqlQueryModel* caisse::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT * FROM caisse ");

return model;
}
//modifier:
bool caisse::modifier(int id_operation)
{
    QSqlQuery query;
    QString id_operation_string=QString::number(id_operation);
    QString date_operation_string=QString(date_operation);
    QString type_operation_string=QString(type_operation);
    QString montant_string=QString::number(montant);
    QString details_string=QString(details);
    query.prepare("UPDATE CAISSE SET id_operation= :id_operation, date_operation= :date_operation,type_operation= :type_operation,montant= :montant where id_operation=:id_operation");
    query.bindValue(":id_operation", id_operation_string);
    query.bindValue(":date_operation", date_operation_string);
    query.bindValue(":type_operation", type_operation_string);
    query.bindValue(":montant", montant_string);
    query.bindValue(":details", details_string);
    return query.exec();
}

caisse caisse::SelectModif(int id_operation)
{

    QSqlQuery query;
    QString res=QString::number(id_operation);
    query.prepare("Select * from caisse where id_operation=:id_operation");
    query.bindValue(":id_operation",res);
    query.exec();
    query.next();
    int id_operationVal=query.value(0).toInt();
     QString date_operationVal=query.value(1).toString();
    QString type_operationVal=query.value(2).toString();
    int montantVal=query.value(3).toInt();
    QString detailsVal=query.value(4).toString();


    caisse c(id_operationVal,date_operationVal,type_operationVal,montantVal,detailsVal);

    return c;
}
QSqlQueryModel *caisse::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
          QSqlQuery query;
          query.prepare("SELECT * FROM CAISSE WHERE id_operation LIKE :rech or date_operation LIKE :rech or type_operation LIKE :rech or montant LIKE :rech or details LIKE :rech");
          query.bindValue(":rech",rech);
          query.exec();
          model->setQuery(query);
   // model->setQuery("SELECT * FROM CAISSE WHERE id_operation LIKE'%"+rech+"%' or date_operation LIKE'%"+rech+"%' or type_operation LIKE'%"+rech+"%' or montant LIKE'%"+rech+"%' or details LIKE'%"+rech+"%'");
    return model;
}

QSqlQueryModel* caisse::calculatrice()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("SELECT SUM(montant) FROM caisse ");

return model;
}

QSqlQueryModel *caisse::showid()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select id_operation from caisse");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;

}

