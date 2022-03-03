#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QMessageBox"
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



void MainWindow::on_ajouter_empl_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_affiche_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(Empl.afficher());

}

void MainWindow::on_modifier_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouter_employer_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id=ui->lineEdit_id_emp->text().toInt();
        QString nom=ui->lineEdit_nom_emp->text();
        QString prenom=ui->lineEdit_prenom_emp->text();
        QString mail=ui->lineEdit_mail_emp->text();
        QString spec=ui->lineEdit_spec_emp->text();

        //Appel du constructeur parametré
        Employe E(id,nom,prenom,mail,spec);

        //controle de saisirs
            test=E.ajouter();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->lineEdit_id_emp->clear();
                ui->lineEdit_nom_emp->clear();
                ui->lineEdit_prenom_emp->clear();
                ui->lineEdit_mail_emp->clear();
                ui->lineEdit_spec_emp->clear();


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

void MainWindow::on_modifier_employer_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id=ui->lineEdit_id_modif->text().toInt();
        QString nom=ui->lineEdit_nom_modif->text();
        QString prenom=ui->lineEdit_prenom_modif->text();
        QString mail=ui->lineEdit_mail_modif->text();
        QString spec=ui->lineEdit_spec_modif->text();

        //Appel du constructeur parametré
        Employe E(id,nom,prenom,mail,spec);

        //controle de saisirs
            test=E.modifier();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->lineEdit_id_modif->clear();
                ui->lineEdit_nom_modif->clear();
                ui->lineEdit_prenom_modif->clear();
                ui->lineEdit_mail_modif->clear();
                ui->lineEdit_spec_modif->clear();

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

void MainWindow::on_supprimer_employe_clicked()
{
    int id=ui->lineEdit_supprimer_emp->text().toInt();
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet employe definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::Yes)
        {
            bool test=Empl.supprimer(id);
            ui->tableView->setModel(Empl.afficher());

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
