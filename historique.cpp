#include "historique.h"

historique::historique()
{

}
void historique:: enregistrer_txt(QString id ,QString type,QString prix,QString nombre,QString id_operation,QString genre)
{
    QFile file ("C:/Users/ASUS/Documents/Equipements/hist.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+id+"\ntype: "+type+"\nprix: "+prix+"\nnombre: "+nombre+"\nid_operation: "+id_operation+"\n"+genre << "\n\n" ;
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
