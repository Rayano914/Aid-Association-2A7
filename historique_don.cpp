#include "historique_don.h"

historique_don::historique_don()
{

}
void historique_don:: save_txt(QString id ,QString nom,QString prenom,QString type,QString mail)
{
    QFile file ("C:/Users/Malek Ayedi/Desktop/gestion_don/hist.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+id+"\ntype: "+nom+"\nprix: "+prenom+"\nnombre: "+type+"\n"+mail << "\n";
}
QString historique_don::hist()
{
    ch="";
       QFile file("C:/Users/Malek Ayedi/Desktop/gestion_don/hist.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}
