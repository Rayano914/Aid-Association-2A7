#include "gestion_patient.h"
#include "ui_gestion_patient.h"
#include "patient.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QUrl>
#include "connection.h"
#include "historique.h"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <QPoint>
#include <utility>
#include <QPdfWriter>
#include <QPainter>
#include <QPointF>
#include <QPicture>
#include <QtGui>
#include <QVariant>
#include <QAbstractEventDispatcher>
#include <QDir>
#include <QSurfaceFormat>
#include "qrcode.h"

using std::int8_t;
using std::uint8_t;
using std::size_t;
using std::vector;
using namespace ::qrcodegen;


const QString RESULTS_PATH = "C:/Users/rayan/OneDrive/Bureau/Gestion_patientV2/Qrcode/";
const QString RESULTS_PATH2 = "C:/Users/rayan/OneDrive/Bureau/Gestion_patientV2/auto_QRcode/";

Gestion_patient::Gestion_patient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion_patient)
{
    ui->setupUi(this);

    ui->lecin->setValidator(new QIntValidator(0,99999999,this));
     ui->lenumchambre->setValidator(new QIntValidator(0,9999,this));
      ui->lecontact->setValidator(new QIntValidator(0,99999999,this));
     selected="";
connection c;
c.createconnect();

     QStringList CompletionList;

     QSqlQuery query;
     query.prepare("SELECT CIN,NOM_PATIENT,PRENOM_PATIENT,AGE,RENDEZ_VOUS,TYPE_MALADIE,NUM_CHAMBRE,CONTACT_FAMILLE FROM PATIENT");
     query.exec();

     while(query.next()) {
          CompletionList  << query.value("NOM_PATIENT").toString()<<query.value("PRENOM_PATIENT").toString()<<query.value("CIN").toString()<<query.value("TYPE_MALADIE").toString();
     }

     StringCompleter = new QCompleter(CompletionList,this);
     StringCompleter->setCaseSensitivity(Qt::CaseSensitive);
     ui->lineEdit_12->setCompleter(StringCompleter);


}

Gestion_patient::~Gestion_patient()
{
    delete ui;
}





void Gestion_patient::on_calendrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Gestion_patient::on_add_patient_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Gestion_patient::on_dispaly_patients_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
        ui->tableView->setModel(p.afficher_patient());
}

void Gestion_patient::on_update_patients_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);
    connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
}

void Gestion_patient::on_delete_patients_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_sup->setModel(modal);

}

void Gestion_patient::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Gestion_patient::on_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Gestion_patient::on_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Gestion_patient::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Gestion_patient::on_ajoute_pati_clicked()
{const QString RESULTS_PATH2 = "C:/Users/rayan/OneDrive/Bureau/Gestion_patientV2/auto_QRcode/";
    QDir().rmpath(RESULTS_PATH2);
    QDir().mkpath(RESULTS_PATH2);
    int cin=ui->lecin->text().toInt();
    int age=ui->leage->text().toInt();
    int num_chambre=ui->lenumchambre->text().toInt();
    int contact_famille=ui->lecontact->text().toInt();
    QString nom=ui->lenom->text();
    QString prenom=ui->leprenom->text();
    QString type_maladie=ui->comboBox_2->currentText();
QString dateR=ui->dateEdit->date().toString();
   QDate rendez_vous=ui->dateEdit->date();
//QDate rendez_vous =ui->calendarAjout->selectedDate();
   patient P(cin,nom,prenom,num_chambre,rendez_vous,type_maladie,age,contact_famille);

 //QString nomimg=nom+".PNG";

   QString QR="Nom \t "+nom+"Prenom \t"+prenom+"Date Rendez_vous\t"+dateR;
QString date=ui->dateEdit->text();

        QMessageBox msgbox;

        Historique h;
      h.save_txt(ui->lecin->text(),ui->lenom->text(),ui->leprenom->text(),ui->leage->text(),type_maladie,date,ui->lenumchambre->text(),ui->lecontact->text());
      ui->historique->setText(h.imp_hist());
        int erreur=0;

                if(!P.chaine_Valid(nom)||nom=="")
                erreur=1;
                if(P.DateValide(rendez_vous))
                erreur=2;
                if(!P.chaine_Valid(prenom)||prenom=="")
                erreur=3;

                switch(erreur)
                {
                case 1:
                msgbox.setText("Le nom doit être composé seulement par des lettres !");
                break;
                case 2:
                msgbox.setText("La date doit être suppérieur à la date actuel !");
                break;
                case 3:
                msgbox.setText("Le nom doit être composé seulement par des lettres !");
                break;

                }
                if(erreur==0){

 bool test=P.ajouter_patient();
        if(test)
        {

          ui->lecin->clear();
          ui->lenom->clear();
          ui->leprenom->clear();
          ui->lecontact->clear();
          ui->lenumchambre->clear();

          QrCode qr = QrCode::encodeText(QR.toUtf8().constData(), QrCode::Ecc::HIGH);
          QString nomimg=nom+".PNG";

          // Read the black & white pixels
          QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
          for (int y = 0; y < qr.getSize(); y++) {
              for (int x = 0; x < qr.getSize(); x++) {
                  int color = qr.getModule(x, y);  // 0 for white, 1 for black

                  // You need to modify this part
                  if(color==0)
                      im.setPixel(x, y,qRgb(254, 254, 254));
                  else
                      im.setPixel(x, y,qRgb(0, 0, 0));
              }
          }
          im=im.scaled(100,100);
          im.save(RESULTS_PATH2 + nomimg,"PNG");


         ui->Qr->setPixmap(QPixmap::fromImage(im));

            msgbox.setText("Ajout avec succes.");
           ui->tableView->setModel(P.afficher_patient());

           Historique h;
         h.save_txt(ui->lecin->text(),ui->lenom->text(),ui->leprenom->text(),ui->leage->text(),type_maladie,date,ui->lenumchambre->text(),ui->lecontact->text());
         ui->historique->setText(h.imp_hist());
        }
        else
            msgbox.setText("Echec d'ajout");


                }
                msgbox.exec();
                 //ui->stackedWidget->setCurrentIndex(3);


}

void Gestion_patient::on_comboBox_sup_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_sup->currentText();
    connection c;


    QSqlQuery qry;
    qry.prepare("select * from patient where cin='"+cin+"'");
    if(qry.exec()){
      while(qry.next()){
       ui->lenom3->setText(qry.value(1).toString());
       ui->leprenom3->setText(qry.value(2).toString());




      }
    }

    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

}

void Gestion_patient::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox->currentText();
    connection c;


    QSqlQuery qry;
    qry.prepare("select * from patient where cin='"+cin+"'");
    if(qry.exec()){
      while(qry.next()){
       ui->lenom2->setText(qry.value(1).toString());
       ui->leprenom2->setText(qry.value(2).toString());
       ui->leage2->setText(qry.value(3).toString());
       ui->dateEdit_2->setDate(qry.value(4).toDate());
       ui->comboBox_3->setCurrentText(qry.value(5).toString());
       ui->lenum_chambre2->setText(qry.value(6).toString());
       ui->lecontact2->setText(qry.value(7).toString());


      }
    }

    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

}

void Gestion_patient::on_modifier_pati_clicked()
{
    patient P;

    QMessageBox msg;

P.setcin(ui->comboBox->currentText().toInt());
    P.setage(ui->leage2->text().toInt());
    P.setnum_chambre(ui->lenum_chambre2->text().toInt());
    P.setcontact_famille(ui->lecontact2->text().toInt());
P.setprenom(ui->leprenom2->text());
P.setnom(ui->lenom2->text());

P.settype_maladie(ui->comboBox_3->currentText());
P.setrendez_vous(ui->dateEdit_2->date());

bool test=P.modifier_patient();


    if(test)
    {
       msg.setText("modification avec succès");
       ui->stackedWidget->setCurrentIndex(3);

        ui->tableView->setModel(P.afficher_patient());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void Gestion_patient::on_supprimer_patient_clicked()
{
    int cin=ui->comboBox_sup->currentText().toInt();

   bool test=p.supprimer_patient(cin);


    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("supprimer avec succée");
    ui->tableView->setModel(p.afficher_patient());

    // Put the focus back into the input box so they can type again:
    ui->comboBox_sup->setFocus();

    }

    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
    ui->stackedWidget->setCurrentIndex(3);
}

void Gestion_patient::on_lineEdit_12_textChanged(const QString &arg1)
{
     ui->tableView->setModel(p.search(arg1));
}

void Gestion_patient::on_toolButton_2_clicked()
{
    QString nom = ui->lineEdit_12->text();
    ui->tableView->setModel(p.search(nom));
}

void Gestion_patient::on_toolButton_5_clicked()
{
    QString l=ui->comboBox_4->currentText();
    ui->tableView->setModel(p.trier(l));
}

void Gestion_patient::on_toolButton_clicked()
{

    QString l=ui->comboBox_4->currentText();
    ui->tableView->setModel(p.trierdesc(l));
}


void Gestion_patient::on_toolButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Gestion_patient::on_toolButton_4_clicked()
{   int cin=ui->lecin->text().toInt();
    int age=ui->leage->text().toInt();
    int num_chambre=ui->lenumchambre->text().toInt();
    int contact_famille=ui->lecontact->text().toInt();
    QString nom=ui->lenom->text();
    QString prenom=ui->leprenom->text();
    QString type_maladie=ui->comboBox_2->currentText();

   QDate rendez_vous=ui->dateEdit->date();
//QDate rendez_vous =ui->calendarAjout->selectedDate();
   patient P(cin,nom,prenom,num_chambre,rendez_vous,type_maladie,age,contact_famille);


QString date=ui->dateEdit->text();

        QMessageBox msgbox;

        Historique h;
      h.save_txt(ui->lecin->text(),ui->lenom->text(),ui->leprenom->text(),ui->leage->text(),type_maladie,date,ui->lenumchambre->text(),ui->lecontact->text());
      ui->historique->setText(h.imp_hist());
    ui->stackedWidget->setCurrentIndex(1);
}

void Gestion_patient::on_calendarAjout_clicked(const QDate &rendez_vous)
{
   ui->calendarAjout->selectedDate();
}





void Gestion_patient::on_qrCode_clicked()
{
    QDir().rmpath(RESULTS_PATH);
    QDir().mkpath(RESULTS_PATH);
    int tabeq=ui->tableView->currentIndex().row();
                       QVariant cinn=ui->tableView->model()->data(ui->tableView->model()->index(tabeq,0));
                       QString cin=cinn.toString();
                      // QString code=idd.toSTring();
                       QSqlQuery qry;
                       qry.prepare("select * from patient where cin=:cin");
                       qry.bindValue(":cin",cin);
                       qry.exec();

                        QString nom,prenom,type_maladie;//attributs
                        int age,num_chambre,contact_famille;
                        QString rendez_vous;

                      while(qry.next()){

                          cin=qry.value(0).toString();
                           nom=qry.value(1).toString();
                            prenom=qry.value(2).toString();
                           age=qry.value(3).toInt();
                            rendez_vous=qry.value(4).toString();
                        type_maladie=qry.value(5).toString();
                            num_chambre=qry.value(6).toInt();
                             contact_famille=qry.value(7).toInt();
                          ;


                       }
                      //const QString RESULTS_PATH = "C:/Users/rayan/OneDrive/Bureau/codeqryahya/";
                      const QString RESULTS_PATH = "C:/Users/rayan/OneDrive/Bureau/Gestion_patientV2/Qrcode/";
                       cin=QString(cin);
                       QString R="Cin \t"+cin+"Nom \t "+nom+"Prenom \t"+prenom+"age\t"+age+"Date Rendez_vous\t"+rendez_vous;



        //cin="CIN:\t" +cin+ "NOM\t:" +nom+ "age:\t" +age+ "num_chambre:\t" +num_chambre+ "contact_famille:\t" +contact_famille+ "Rendez_vous:\t" +rendez_vous ;

        cin="CODE:\t" +cin+ "NOM\t:" +nom+ "prenom:\t" +prenom+ "age:\t" +age+ "type_maladie:\t" +type_maladie+ "num_chambre:\t" +num_chambre + "contact:\t" +contact_famille ;

                       QrCode qr = QrCode::encodeText(R.toUtf8().constData(), QrCode::Ecc::HIGH);
                       QString nomimg=nom+".PNG";

                       // Read the black & white pixels
                       QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
                       for (int y = 0; y < qr.getSize(); y++) {
                           for (int x = 0; x < qr.getSize(); x++) {
                               int color = qr.getModule(x, y);  // 0 for white, 1 for black

                               // You need to modify this part
                               if(color==0)
                                   im.setPixel(x, y,qRgb(254, 254, 254));
                               else
                                   im.setPixel(x, y,qRgb(0, 0, 0));
                           }
                       }
                       im=im.scaled(100,100);
                       im.save(RESULTS_PATH + nomimg,"PNG");


                      ui->qrcode->setPixmap(QPixmap::fromImage(im));
}

void Gestion_patient::on_calendarAjout_selectionChanged()
{
    ui->dateEdit->setDate(ui->calendarAjout->selectedDate());
}

void Gestion_patient::on_pushButton_clicked()
{

    QPdfWriter pdf("C:Users\\rayan\\OneDrive\\Bureau\\Gestion_patientV2\\patient.pdf");


                    QPainter painter(&pdf);
                    //painter.begin(&pdf);

                    //QImage image("C:\\Users\\MSI\\OneDrive\\Bureau\\yahyav3\\images\\logo_c++-1.png");
                   // painter.drawImage(15,15,image);

                     painter.setPen(Qt::red);
                     painter.setFont(QFont("Time New Roman", 25));
                     painter.drawText(3200,1400,"Patient");
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Time New Roman", 15));
                     painter.setFont(QFont("Time New Roman", 9));
                                      painter.drawText(400,3800,"CIN: ");

                                      painter.drawText(400,4650,"NOM_Patient : ");

                                      painter.drawText(400,5600,"PRENOM_PATIENT: ");

                                      painter.drawText(400,6550,"AGE: ");

                                      painter.drawText(400,7500,"RENDEZ_VOUS: ");

                                      painter.drawText(400,8450,"TYPE_MALADIE:");
                                      painter.drawText(400,8450,"NUM_CHAMBRE:");
                                          painter.drawText(400,8450,"CONTACT_FAMILLE:");

                                      painter.drawText(7800,10100,"Signature");
                                      painter.drawText(8150,10300,".");

                     painter.drawRect(100,3000,9400,9000);

                     QSqlQuery query;
                     int cin=ui->comboBox_pdf->currentText().toInt();
                     //int id=ui->le_id_4->currentText().toInt();
                     query.prepare("SELECT * FROM patient WHERE cin= :cin");
                     query.bindValue(":cin", cin);
                     //query.prepare("select  ID_LIVR,NOM_LIVREUR,DATE_LIVRAISON,REF_CMD,NOM_CL,ADR_CL FROM livraisons NATURAL JOIN COMMANDES where ID_LIVR=:ID_LIVR");   //on supprime  where ID_LIVR=:ID_LIVR si tout livraisins
                     //query.bindValue(":ID_LIVR", id);
                     query.exec();

                     query.next();
                                      painter.drawText(800,3800,query.value(0).toString());
                                      painter.drawText(1550,4650,query.value(1).toString());
                                      painter.drawText(1750,5600,query.value(2).toString());
                                      painter.drawText(1600,6550,query.value(3).toString());
                                      painter.drawText(1400,7500,query.value(4).toString());
                                      painter.drawText(1700,8450,query.value(5).toString());
                                      painter.drawText(1700,8450,query.value(6).toString());
                                      painter.drawText(1700,8450,query.value(7).toString());



                     QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                     QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_patient::on_calendarWidget_selectionChanged()
{ QDate date;

    date=ui->calendarWidget->selectedDate();

    ui->dateEdit_C->setDate(ui->calendarWidget->selectedDate());

//ui->tablC->setModel(p.afficher_patient());

QString m=date.toString();
ui->tablC->setModel(p.afficher_C(date));
ui->tablC->setModel(p.afficher_C2());

}

void Gestion_patient::on_addButton_clicked()
{
    QDate r=ui->dateEdit_C->date();
   // ui->tablC->setModel(p.afficher_C(r));
}

void Gestion_patient::on_pushButton_2_clicked()
{ ui->stackedWidget->setCurrentIndex(7);
    connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_pdf->setModel(modal);
}

void Gestion_patient::on_comboBox_pdf_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_pdf->currentText();
}

void Gestion_patient::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
