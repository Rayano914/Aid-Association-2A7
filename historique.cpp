#include "historique.h"
#include <QSqlQuery>
#include <QDate>
historique::historique()
{

}
void historique:: enregistrer_txt(QString id ,QString type,QString prix,QString nombre,QString id_operation,QString genre)
{

 QSqlQuery query;
     QString prenom;
    query.prepare("Select prenom_employe from employe " );
            query.bindValue(":id_employe",2) ;
            query.exec();
     query.next() ;
     prenom=query.value("prenom_employe").toString();
    QFile file ("C:/Users/Ghada/Desktop/ghada/historique_equipement.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+id+"\ntype: "+type+"\nprix: "+prix+"\nnombre: "+nombre+"\nid_operation: "+id_operation+"\nprenom:"+prenom+"\n "+genre << "\n\n\n" ;
}
QString historique::imprimer_hist()
{
    chaine="";
       QFile file("C:/Users/Ghada/Desktop/ghada/historique_equipement.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         chaine="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            chaine+=myString+"\n";

      }
      return chaine;
}
void historique:: save_txt(QString id ,QString nom,QString prenom,QString type,QString mail)
{
    QFile file ("C:/Users/Ghada/Desktop/ghada/historique_dons.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+id+"\ntype: "+nom+"\nprix: "+prenom+"\nnombre: "+type+"\n"+mail << "\n";
}
QString historique::hist()
{
    ch="";
       QFile file("C:/Users/Ghada/Desktop/ghada/historique_dons.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}
QString historique::imp_hist()
{
    ch="";
       QFile file("C:/Users/Ghada/Desktop/ghada/historique_activite.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}
void historique:: save(QString titre )
{
    QFile file ("C:/Users/Ghada/Desktop/ghada/historique_activite.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+titre<< "\n";
}
void historique:: save_t(QString id ,QString type,QString date,QString montant,QString details ,QString genre)
{

QSqlQuery query;
     QString prenom_donateur;
    query.prepare("Select prenom_donateur from don " );
            query.bindValue(":id_don",2) ;
            query.exec();
     query.next() ;
     prenom_donateur=query.value("prenom_donateur").toString();
    QFile file ("C:/Users/asus/Desktop/Gestion_Caisse/historique.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
        out << "id: "+id+"\ntype: "+type+"\ndate: "+date+"\nmontant: "+montant+"\ndetails: "+details+"\nprenom_donateur:"+prenom_donateur+"\n "+genre << "\n\n" ;
}
QString historique::imp()
{
    ch="";
       QFile file("C:/Users/asus/Desktop/Gestion_Caisse/historique.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}
void historique::save_txt_p(QString cin, QString nom, QString prenom, QString age, QString type_maladie, QString rendez_vous, QString num_chambre, QString contact_famille)
{
    QFile file ("C:/Users/rayan/Downloads/Aid-Association_integration/Aid-Association-2A7-main/historique.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
QDate date = QDate::currentDate();
QString s=date.toString();
out<<"Date\t"+s+"\t"+"\n";
         out<<"Dernier Ajout\n";
         out << "cin: "+cin+"\nnom: "+nom+"\nprenom: "+prenom+"\nage: "+age+"\ntype_maladie: "+type_maladie+"\nRendez_vous: "+rendez_vous+"\num_chambre: "+num_chambre+"\nContact_famille: "+contact_famille<< "\n\n";
}

QString historique::imp_hist_p()
{
    ch1="";
       QFile file("C:/Users/rayan/Downloads/Aid-Association_integration/Aid-Association-2A7-main/historique.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch1="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch1+=myString+"\n";

      }
      return ch1;
}
