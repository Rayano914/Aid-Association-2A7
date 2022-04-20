#include "historique.h"

historique::historique()
{

}
void historique:: save_txt(QString titre )
{
    QFile file ("C:/Users/asus/Desktop/activitee/historique.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+titre<< "\n";
}
QString historique::imp_hist()
{
    ch="";
       QFile file("C:/Users/asus/Desktop/activitee/historique.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}
