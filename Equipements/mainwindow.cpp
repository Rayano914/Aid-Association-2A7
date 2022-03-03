#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_equipements_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_affiche_equipements_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(Equi.afficher());

}

void MainWindow::on_modifier_equipements_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_equipements_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_modifier_equipement_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id_equipement=ui->lineEdit_id_equi_modif->text().toInt();
        QString type_equipement=ui->lineEdit_type_modif->text();
        int prix=ui->lineEdit_prix_modif->text().toInt();
        int nombre=ui->lineEdit_nombre_modif->text().toInt();


        //Appel du constructeur parametré
        equipements E(id_equipement,type_equipement,prix,nombre);

        //controle de saisirs
            test=E.modifier();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->lineEdit_id_equi_modif->clear();
                ui->lineEdit_type_modif->clear();
                ui->lineEdit_prix_modif->clear();
                ui->lineEdit_nombre_modif->clear();


                //ui->tableView->setModel(Empl.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("OK"),
                         QObject::tr("Modification non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
            }
}

void MainWindow::on_supprimer_equipement_clicked()
{
    int id=ui->lineEdit_supprimer_equipement->text().toInt();
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet equipements definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::Yes)
        {
            bool test=Equi.supprimer(id);
            ui->tableView->setModel(Equi.afficher());

            if(test)//si requete executer ==>QMessageBox::information
            {
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else//si la requete non executer ==>QMessageBox::critical
            {
                QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                       QObject::tr("Suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
            }
        }
        else
        {
           qDebug()<<"Suppresion annulée!!";
        }
}

void MainWindow::on_ajouter_equipement_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id_equipement=ui->lineEdit_id_equipement->text().toInt();
        QString type_equipement=ui->lineEdit_type_equipement->text();
        int prix=ui->lineEdit_prix->text().toInt();
        int nombre=ui->lineEdit_nombre->text().toInt();


        //Appel du constructeur parametré
        equipements E(id_equipement,type_equipement,prix,nombre);

        //controle de saisirs
            test=E.ajouter();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->lineEdit_id_equipement->clear();
                ui->lineEdit_type_equipement->clear();
                ui->lineEdit_prix->clear();
                ui->lineEdit_nombre->clear();


                //ui->tableView->setModel(Empl.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("OK"),
                         QObject::tr("Ajout non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
            }

}










