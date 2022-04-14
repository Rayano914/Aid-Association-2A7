#include "historique.h"
#include <QSqlQuery>
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
    QFile file ("C:/Users/ASUS/Documents/Equipements/hist.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+id+"\ntype: "+type+"\nprix: "+prix+"\nnombre: "+nombre+"\nid_operation: "+id_operation+"\nprenom:"+prenom+"\n "+genre << "\n\n\n" ;
}
QString historique::imprimer_hist()
{
    chaine="";
       QFile file("C:/Users/ASUS/Documents/Equipements/hist.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         chaine="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            chaine+=myString+"\n";

      }
      return chaine;
}
