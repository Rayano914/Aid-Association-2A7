#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "don.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   ui->setupUi(this);
    ui->letypedon->addItem("Select");
    ui->letypedon->addItem("equipement");
    ui->letypedon->addItem("argent");
    ui->letypedon2->addItem("Select");
    ui->letypedon2->addItem("equipement");
    ui->letypedon2->addItem("argent");
    ui->leid->setValidator(new QIntValidator(0, 99999999, this));
    ui->leid2->setValidator(new QIntValidator(0, 99999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->lenomdonateur2->setValidator(valiNom);
    ui->leprenomdonateur2->setValidator(valiNom);
    ui->lenomdonateur->setValidator(valiNom);
    ui->leprenomdonateur->setValidator(valiNom);
    ui->letypedon->setValidator(valiNom);
    ui->letypedon2->setValidator(valiNom);
    ui->stackedWidget->setCurrentIndex(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_dons_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_afficher_dons_clicked()
{
don d;
    ui->stackedWidget->setCurrentIndex(2);
     ui->tableView->setModel(d.afficher_don());
}

void MainWindow::on_modifier_dons_clicked()
{
    QSqlQuery qry;
    qry.prepare("select ID_DON from DON");
    qry.exec();
    while(qry.next()){
    ui->leid2->addItem(qry.value(0).toString());
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_dons_clicked()
{
        QSqlQuery qry;
        qry.prepare("select ID_DON from DON");
        qry.exec();
        while(qry.next()){
        ui->leidsupp->addItem(qry.value(0).toString());
        }
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajoute_don_clicked()
{
    int id_don=ui->leid->text().toInt();
    QString nom_donateur=ui->lenomdonateur->text();
    QString prenom_donateur=ui->leprenomdonateur->text();
    QString type_donateur=ui->letypedon->currentText();
   QString mail_donateur=ui->lemaildonateur->text();

   don d(id_don,nom_donateur,prenom_donateur,type_donateur,mail_donateur);
bool test=d.ajouter_don();
test=true;
   if ((id_don==0) || (nom_donateur=="") || (prenom_donateur=="")|| (mail_donateur=="")|| (ui->letypedon->currentIndex ()==0))
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Champs vides!!\n""Click Cancel to exit."),QMessageBox::Cancel);
               test=false;
           }





        QMessageBox msgbox;
        if(test)
        {msgbox.setText("Ajout avec succes.");
           ui->tableView->setModel(d.afficher_don());
           ui->leid->clear();
              ui->lenomdonateur->clear();
              ui->leprenomdonateur->clear();
              ui->letypedon->clear();
              ui->lemaildonateur->clear();


        }
        else
            msgbox.setText("Echec d'ajout");

        msgbox.exec();
         ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_supprimer_don_clicked()
{
    don d;

    int id_don=ui->leidsupp->currentText().toInt();
   bool test=d.supprimer_don(id_don);


    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("supprimer avec succée");
    ui->tableView->setModel(d.afficher_don());

    // Put the focus back into the input box so they can type again:
    ui->leidsupp->setFocus();

    }

    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}



void MainWindow::on_modifier_don_clicked()
{
    don d;

    QMessageBox msg;

 d.setid_don(ui->leid2->currentText().toInt());

d.setprenom_donateur(ui->leprenomdonateur2->text());
d.setnom_donateur(ui->lenomdonateur2->text());
d.settype_don(ui->letypedon2->currentText());
d.setmail_donateur(ui->lemaildonateur2->text());


bool test=d.modifier_don(d.getid_don());


    if(test)
    {
        msg.setText("modification avec succès");
        ui->tableView->setModel(d.afficher_don());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

