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
    //ui->stackedWidget->setCurrentIndex(1);
    ui->tablecaisse->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_afficher_clicked()
{
 ui->tablecaisse->setModel(c.afficher());
}

void MainWindow::on_ajoute_caisse_clicked()
{
    int id_operation=ui->leidoperation->text().toInt();
    int date_operation=ui->ledateoperation->text().toInt();
      QString type_operation=ui->letypeoperation->text();
      int montant=ui->lemontant->text().toInt();
      caisse c (id_operation,date_operation,type_operation,montant);
      bool test=c.ajouter();
      QMessageBox msgBox;

        if(test)
          {  msgBox.setText("Ajout avec succes.");
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
