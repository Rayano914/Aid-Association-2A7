#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "QMessageBox"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox->addItem("Directeur");
    ui->comboBox->addItem("Trésorier");
    ui->comboBox->addItem("Responsable Logistiques");
    ui->comboBox->addItem("Responsable Patients");

    ui->comboBox_2->addItem("Directeur");
    ui->comboBox_2->addItem("Trésorier");
    ui->comboBox_2->addItem("Responsable Logistiques");
    ui->comboBox_2->addItem("Responsable Patients");

    //control de saisi
    ui->lineEdit_id_emp->setValidator(new QIntValidator(0, 99999999, this));
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->lineEdit_nom_emp->setValidator(valiNom);
    ui->lineEdit_prenom_emp->setValidator(valiNom);
    ui->lineEdit_nom_modif->setValidator(valiNom);
    ui->lineEdit_prenom_modif->setValidator(valiNom);
    ui->comboBox_sup->setModel(Empl.afficherValeur("id_employe"));
    ui->comboBox_modif->setModel(Empl.afficherValeur("id_employe"));
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
void MainWindow::on_mailing_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouter_employer_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id=ui->lineEdit_id_emp->text().toInt();
        QString nom=ui->lineEdit_nom_emp->text();
        QString prenom=ui->lineEdit_prenom_emp->text();
        QString spec = ui->comboBox->currentText();
        QString mail=ui->lineEdit_mail_emp->text();


        //Appel du constructeur parametré
        Employe E(id,nom,prenom,spec,mail);

        //controle de saisirs

            test=E.ajouter();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->lineEdit_id_emp->clear();
                ui->lineEdit_nom_emp->clear();
                ui->lineEdit_prenom_emp->clear();
                ui->lineEdit_mail_emp->clear();


                //ui->tableView->setModel(Empl.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
                ui->comboBox_sup->setModel(Empl.afficherValeur("id_employe"));
                ui->comboBox_modif->setModel(Empl.afficherValeur("id_employe"));
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
        int id=ui->comboBox_modif->currentText().toInt();
        QString nom=ui->lineEdit_nom_modif->text();
        QString prenom=ui->lineEdit_prenom_modif->text();       
        QString spec = ui->comboBox_2->currentText();
        QString mail=ui->lineEdit_mail_modif->text();

        //Appel du constructeur parametré
        Employe E(id,nom,prenom,mail,spec);

        //efface
            test=E.modifier();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->comboBox_modif->clear();
                ui->lineEdit_nom_modif->clear();
                ui->lineEdit_prenom_modif->clear();
                ui->lineEdit_mail_modif->clear();



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
    //int id=ui->lineEdit_supprimer_emp->text().toInt();
    int id=ui->comboBox_sup->currentText().toInt();
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet employe definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::Yes)
        {
            bool test=Empl.supprimer(id);
            ui->tableView->setModel(Empl.afficher());

            if(test)//si requete executer ==>QMessageBox::information
            {
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
                ui->comboBox_sup->setModel(Empl.afficherValeur("id_employe"));
                 ui->comboBox_modif->setModel(Empl.afficherValeur("id_employe"));

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

//alter table employe add constraint ck_mail check(mail like '%@%.%');

void MainWindow::on_toolButton_pdf_clicked()
{
    bool test = Empl.telechargerPDF();
    if(test)
    {
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:\\Users\\Ghada\\Desktop\\TEST.pdf"));

        }
        if (reponse == QMessageBox::No)
        {

        }
    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("PDF non enregistré.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}


void MainWindow::on_toolButton_recherche_employe_clicked()
{
    QString arg1=ui->lineEdit_recherche_emp->text();
        ui->tableView->setModel(Empl.rechercher(arg1));
}


