#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "activites.h"
#include "QMessageBox"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->stackedWidget->setCurrentIndex(1);
    ui->table_activite->setModel(act.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_act_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_affiche_act_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    //ui->tableView->setModel(act.afficher());

}

void MainWindow::on_modifier_act_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_act_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_clicked()
{
    //ui->stackedWidget->setCurrentIndex(0);
    ui->table_activite->setModel(act.afficher());
}

void MainWindow::on_ajouteractivite_clicked()
{
    int id_activite=ui->LE_ID->text().toInt();
      QString titre=ui->LE_TITRE->text();
      int date_activite=ui->LE_DATE->text().toInt();
      QString localisation =ui->LE_LOCALISATION->text();
      QString type_activite=ui->LE_TYPE->text();
      activite a (id_activite,titre,date_activite,localisation,type_activite);

bool test=a.ajouter();
QMessageBox msgBox;

  if(test)
    {  msgBox.setText("Ajout avec succes.");
      ui->table_activite->setModel(a.afficher());
  }
  else
     { msgBox.setText("Echec d'ajout");}
      msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    activite a;
    a.setid_activite(ui->LE_ID->text().toInt());
        bool test=a.supprimer(a.getid_activite());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->table_activite->setModel(a.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}
            msgBox.exec();
}

void MainWindow::on_supprimer_employe_clicked()
{
    activite a;
    a.setid_activite(ui->lineEdit_supprimer_emp->text().toInt());
        bool test=a.supprimer(a.getid_activite());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->table_activite->setModel(a.afficher());

        }
        else
           { msgBox.setText("Echec de suppression");}
            msgBox.exec();
}
