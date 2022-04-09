#include "historique.h"
#include <QString>
#include <QDebug>
#include <QDate>
Historique::Historique()
{

}
void Historique::save_txt(QString cin, QString nom, QString prenom, QString age, QString type_maladie, QString rendez_vous, QString num_chambre, QString contact_famille)
{
    QFile file ("C:/Users/rayan/OneDrive/Bureau/Gestion_patientV2/historique.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out<<"Dernier Ajout\n";
         out << "cin: "+cin+"\nnom: "+nom+"\nprenom: "+prenom+"\nage: "+age+"\ntype_maladie: "+type_maladie+"\nRendez_vous: "+rendez_vous+"\num_chambre: "+num_chambre+"\nContact_famille: "+contact_famille<< "\n\n";
}

QString Historique::imp_hist()
{
    ch="";
       QFile file("C:/Users/rayan/OneDrive/Bureau/Gestion_patientV2/historique.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}

