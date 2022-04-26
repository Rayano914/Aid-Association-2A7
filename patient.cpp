#include "patient.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

patient::patient()
{
    cin=0;
    age=0;
    num_chambre=0;
    contact_famille=0;
    nom="";
    prenom="";
    type_maladie="";
    image="";
}

patient::patient(int cin,QString nom,QString prenom,int num_chambre,QDate rendez_vous,QString type_maladie,int age,int contact_famille,QString image)
{
    this->cin=cin;
    this->age=age;
    this->num_chambre=num_chambre;
    this->contact_famille=contact_famille;
    this->nom=nom;
    this->prenom=prenom;
    this->type_maladie=type_maladie;
    this->rendez_vous=rendez_vous;
    this->image=image;
}
int patient::getcin()
{return cin;}
int patient::getage()
{return age;}
int patient::getnum_chambre()
{return num_chambre;}
int patient::getcontact_famille(){return contact_famille;}

QString patient::getnom(){return nom;}
QString patient::getprenom(){return  prenom;}
QString patient::gettype_maladie(){return type_maladie;}

QDate patient::getrendez_vous(){return rendez_vous;}

void patient::setnom(QString nom){
    this->nom=nom;
}
void patient::setprenom(QString prenom){
    this->prenom=prenom;
}
void patient::settype_maladie(QString type_maladie){
    this->type_maladie=type_maladie;
}
void patient::setcin(int cin){
    this->cin=cin;

}
void patient::setage(int age){
    this->age=age;
}
void patient::setnum_chambre(int num_chambre)
{this->num_chambre=num_chambre;}

void patient::setcontact_famille(int contact_famille)
{this->contact_famille=contact_famille;}

void patient::setrendez_vous(QDate rendez_vous){
    this->rendez_vous=rendez_vous;
}
void patient::setimage(QString image){
    this->image=image;
}

bool patient::ajouter_patient(){



    QSqlQuery query;
    QString cin_string= QString ::number(cin);
    QString age_string= QString ::number(age);
    QString num_chambre_string= QString ::number(num_chambre);
    QString contact_famille_string= QString ::number(contact_famille);


          query.prepare("INSERT INTO PATIENT (CIN,NOM_PATIENT,PRENOM_PATIENT,AGE,RENDEZ_VOUS,TYPE_MALADIE,NUM_CHAMBRE,CONTACT_FAMILLE,IMAGE ) "
                        "VALUES (:CIN, :NOM_PATIENT,:PRENOM_PATIENT,:AGE,:RENDEZ_VOUS,:TYPE_MALADIE,:NUM_CHAMBRE,:CONTACT_FAMILLE,:IMAGE)");


          query.bindValue(0, cin_string);
          query.bindValue(1, nom);
          query.bindValue(2, prenom);
          query.bindValue(3, age_string);
          query.bindValue(4, rendez_vous);
          query.bindValue(5, type_maladie);
          query.bindValue(6, num_chambre_string);
          query.bindValue(7, contact_famille_string);
          query.bindValue(8, image);



    return query.exec();
}
QSqlQueryModel * patient::afficher_C(QDate RENDEZ_VOUS){

QSqlQuery query;
QString m=RENDEZ_VOUS.toString();

    QSqlQueryModel* model=new QSqlQueryModel();

 //QString c ="SELECT* FROM patient WHERE RENDEZ_VOUS like "'+RENDEZ_VOUS.toString();
   // query.prepare("SELECT* FROM patient where RENDEZ_VOUS like '08%'" );
       //   query.bindValue(":RENDEZ_VOUS",RENDEZ_VOUS) ;

          model->setQuery("SELECT* FROM patient where RENDEZ_VOUS like '08%'" );
//model->setQuery("SELECT* FROM patient where RENDEZ_VOUS like '%"+m+"%' " );

          //TO_DATE('26/JAN/2011 00:00:00', 'dd/mon/yyyy HH24:MI:SS')


          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("RENDEZ_VOUS"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_MALADIE"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_CHAMBRE"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("CONTACT_FAMILLE"));

    return model;


}
QSqlQueryModel * patient::afficher_C2(){
    QSqlQuery query;
    //QString m=RENDEZ_VOUS.toString();

        QSqlQueryModel* model=new QSqlQueryModel();

     //QString c ="SELECT* FROM patient WHERE RENDEZ_VOUS like "'+RENDEZ_VOUS.toString();
       // query.prepare("SELECT* FROM patient where RENDEZ_VOUS like '08%'" );
           //   query.bindValue(":RENDEZ_VOUS",RENDEZ_VOUS) ;

              model->setQuery("SELECT* FROM patient where RENDEZ_VOUS like '15%'" );

              //TO_DATE('26/JAN/2011 00:00:00', 'dd/mon/yyyy HH24:MI:SS')


              model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("RENDEZ_VOUS"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_MALADIE"));
              model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_CHAMBRE"));
              model->setHeaderData(7, Qt::Horizontal, QObject::tr("CONTACT_FAMILLE"));

        return model;

                                             }
QSqlQueryModel * patient::afficher_patient()
{


    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM patient ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("RENDEZ_VOUS"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_MALADIE"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_CHAMBRE"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("CONTACT_FAMILLE"));

    return model;

}
bool patient::supprimer_patient(int CIN){
QMessageBox msgBox;
    QSqlQuery query;
    patient P;
if(recherche(CIN)){

    query.prepare("Delete from patient where CIN=:CIN");
    query.bindValue(":CIN", CIN);

 return query.exec();
}
else

return false;

    }


bool patient::recherche(int cin){
    QMessageBox msgBox;
    QSqlQuery query;
     QString cin_string=QString::number(cin);
    query.prepare("SELECT * FROM patient WHERE cin= :cin");
    query.bindValue(":cin", cin);
    if (query.exec() && query.next())
    {
            return true;
    }
    else
    {
        msgBox.setText("patient n existe pas");
        msgBox.exec();
        return false;
    }


}

bool patient::modifier_patient(){

    QSqlQuery query;





          query.prepare("UPDATE patient SET CIN=:CIN,NOM_PATIENT=:NOM_PATIENT,PRENOM_PATIENT=:PRENOM_PATIENT,AGE=:AGE,RENDEZ_VOUS=:RENDEZ_VOUS,TYPE_MALADIE=:TYPE_MALADIE,NUM_CHAMBRE=:NUM_CHAMBRE,CONTACT_FAMILLE=:CONTACT_FAMILLE,IMAGE=:IMAGE WHERE CIN=:CIN");

          query.bindValue(":CIN", cin);
          query.bindValue(":NOM_PATIENT", nom);
          query.bindValue(":PRENOM_PATIENT", prenom);
          query.bindValue(":AGE", age);
          query.bindValue(":RENDEZ_VOUS", rendez_vous);
          query.bindValue(":TYPE_MALADIE", type_maladie);
          query.bindValue(":NUM_CHAMBRE", num_chambre);
          query.bindValue(":CONTACT_FAMILLE", contact_famille);
           query.bindValue(":IMAGE", image);




          return query.exec();


}

bool patient::DateValide(QDate Rendez_vous){

    if (Rendez_vous>QDate::currentDate())

       {return false;}

    else return true;
}
bool patient::chaine_Valid(QString chaine)
   {
       int i=0;
       while(i<chaine.size())
       {
           if(! ((chaine[i]>='A' && chaine[i]<='Z')|| (chaine[i]>='a' && chaine[i]<='z')))
           {
              return false;
           }
           else
               i++;
       }
       return true;
   }


QSqlQueryModel * patient::search(QString rech){

    QSqlQueryModel *model= new QSqlQueryModel();
      model->setQuery("SELECT * FROM PATIENT WHERE CIN  LIKE'%"+rech+"%' or NOM_PATIENT  LIKE'%"+rech+"%' or PRENOM_PATIENT  LIKE'%"+rech+"%' or TYPE_MALADIE  LIKE'%"+rech+"%' or AGE  LIKE'%"+rech+"%'  or CONTACT_FAMILLE  LIKE'%"+rech+"%' ");
      return model;

}
QSqlQueryModel *patient::trier(QString x){

            QSqlQueryModel *model= new QSqlQueryModel();

            if(x=="NOM")
                model->setQuery("select * from patient order by NOM_PATIENT ASC ");
            else if(x=="AGE")
                model->setQuery("select * from patient order by AGE ASC ");
            else if (x=="RENDEZ_VOUS")
                model->setQuery("select * from patient order by RENDEZ_VOUS ASC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("RENDEZ_VOUS"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_MALADIE"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_CHAMBRE"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("CONTACT_FAMILLE"));
                return model;
}


QSqlQueryModel *patient::trierdesc(QString x){

            QSqlQueryModel *model= new QSqlQueryModel();

            if(x=="NOM")
                model->setQuery("select * from patient order by NOM_PATIENT DESC ");
            else if(x=="AGE")
                model->setQuery("select * from patient order by AGE DESC ");
            else if (x=="RENDEZ_VOUS")
                model->setQuery("select * from patient order by RENDEZ_VOUS DESC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PATIENT"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_PATIENT"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("RENDEZ_VOUS"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE_MALADIE"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("NUM_CHAMBRE"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("CONTACT_FAMILLE"));
                return model;
}

