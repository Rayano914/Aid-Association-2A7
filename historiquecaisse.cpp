#include "historiquecaisse.h"
#include <QSqlQuery>
historique::historique()
{

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
