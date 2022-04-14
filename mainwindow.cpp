#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipements.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDebug>
#include "historique.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);

    //control de saisi
        ui->lineEdit_id_equipement->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_prix->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_prix_modif->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_nombre_modif->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_nombre->setValidator(new QIntValidator(0, 99999999, this));
        #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
        QRegExp rxNom(NOM_RX);
        QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
        ui->lineEdit_type_modif->setValidator(valiNom);
        ui->lineEdit_type_equipement->setValidator(valiNom);
        historique hs;
        ui->historique->setText(hs.imprimer_hist());



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_equipements_clicked()
{
  combo();
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_affiche_equipements_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->tableView->setModel(Equi.afficher());
    QSqlQuery qry1;
    qry1.prepare("select * from equipement");
               qry1.exec();
               QStringList completionlist;
               while(qry1.next()){
                   completionlist <<qry1.value("id_equipement").toString()<<qry1.value("type_equipement").toString() <<qry1.value("prix").toString() <<qry1.value("nombre").toString()<<qry1.value("id_operation").toString()  ;


               }

               stringcompleter=new QCompleter(completionlist,this);
               stringcompleter->setCaseSensitivity(Qt::CaseInsensitive);
               ui->lineEdit_12->setCompleter(stringcompleter);



}

void MainWindow::on_modifier_equipements_clicked()
{
     combo();
    QSqlQuery qry;
        qry.prepare("select id_equipement from EQUIPEMENT");
        qry.exec();
        while(qry.next()){
        ui->lineEdit_id_equi_modif->addItem(qry.value(0).toString());
        }
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_equipements_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);
    combo();
}

void MainWindow::on_return_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_return_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_return_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_return_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_return_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_modifier_equipement_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id_equipement=ui->lineEdit_id_equi_modif->currentText().toInt();
        QString type_equipement=ui->lineEdit_type_modif->text();
        int prix=ui->lineEdit_prix_modif->text().toInt();
        int nombre=ui->lineEdit_nombre_modif->text().toInt();
         int id_operation=ui->id_operationmodif->currentText().toInt();


        //Appel du constructeur parametré
        equipements E(id_equipement,type_equipement,prix,nombre,id_operation);


            test=E.modifier();
            if(test)//si requete executer ==>QMessageBox::information
            {
                historique hs;
                hs.enregistrer_txt(ui->lineEdit_id_equi_modif->currentText(),type_equipement,ui->lineEdit_prix_modif->text(),ui->lineEdit_nombre_modif->text(),ui->id_operationmodif->currentText(),"Modif");
                ui->historique->setText(hs.imprimer_hist());
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
             combo();

}

void MainWindow::on_supprimer_equipement_clicked()
{

        int id_equipement=ui->supprimer_equipement_2->currentText().toInt();

        QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet equipements definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::Yes)
        {
            /*historique hs;
            hs.enregistrer_txt(ui->supprimer_equipement_2->currentText(),"","","","supprimer");
            ui->historique->setText(hs.imprimer_hist());*/
            bool test=Equi.supprimer(id_equipement);
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
        combo();
}

void MainWindow::on_ajouter_equipement_clicked()
{
    bool test=false;

        //Recuperation des informations saisies dans les 3 champs
        int id_equipement=ui->lineEdit_id_equipement->text().toInt();
        QString type_equipement=ui->lineEdit_type_equipement->text();
        int prix=ui->lineEdit_prix->text().toInt();
        int nombre=ui->lineEdit_nombre->text().toInt();
        int id_operation=ui->id_operationajout->currentText().toInt();


        //Appel du constructeur parametré
        equipements E(id_equipement,type_equipement,prix,nombre,id_operation);


            test=E.ajouter();
            if(test)//si requete executer ==>QMessageBox::information
            {
                historique hs;
                hs.enregistrer_txt(ui->lineEdit_id_equipement->text(),type_equipement,ui->lineEdit_prix->text(),ui->lineEdit_nombre->text(),ui->id_operationmodif->currentText(),"Ajout");
                ui->historique->setText(hs.imprimer_hist());
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
            //ui->id_operationajout->clear();
 combo();
}





void MainWindow::on_recherche_equipement_clicked()
{
    QString arg1=ui->lineEdit_12->text();
    if (arg1 == NULL)
        ui->tableView->setModel(Equi.afficher());
    else
     ui->tableView->setModel(Equi.rechercher(arg1));

}

void MainWindow::on_tri_prix_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Tri effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
       ui->tableView->setModel(Equi.tri_prix());
}

void MainWindow::on_tri_id_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Tri effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
       ui->tableView->setModel(Equi.tri_id());
}



void MainWindow::on_tri_nombre_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Tri effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
       ui->tableView->setModel(Equi.tri_nombre());
}


void MainWindow::on_historique_2_clicked()
{
      ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_lineEdit_id_equi_modif_currentIndexChanged(int index)
{
    index=0;
        int id_equipement=ui->lineEdit_id_equi_modif->currentText().toInt();
        QSqlQuery query;
        query.prepare("select *from equipement where id_equipement=:id_equipement");
        query.bindValue(":id_equipement",id_equipement);

        index++;

        if(query.exec())
        {
            while(query.next())
            {
                ui->lineEdit_type_modif->setText(query.value(1).toString());
                ui->lineEdit_prix_modif->setText(query.value(2).toString());
                ui->lineEdit_nombre_modif->setText(query.value(3).toString());

            }
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                   QObject::tr("Transfere de donnees Non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
}
void MainWindow::combo()
{
    ui->id_operationajout->clear();
     ui->id_operationmodif->clear();
      ui->supprimer_equipement_2->clear();
      ui->lineEdit_id_equi_modif->clear();
    QSqlQuery qry;
        qry.prepare("select ID_OPERATION from CAISSE");
        qry.exec();
        while(qry.next()){
        ui->id_operationajout->addItem(qry.value(0).toString());
         ui->id_operationmodif->addItem(qry.value(0).toString());

        }
        QSqlQuery qry2;
            qry2.prepare("select id_equipement from EQUIPEMENT");
            qry2.exec();
            while(qry2.next()){
            ui->supprimer_equipement_2->addItem(qry2.value(0).toString());

            }
}
