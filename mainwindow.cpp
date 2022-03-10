#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "caisse.h"
#include "QMessageBox"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->lineEdit_modif_type->addItem("Revenue");
    ui->lineEdit_modif_type->addItem("Depense");
    ui->letypeoperation->addItem("Revenue");
    ui->letypeoperation->addItem("Depense");

    ui->stackedWidget->setCurrentIndex(1);
    //control de saisi
      ui->leidoperation->setValidator(new QIntValidator(0, 99999999, this));
      ui->lineEdit_modif_id->setValidator(new QIntValidator(0, 99999999, this));
      ui->lemontant->setValidator(new QIntValidator(0, 99999999, this));
      ui->lineEdit_modif_montant->setValidator(new QIntValidator(0, 99999999, this));  

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fleche_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouter_caisses_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_afficher_caisses_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
     ui->tablecaisse->setModel(c.afficher());
}


void MainWindow::on_modifier_caisses_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_supprimer_caisses_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_ajoute_caisse_clicked()
{
    //recuperation des informations saises:
     int id_operation=ui->leidoperation->text().toInt();
     QString date_operation=ui->ledateoperation->text();
      QString type_operation=ui->letypeoperation->currentText();
      int montant=ui->lemontant->text().toInt();
      caisse c (id_operation,date_operation,type_operation,montant);
      bool test=c.ajouter();
      QMessageBox msgBox;

        if(test)
          {
            ui->leidoperation->clear();
            ui->lemontant->clear();
            msgBox.setText("Ajout avec succes.");
            ui->tablecaisse->setModel(c.afficher());
        }
        else
           { msgBox.setText("Echec d'ajout");}
            msgBox.exec();


}

void MainWindow::on_supprimer_caisse_clicked()
{
    caisse c; c.setid_operation(ui->leidoperation_2->text().toInt());
        bool test=c.supprimer(c.getid_operation());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->tablecaisse->setModel(c.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}
            msgBox.exec();
}





void MainWindow::on_modifier_caisse_clicked()
{
    {
        bool test=false;


            int id_operation=ui->lineEdit_modif_id->text().toInt();
            QString date_operation=ui->lineEdit_modif_date->text();
            QString type_operation=ui->lineEdit_modif_type->currentText();
            int montant=ui->lineEdit_modif_montant->text().toInt();


            //Appel du constructeur parametré
            caisse c(id_operation,date_operation,type_operation,montant);


                test=c.modifier();
                if(test)//si requete executer ==>QMessageBox::information
                {
                    ui->lineEdit_modif_id->clear();
                    ui->lineEdit_modif_date->clear();
                    ui->lineEdit_modif_type->clear();
                    ui->lineEdit_modif_montant->clear();


                    //ui->tableView->setModel(c.afficher());
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

                }
                else
                {
                    QMessageBox::critical(nullptr, QObject::tr("OK"),
                             QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
                }
    }
}
