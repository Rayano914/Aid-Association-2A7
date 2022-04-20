#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "activite.h"
#include "historique.h"
#include "QMessageBox"
#include <QDebug>
#include "QComboBox"
#include "QSqlQuery"
#include<QSqlQueryModel>
#include <QtGui>
#include "notif.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

activite act;

    ui->letypeoperation->addItem("activite");
       ui->letypeoperation->addItem("theatre");
       ui->tablecaisse_2->setModel(act.afficher());


       ui->stackedWidget->setCurrentIndex(1);
       //control de saisi
         ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));
         //ui->lineEdit_modif_id->setValidator(new QIntValidator(0, 99999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
      QRegExp rxNom(NOM_RX);
      QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
        ui->lemontant->setValidator(valiNom);
        ui->lemontant_2->setValidator(valiNom);
         historique h;
         ui->historique->setText(h.imp_hist());


   }
MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_fleche_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}






void MainWindow::on_supprimer_caisses_clicked()
{
    ui->comboBox_supprimer->clear();
        QSqlQuery qry;
            qry.prepare("select ID_ACTIVITE from activite");
            qry.exec();
            while(qry.next()){
            ui->comboBox_supprimer->addItem(qry.value(0).toString());
            }
        ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_ajoute_caisse_clicked()
{
    //recuperation des informations saises:
         int id_activite=ui->lineEdit->text().toInt();
         QString titre=ui->lemontant_2->text();
         QDate date_activite=ui->ledateoperation->date();
         QString localisation=ui->lemontant->text();
          QString type_activite=ui->letypeoperation->currentText();
     activite a (id_activite ,titre,date_activite ,localisation,type_activite);

          bool test=a.ajouter();
          QMessageBox msgBox;

            if(test)
              {
                historique h;
                h.save_txt(titre);
                ui->historique->setText(h.imp_hist());
                if (date_activite <QDate::currentDate())
                {

                    notif n ("date dépassé","vous avez ajouté une ancienne date");
                    n.afficher();
                }
                ui->lineEdit->clear();
                ui->lemontant->clear();
                msgBox.setText("Ajout avec succes.");
                ui->tablecaisse_2->setModel(a.afficher());
            }
            else
               { msgBox.setText("Echec d'ajout");}
                msgBox.exec();

}

void MainWindow::on_ajouter_caisses_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_supprimer_caisse_clicked()
{
    activite a;
        int id=ui->comboBox_supprimer->currentText().toInt();
            bool test=a.supprimer(id);
            QMessageBox msgBox;
            if(test)
               { msgBox.setText("Suppression avec succes.");
            ui->tablecaisse_2->setModel(a.afficher());
            }
            else
               { msgBox.setText("Echec de suppression");}
                msgBox.exec();
}

void MainWindow::on_tablecaisse_2_clicked(const QModelIndex &index)
{
    int id_activite=ui->tablecaisse_2->model()->data(index).toInt();
          activite a;



          a=a.SelectModif(id_activite);

          if(a.get_id()!=0)
          {

         ui->lineEdit->setText(QString(QString::number(a.get_id())));
         ui->ledateoperation->date();
         ui->letypeoperation->setCurrentText(a.get_type_activite());
         ui->lemontant->setText(QString (a.get_localisation()));
         ui->lemontant_2->setText(QString (a.get_titre()));

}
}

void MainWindow::on_modifier_caisse_2_clicked()
{
               int id_activite=ui->lineEdit->text().toInt();
               QString titre=ui->lemontant_2->text();
               QDate date_activite=ui->ledateoperation->date();
               QString type_activite=ui->letypeoperation->currentText();
               QString localisation=ui->lemontant->text();
               bool test=false;
               activite a(id_activite,titre,date_activite,localisation,type_activite);
               test=a.modifier(id_activite);

               if(test==true)
               {
                 QMessageBox::information(nullptr,QObject::tr("ok"),
                 QObject::tr("Modifier avec success\n""click ok to exit"),QMessageBox::Ok);
                 ui->tablecaisse_2->setModel(a.afficher()); //affichage automatique apres modification


               }
               else
               {

                       QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                       QObject::tr("modification non effectue\n""click cancel to exit"),QMessageBox::Cancel);

               }
                        ui->lineEdit->clear();
                        ui->lemontant_2->clear();
                        ui->ledateoperation->clear();
                        ui->lemontant->clear();

   }


void MainWindow::on_lineEdit_12_textEdited(const QString &arg1)
{activite a;
    QString arg=ui->lineEdit_12->text();
            ui->tablecaisse_2->setModel(a.rechercher(arg));
}

void MainWindow::on_modif_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_historique_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);}





void MainWindow::on_trier_clicked()
{
    activite act;
       QString a;
       if (ui->croissant->isChecked()) a="ASC";
       else if (ui->decroissant->isChecked()) a="DESC";

       // a="ASC" ou a="DESC"
       switch (ui->comboBox_Tri->currentIndex()) {
       case 0:
           ui->tablecaisse_2->setModel((act.Trititre(a)));
           break;
       case 1:
           ui->tablecaisse_2->setModel((act.Trilocalisation(a)));
           break;
       case 2:
           ui->tablecaisse_2->setModel((act.Tritype_act(a)));
           break;


       }
}

void MainWindow::on_comboBox_Tri_activated(const QString &arg1)
{

    activite act;
       QString a;
       if (ui->croissant->isChecked()) a="ASC";
       else if (ui->decroissant->isChecked()) a="DESC";

       // a="ASC" ou a="DESC"
       switch (ui->comboBox_Tri->currentIndex()) {
       case 0:
           ui->tablecaisse_2->setModel((act.Trititre(a)));
           break;
       case 1:
           ui->tablecaisse_2->setModel((act.Trilocalisation(a)));
           break;
       case 2:
           ui->tablecaisse_2->setModel((act.Tritype_act(a)));
           break;


       }
}

void MainWindow::on_historique_3_triggered(QAction *arg1)
{

}

void MainWindow::on_sms_clicked()
{
    QString link = "https://console.twilio.com/us1/develop/sms/try-it-out/send-an-sms?frameUrl=%2Fconsole%2Fsms%2Fget-setup%3F__override_layout__%3Dembed%26bifrost%3Dtrue%26x-target-region%3Dus1&currentFrameUrl=%2Fconsole%2Fsms%2Fgetting-started%2Fbuild%3F__override_layout__%3Dembed%26bifrost%3Dtrue%26x-target-region%3Dus1";
       QDesktopServices::openUrl(QUrl(link));
}
