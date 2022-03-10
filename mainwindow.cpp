#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "activite.h"
#include "QMessageBox"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);



    //control de saisi
        ui->lineEdit_id_act_modif->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_id_activite->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_supprimer_activite->setValidator(new QIntValidator(0, 99999999, this));
        //ui->dateEdit->setValidator(new QIntValidator(0, 99999999, this));
       // ui->dateEdit_2->setValidator(new QIntValidator(0, 99999999, this));

        #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
        QRegExp rxNom(NOM_RX);
        QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
        ui->lineEdit_localisation_modif->setValidator(valiNom);
        ui->lineEdit_localisation->setValidator(valiNom);
        ui->lineEdit_titre_modif->setValidator(valiNom);
        ui->lineEdit_titre_activite->setValidator(valiNom);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_activite_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_affiche_activites_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(act.afficher());

}

void MainWindow::on_modifier_activite_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_activite_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_modifier_activites_clicked()
{  int id_activite=ui->lineEdit_id_act_modif->text().toInt();
    QString titre=ui->lineEdit_titre_modif->text();
    QDate date_activite=ui->dateEdit_2->date();
    QString localisation=ui->lineEdit_localisation_modif->text();
    QString type_activite=ui->lineEdit_type_activite_modif->text();

    bool test=false;


    activite a(id_activite,titre,date_activite,localisation,type_activite);

    ui->lineEdit_id_act_modif->setEnabled(true);
    test=a.modifier(id_activite);



    if(test==true)
    {
     // qDebug()<<"connection reussite";
        ui->lineEdit_id_act_modif->setEnabled(false);
      QMessageBox::information(nullptr,QObject::tr("ok"),
                               QObject::tr("Modifier avec success\n""click ok to exit"),QMessageBox::Ok);
      //ui->tableView->setModel(a.afficher());

      //ui->LE_cin->clear();
      //ui->LE_nom->clear();


      //ui->pushButton_6->setEnabled(false);
    }
    else
    {
            ui->lineEdit_id_act_modif->setEnabled(false);

            QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                     QObject::tr("modification non effectue\n""click cancel to exit"),QMessageBox::Cancel);






    }
}


void MainWindow::on_supprimer_activites_clicked()
{
    int id=ui->lineEdit_supprimer_activite->text().toInt();
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet equipements definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::Yes)
        {
            bool test=act.supprimer(id);
            ui->tableView->setModel(act.afficher());

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

void MainWindow::on_ajouter_activites_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id_activite=ui->lineEdit_id_activite->text().toInt();
        QString titre =ui->lineEdit_titre_activite->text();
        QDate date_activite=ui->dateEdit->date();
        QString localisation=ui->lineEdit_localisation->text();
        QString type_activite=ui->lineEdit_type_activite->text();



        //Appel du constructeur parametré
        activite a(id_activite,titre,date_activite,localisation,type_activite);


            test=a.ajouter();
            if(test)//si requete executer ==>QMessageBox::information
            {
                ui->lineEdit_id_activite->clear();
                ui->lineEdit_titre_activite->clear();
                ui->dateEdit->clear();
                ui->lineEdit_localisation->clear();
                ui->lineEdit_type_activite->clear();

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











void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}
