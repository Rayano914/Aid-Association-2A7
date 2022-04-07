#include "historique.h"

historique::historique()
{

}
void historique:: save_txt(QString id ,QString type,QString date,QString montant,QString details ,QString genre)
{
    QFile file ("C:/Users/asus/Desktop/Gestion_Caisse/historique.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
        out << "id: "+id+"\ntype: "+type+"\ndate: "+date+"\nmontant: "+montant+"\ndetails: "+details+"\n"+genre << "\n\n" ;
}
QString historique::imp_hist()
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
