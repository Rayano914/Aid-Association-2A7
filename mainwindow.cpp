#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "login.h"
#include "QMessageBox"
#include <QDebug>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlQuery>
#include "mail/SmtpMime"
#include <QFileDialog>
#include <QStringList>
#include <QSqlQueryModel>
#include <QDateTime>
#include <QTimer>
#include "historique.h"
#include <QSystemTrayIcon>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include<QGraphicsView>
#include <QtGui>
#include "caisse.h"
#include "notif.h"
#include "qrcode.h"
#include "patient.h"
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSystemTrayIcon>

constexpr int MAX = 1000000;
using std::int8_t;
using std::uint8_t;
using std::size_t;
using std::vector;
using namespace ::qrcodegen;
const QString RESULTS_PATH = "C:/Users/rayan/Downloads/Aid-Association_integration/Aid-Association-2A7-main/auto_QRcode";
const QString RESULTS_PATH2 = "C:/Users/rayan/Downloads/Aid-Association_integration/Aid-Association-2A7-main/auto_QRcode";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    activite act;
           ui->stackedWidget->setCurrentIndex(6);
        ui->letypeoperation->addItem("activite");
           ui->letypeoperation->addItem("theatre");
           ui->tableactivite_2->setModel(act.afficher());
           ui->stackedWidget->setCurrentIndex(1);
           ui->stackedWidget_2->setCurrentIndex(1);
           ui->stackedWidget_4->setCurrentIndex(1);
           ui->stackedWidget_3->setCurrentIndex(1);

           //control de saisi
             ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));
             //ui->lineEdit_modif_id->setValidator(new QIntValidator(0, 99999999, this));
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
          QRegExp rxNom(NOM_RX);
          QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
            ui->lemontant->setValidator(valiNom);
            ui->lemontant_2->setValidator(valiNom);
             historique h;
             ui->historique->setText(h.imp_hist());

   // timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()),this,SLOT(myfunction()));
    //timer->start(1000);
    mScene = new Duscene(this);
    ui->graphicsView->setScene(mScene);
    ui->letypedon->addItem("Select");
    ui->letypedon->addItem("equipement");
    ui->letypedon->addItem("argent");
    ui->letypedon2->addItem("Select");
    ui->letypedon2->addItem("equipement");
    ui->letypedon2->addItem("argent");
    ui->leid->setValidator(new QIntValidator(0, 99999999, this));
    ui->leid2->setValidator(new QIntValidator(0, 99999999, this));
    ui->lenomdonateur2->setValidator(valiNom);
    ui->leprenomdonateur2->setValidator(valiNom);
    ui->lenomdonateur->setValidator(valiNom);
    ui->leprenomdonateur->setValidator(valiNom);
    ui->letypedon->setValidator(valiNom);
    ui->letypedon2->setValidator(valiNom);
    ui->stackedWidget->setCurrentIndex(1);
    historique hs;
    ui->hist->setText(hs.hist());
    mSocket= new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&]()
    {
        QTextStream T(mSocket);
        auto text =T.readAll();
        ui->textEdit->append(text);
    });
    /*int ret=A.connect_arduino();
switch (ret) {
case(0):qDebug() << "arduino is available and connected to :" << A.getarduino_port_name();
    break;
case(1):qDebug() << "arduino is available but not connected to :" << A.getarduino_port_name();
    break;
case(-1):qDebug() << "arduino is not available ";

}
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/


    ui->stackedWidget_3->setCurrentIndex(1);

    //control de saisi
        ui->lineEdit_id_equipement->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_prix->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_prix_modif->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_nombre_modif->setValidator(new QIntValidator(0, 99999999, this));
        ui->lineEdit_nombre->setValidator(new QIntValidator(0, 99999999, this));
        #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
        ui->lineEdit_type_modif->setValidator(valiNom);
        ui->lineEdit_type_equipement->setValidator(valiNom);
        historique hist;
        ui->historique->setText(hist.imprimer_hist());

    ui->stackedWidget->setCurrentIndex(6);
    ui->comboBox->addItem("Select");
    ui->comboBox->addItem("Directeur");
    ui->comboBox->addItem("tresorier");
    ui->comboBox->addItem("Responsable Logistiques");
    ui->comboBox->addItem("Responsable Patients");

    ui->comboBox_2->addItem("Select");
    ui->comboBox_2->addItem("Directeur");
    ui->comboBox_2->addItem("tresorier");
    ui->comboBox_2->addItem("Responsable Logistiques");
    ui->comboBox_2->addItem("Responsable Patients");

    //control de saisi
    ui->lineEdit_age->setValidator(new QIntValidator(0, 65, this));
    ui->lineEdit_age_modif->setValidator(new QIntValidator(20, 65, this));
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
    ui->lineEdit_nom_emp->setValidator(valiNom);
    ui->lineEdit_prenom_emp->setValidator(valiNom);
    ui->lineEdit_nom_modif->setValidator(valiNom);
    ui->lineEdit_prenom_modif->setValidator(valiNom);
    ui->comboBox_sup->setModel(Empl.afficherValeur("id_employe"));
    ui->comboBox_modif->setModel(Empl.afficherValeur("id_employe"));
    ui->comboBox_dest_1->setModel(Empl.afficherValeur("mail"));
    ui->comboBox_dest_2->setModel(Empl.afficherValeur("mail"));
    ui->comboBox_dest_3->setModel(Empl.afficherValeur("mail"));
    ui->comboBox_cin->setModel(Empl.afficherValeur("id_employe"));
    ui->comboBox_un->setModel(Empl.afficherValeur("nom_utilisateur"));
    ui->comboBox_un1->setModel(Empl.afficherValeur("nom_utilisateur"));
        QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",
                              QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_mail_emp->setValidator(new QRegularExpressionValidator(rx, this));
    ui->lineEdit_mail_modif->setValidator(new QRegularExpressionValidator(rx, this));

    n=0;
    cp=0;
    t=10;
    ui->letypeoperation1->addItem("Revenue");
    ui->letypeoperation1->addItem("Depense");
    ui->letypeoperation_21->addItem("Revenue");
    ui->letypeoperation_21->addItem("Depense");
    ui->ledetails1->addItem("Dons");
    ui->ledetails1->addItem("Adherents");
    ui->ledetails1->addItem("Depense");
    ui->ledetails_21->addItem("Dons");
    ui->ledetails_21->addItem("Adherents");
    ui->ledetails_21->addItem("Depense");
    ui->tablecaisse_2->setModel(c.afficher());
    // ui->calculatrice->setModel(c.calculatrice());
    ui->leidoperation_21->setModel(c.showid());
    ui->stackedWidget->setCurrentIndex(2);
    //control de saisi
      ui->leidoperation1->setValidator(new QIntValidator(0, 999999, this));
      //ui->lineEdit_modif_id->setValidator(new QIntValidator(0, 99999999, this));
      ui->lemontant1->setValidator(new QIntValidator(0, 999999, this));
      ui->historique_caisse->setText(h.imp());
        QSqlQuery qry1;
      qry1.prepare("select * from caisse");
      qry1.exec();
      QStringList completionlist;
      while(qry1.next()){
      completionlist <<qry1.value("id_operation").toString()<<qry1.value("type_operation").toString() <<qry1.value("montant").toString()<<qry1.value("details").toString();


                      }

                      stringcompleter=new QCompleter(completionlist,this);
                      stringcompleter->setCaseSensitivity(Qt::CaseInsensitive);
                     ui->lineEdit_20->setCompleter(stringcompleter);
                     /*int ret=A.connect_arduino(); // lancer la connexion à arduino
                         switch(ret){
                         case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                             break;
                         case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                            break;
                         case(-1):qDebug() << "arduino is not available";
                         }
                          QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(verif()));*/
                                ui->stackedWidget->setCurrentIndex(6);




ui->historique_6->setText(h.imp_hist_p());

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
    QSqlQuery qry1;
        qry1.prepare("select * from EMPLOYE");
                   qry1.exec();
                   QStringList completionlist;
                   while(qry1.next()){
                       completionlist <<qry1.value("id_employe").toString()<<qry1.value("nom").toString() <<qry1.value("prenom").toString()<<qry1.value("specialite").toString()<<qry1.value("age").toString();

                             }

                   stringcompleter=new QCompleter(completionlist,this);
                   stringcompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit_recherche_emp->setCompleter(stringcompleter);

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
    bool test=true;

        //Recuperation des informations saisies dans les 3 champs

        QString id=ui->lineEdit_id_emp->text();
        QString nom=ui->lineEdit_nom_emp->text();
        QString prenom=ui->lineEdit_prenom_emp->text();
        QString spec = ui->comboBox->currentText();
        QString mail=ui->lineEdit_mail_emp->text();
        int age=ui->lineEdit_age->text().toInt();
        if(!mail.contains(QRegExp("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$")))

        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("mail invalide\n""Click Cancel to exit."),QMessageBox::Cancel);
        test=false;
}


        //Appel du constructeur parametré

        else if ((id=="") || (nom=="") || (prenom=="") ||(age==0) || (ui->comboBox->currentIndex ()==0))
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("Champs vides!!\n""Click Cancel to exit."),QMessageBox::Cancel);
            test=false;
        }
        else if(id.length()!=8)
        {
            test=false;
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("!!\n""Verifier longueur de CIN"),QMessageBox::Cancel);
        }


            if(test)//si requete executer ==>QMessageBox::information
            {
                Employe E(id,nom,prenom,spec,mail,age);

                E.ajouter();
                ui->lineEdit_id_emp->clear();
                ui->lineEdit_nom_emp->clear();
                ui->lineEdit_prenom_emp->clear();
                ui->lineEdit_mail_emp->clear();
                ui->lineEdit_age->clear();



                //ui->tableView->setModel(Empl.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
                ui->comboBox_sup->setModel(Empl.afficherValeur("id_employe"));
                ui->comboBox_modif->setModel(Empl.afficherValeur("id_employe"));
                ui->comboBox_dest_1->setModel(Empl.afficherValeur("mail"));
                ui->comboBox_dest_2->setModel(Empl.afficherValeur("mail"));
                ui->comboBox_dest_3->setModel(Empl.afficherValeur("mail"));
            }

}

void MainWindow::on_modifier_employer_clicked()
{
    bool test=true;
        //Recuperation des informations saisies dans les 3 champs
        QString id=ui->comboBox_modif->currentText();
        QString nom=ui->lineEdit_nom_modif->text();
        QString prenom=ui->lineEdit_prenom_modif->text();       
        QString spec = ui->comboBox_2->currentText();
        QString mail=ui->lineEdit_mail_modif->text();
        int age=ui->lineEdit_age_modif->text().toInt();

        //Appel du constructeur parametré
        Employe E(id,nom,prenom,spec,mail,age);

        if ((nom=="") || (prenom=="")|| (mail=="")|| (age==0) || (ui->comboBox_2->currentIndex ()==0))
        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("Champs vides!!\n""Click Cancel to exit."),QMessageBox::Cancel);
            test=false;
        }
        else if(!mail.contains(QRegExp("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$")))

        {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                     QObject::tr("mail invalide\n""Click Cancel to exit."),QMessageBox::Cancel);
        test=false;
}



        //efface

            if(test)//si requete executer ==>QMessageBox::information
            {
                E.modifier();
                ui->comboBox_modif->clear();
                ui->lineEdit_nom_modif->clear();
                ui->lineEdit_prenom_modif->clear();
                ui->lineEdit_mail_modif->clear();
                ui->lineEdit_age_modif->clear();




                //ui->tableView->setModel(Empl.afficher());
                QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("Modification effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

            }

}

void MainWindow::on_supprimer_employe_clicked()
{
    //int id=ui->lineEdit_supprimer_emp->text().toInt();
    QString id=ui->comboBox_sup->currentText();
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
//alter table employe add constraint ck_mail check(mail like '%@%.%');




void MainWindow::on_comboBox_modif_currentIndexChanged(int index)
{
    index=0;
    QString id_employe=ui->comboBox_modif->currentText();
    QSqlQuery query;
    query.prepare("select *from employe where id_employe=:id_employe");
    query.bindValue(":id_employe",id_employe);

    index++;

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_nom_modif->setText(query.value(1).toString());
            ui->lineEdit_prenom_modif->setText(query.value(2).toString());
            ui->lineEdit_mail_modif->setText(query.value(4).toString());
            ui->comboBox_2->setCurrentText(query.value(3).toString());
            ui->lineEdit_age_modif->setText(query.value(6).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("Transfere de donnees Non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}
//*************************************MAILING********************************************************

QStringList MainWindow::getRecipientsAddress(QString str)
{

   QStringList recipients;

   recipients = str.split(QRegExp(";"));

   return recipients;
}
void MainWindow::on_toolButton_attach_1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach1->setText(fileName);
}

void MainWindow::on_toolButton_attach_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach2->setText(fileName);
}

void MainWindow::on_toolButton_attach_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach3->setText(fileName);
}

void MainWindow::on_envoyer_mail_clicked()
{

QString email_stmp="smtp.gmail.com", email_user="sejourbeau42@gmail.com" , email_pass="beausejour20";
int email_port =465;

                SmtpClient smtp(email_stmp, email_port, SmtpClient::SslConnection);

                smtp.setUser(email_user);
                smtp.setPassword(email_pass);

                MimeMessage message;

                EmailAddress sender(email_user, "Beau Sejour");
                message.setSender(&sender);

                //create list of to
                QStringList to = getRecipientsAddress(ui->comboBox_dest_1->currentText());
                QStringList cc = getRecipientsAddress(ui->comboBox_dest_2->currentText());
                QStringList bcc = getRecipientsAddress(ui->comboBox_dest_3->currentText());

                for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
                     message.addRecipient(new EmailAddress(*it),MimeMessage::To);
                }
                for (QStringList::iterator it = cc.begin();it != cc.end(); ++it) {
                     message.addRecipient(new EmailAddress(*it),MimeMessage::Cc);
                }
                for (QStringList::iterator it = bcc.begin();it != bcc.end(); ++it) {
                     message.addRecipient(new EmailAddress(*it),MimeMessage::Bcc);
                }

                //set message subject
                message.setSubject(ui->objet_mail->text());

                MimeText text;
                text.setText(ui->message_mail->document()->toPlainText());
                message.addPart(&text);

                MimeAttachment attachment1(new QFile(ui->le_emailAttach1->text()));
                MimeAttachment attachment2(new QFile(ui->le_emailAttach2->text()));
                MimeAttachment attachment3(new QFile(ui->le_emailAttach3->text()));

                //attachments
                if(ui->le_emailAttach1->text() != NULL){
                   message.addPart(&attachment1);
                }

                if(ui->le_emailAttach2->text() != NULL){
                    message.addPart(&attachment2);
                }

                if(ui->le_emailAttach3->text() != NULL){
                    message.addPart(&attachment3);
                }

                 if (!smtp.connectToHost()) {
                     QMessageBox::critical(this,"Failed to connect","Cannot connect to host");
                 }

                 if (!smtp.login()) {
                     QMessageBox::critical(this,"Failed to connect","Failed to login");
                 }

                 smtp.sendMail(message);

                 QMessageBox::information(this,"Email Send","Operation completed succesfully!");


                 smtp.quit();

             ui->le_emailAttach1->clear();
             ui->le_emailAttach2->clear();
             ui->le_emailAttach3->clear();
             ui->objet_mail->clear();
             ui->message_mail->clear();
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

void MainWindow::on_return_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_login_clicked()
{
    QString nom_utilisateur = ui->lineEdit_surnom->text();
    QString mdp = ui->lineEdit_mdp->text();
int test = C.Authentification(nom_utilisateur,mdp);
        if(test)
        {
            QMessageBox::information(this,"Welcome !!","Bonne Journee !!");
            ui->stackedWidget->setCurrentIndex(test);
            ui->lineEdit_surnom->clear();
            ui->lineEdit_mdp->clear();
        }
        else

        {
            QMessageBox::critical(this,"AUTHENTIFICATION ECHOUE","MOT DE PASSE/LOGIN INCORRECTES!");

        }


}

void MainWindow::on_affiche_emp_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajouter_empl_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouter_empl_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_ajouter_empl_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_ajouter_empl_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_mdp_oublier_clicked()
{
     QMessageBox::warning(this,"Mot de passe oublié","Pour recuperer votre mot de passe \n Veuillez contacter votre Directeur!");
}

void MainWindow::on_mailing_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_mailing_4_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}

void MainWindow::on_mailing_3_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}

void MainWindow::on_affiche_emp_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_return_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_return_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_return_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}



void MainWindow::on_login_7_clicked()
{
    QString nom_utilisateur=ui->comboBox_un1->currentText();
    SmtpClient smtp("smtp.gmail.com",465, SmtpClient::SslConnection);
    smtp.setUser("sejourbeau42@gmail.com");
    smtp.setPassword("beausejour20");

    std::srand(std::time(nullptr));

    long rand_code;
    rand_code = rand() % MAX;
    l.set_code(QString::number(rand_code));

    MimeMessage message;

    EmailAddress sender("sejourbeau42@gmail.com","BEAU SEJOUR");
    message.setSender(&sender);

    QStringList to = getRecipientsAddress("ghada.eladeb@esprit.tn");

    for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
         message.addRecipient(new EmailAddress(*it),MimeMessage::To);
    }

    //set message subject
    message.setSubject("CODE DE REINITIALISATION MOT DE PASSE");

    MimeText text;
    QString messagetext = "Le Code de reinitialisation du login avec USERNAME: " ;
    messagetext=messagetext+nom_utilisateur+" est: "+l.get_code();
    text.setText(messagetext);
    message.addPart(&text);

     if (!smtp.connectToHost()) {
         QMessageBox::critical(this,"Failed to connect","Cannot connect to host");
     }

     if (!smtp.login()) {
         QMessageBox::critical(this,"Failed to connect","Failed to login");
     }

     if(smtp.sendMail(message))
     {
         QMessageBox::information(this,"Code de validation","Un code a été envoyer par mail à l'administrateur du system\nVeuillez remplir ce code dans l'espace pour reinitialiser le mot de passe!");
     }
     else
     {
         QMessageBox::critical(this,"ERREURS","Veuillez contacter le developpeur de l'application");
     }

     smtp.quit();
}

void MainWindow::on_login_9_clicked()
{
    QString nom_utilisateur=ui->comboBox_un->currentText();
    QString mdp_anc=ui->lineEdit_mdp_anc->text();
    QString mdp=ui->lineEdit_mdp_nv->text();
    QString mdp_nvconf=ui->lineEdit_mdp_nvconf->text();
    //QString query="select mdp from EMPLOYE where nom_utilisateur=:nom_utilisateur";
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYE SET MDP=:mdp_nvconf where NOM_UTILISATEUR=:nom_utilisateur AND MDP=:mdp");
    query.bindValue(":nom_utilisateur",nom_utilisateur);
    query.bindValue(":mdp",mdp_anc);
    query.bindValue(":mdp_nvconf",mdp_nvconf);
    bool test=query.exec();



        if (test)
                    {
                        QMessageBox::information(nullptr, QObject::tr("success"),QObject::tr("nouveau mot de passe effectué"), QMessageBox::Cancel);
                        ui->lineEdit_mdp_anc->clear();
                        ui->lineEdit_mdp_nv->clear();
                        ui->lineEdit_mdp_nvconf->clear();
                    }
                    else QMessageBox::critical(nullptr,"error","wronginfo");
}


void MainWindow::on_login_4_clicked()
{
    QString nom_utilisateur=ui->lineEdit_surnom_3->text();
    QString mdp=ui->lineEdit_mdp_ajout->text();
    QString code=ui->lineEdit_code->text();
    QString id_employe=ui->comboBox_cin->currentText();

        l.set_nom_utilisateur(nom_utilisateur);
        l.set_mdp(mdp);


        if(code==l.get_code())
        {
            ui->lineEdit_code->clear();
            if(l.ajouterLogin(id_employe))
            {
                ui->comboBox_un->setModel(Empl.afficherValeur("nom_utilisateur"));
                ui->comboBox_un1->setModel(Empl.afficherValeur("nom_utilisateur"));
                ui->lineEdit_surnom_3->clear();
                ui->lineEdit_mdp_ajout->clear();
                ui->lineEdit_mdp_conf_ajouter->clear();
                QMessageBox::information(this,"Succes","Ajout avec succes");
            }
            else
            {
                QMessageBox::critical(this,"NOT OK","Echec de création du Login");
            }

        }
        else
        {
           QMessageBox::critical(this,"Code Erronné"," Verifier le code à nouveau ou cliquer sur 'ENVOYER CODE' pour recevoir un nouveau code!");

        }
}

void MainWindow::on_login_10_clicked()
{
    QString code=ui->lineEdit_code_12->text();
    QString nom_utilisateur=ui->comboBox_un1->currentText();
    QString mdp=nom_utilisateur+QString::number(rand() % 3000);
    QString message="Le nouveau mot de passe du compte est: "+mdp;

    l.set_nom_utilisateur(nom_utilisateur);
    l.set_mdp(mdp);

    if(code==l.get_code())
    {
        //ui->code_rein->clear();

        if(l.modifierLogin())
        {
            QMessageBox::information(this,"REINITIALISATION REUSSIE",message);
            ui->lineEdit_code_12->clear();


        }

    }
    else
    {
        QMessageBox::critical(this,"Code Erronné","Verifier le code à nouveau ou cliquer sur 'ENVOYER CODE' pour recevoir un nouveau code!");
        //ui->code_rein->clear();
    }
}

void MainWindow::on_envoyer_code_ajouter_clicked()
{
    QString nom_utilisateur=ui->lineEdit_surnom_3->text();
    QString mdp=ui->lineEdit_mdp_ajout->text();
    QString password=ui->lineEdit_mdp_conf_ajouter->text();

    if(mdp==password)
    {
        SmtpClient smtp("smtp.gmail.com",465, SmtpClient::SslConnection);
        smtp.setUser("sejourbeau42@gmail.com");
        smtp.setPassword("beausejour20");

        std::srand(std::time(nullptr));

        l.set_code(QString::number(rand() % MAX));

        MimeMessage message;

        EmailAddress sender("sejourbeau42@gmail.com","BEAU SEJOUR");
        message.setSender(&sender);

        QStringList to = getRecipientsAddress("ghada.eladeb@esprit.tn");

        for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
             message.addRecipient(new EmailAddress(*it),MimeMessage::To);
        }

        //set message subject
        message.setSubject("CODE DE VALIDATION D'AJOUT DE LOGIN");

        MimeText text;
        QString messagetext = "Le Code de validation du login avec USERNAME: " ;
        messagetext=messagetext+nom_utilisateur+" est: "+l.get_code();
        text.setText(messagetext);
        message.addPart(&text);

         if(!smtp.connectToHost()) {
             QMessageBox::critical(this,"Failed to connect","Cannot connect to host");
         }

         if(!smtp.login()) {
             QMessageBox::critical(this,"Failed to connect","Failed to login");
         }

         if(smtp.sendMail(message))
         {
              QMessageBox::information(this,"Valider le code","Veuillez renseigner le champs code avec le code envoyer par mail!");
         }
         else
         {
             QMessageBox::critical(this,"Erreurs","Veuillez contacter le developpeur de l'application");
         }

         smtp.quit();

    }
    else
    {
        QMessageBox::critical(this,"Failed to connect","Code different");
    }
}

void MainWindow::on_mailing_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
void MainWindow::myfunction()
{
  QTime time= QTime::currentTime();
  QString time_text=time.toString("hh : mm : ss");
  ui->label_date->setText(time_text);
}

void MainWindow::on_mailing_8_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}

void MainWindow::on_mailing_10_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}

void MainWindow::on_mailing_11_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}
/************************************************EQUIPEMENT******************************************************/

void MainWindow::on_ajouter_equipements_clicked()
{
  combo();
    ui->stackedWidget_3->setCurrentIndex(0);

}

void MainWindow::on_affiche_equipements_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->tableView_3->setModel(Equi.afficher());
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
    ui->stackedWidget_3->setCurrentIndex(3);
}

void MainWindow::on_supprimer_equipements_clicked()
{

    ui->stackedWidget_3->setCurrentIndex(4);
    combo();
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
                historique hist;
                hist.enregistrer_txt(ui->lineEdit_id_equi_modif->currentText(),type_equipement,ui->lineEdit_prix_modif->text(),ui->lineEdit_nombre_modif->text(),ui->id_operationmodif->currentText(),"Modif");
                ui->historique->setText(hist.imprimer_hist());
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
                historique hist;
                //hs.enregistrer_txt(ui->lineEdit_id_equipement->text(),type_equipement,ui->lineEdit_prix->text(),ui->lineEdit_nombre->text(),ui->id_operationmodif->currentText(),"Ajout");
                //ui->historique->setText(hs.imprimer_hist());
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
        ui->tableView_3->setModel(Equi.afficher());
    else
     ui->tableView_3->setModel(Equi.rechercher(arg1));

}

void MainWindow::on_tri_prix_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Tri effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
       ui->tableView_3->setModel(Equi.tri_prix());
}

void MainWindow::on_tri_id_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Tri effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
       ui->tableView_3->setModel(Equi.tri_id());
}



void MainWindow::on_tri_nombre_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
             QObject::tr("Tri effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
       ui->tableView_3->setModel(Equi.tri_nombre());
}


void MainWindow::on_historique_2_clicked()
{
      ui->stackedWidget_3->setCurrentIndex(5);
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

void MainWindow::on_return_22_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_return_18_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}


void MainWindow::on_return_19_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}


void MainWindow::on_return_20_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}


void MainWindow::on_return_21_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_affiche_emp_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_affiche_emp_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);

}

void MainWindow::on_affiche_emp_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void MainWindow::on_affiche_emp_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}
/************************************************DONS******************************************************************/

 void MainWindow::update_label()
{
   data= A.read_from_arduino();
   QString temp="";
   QString bpm="";
   qDebug()<<data;
   QString DataAsString = QString(data);
   QString numstring="";
       for (int i = 0; i < DataAsString.length(); ++i) {


           if (DataAsString.at(i).isDigit()){
                numstring =numstring+QString::number(DataAsString.at(i).digitValue());
           }}
       for(int i = 0; i < numstring.length(); ++i)
       {
           if(i<2)
               temp=temp+numstring.at(i);
           else
               bpm=bpm+numstring.at(i);
       }
       if(bpm.toInt()>=200)
       { QMessageBox::critical(this,res,"le bpm de "+res+" est sup à 71 !!!");}
       ui->temp_d->setText(temp);
       ui->bpm_d->setText(bpm);
}
void MainWindow::on_ajouter_dons_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_afficher_dons_clicked()
{
don d;
    ui->stackedWidget_4->setCurrentIndex(2);
     ui->tableView_4->setModel(d.afficher_don());
}

void MainWindow::on_modifier_dons_clicked()
{
    QSqlQuery qry;
    qry.prepare("select ID_DON from DON");
    qry.exec();
    while(qry.next()){
    ui->leid2->addItem(qry.value(0).toString());
    }
    ui->stackedWidget_4->setCurrentIndex(3);
}

void MainWindow::on_supprimer_dons_clicked()
{
        QSqlQuery qry;
        qry.prepare("select ID_DON from DON");
        qry.exec();
        while(qry.next()){
        ui->leidsupp->addItem(qry.value(0).toString());
        }
    ui->stackedWidget_4->setCurrentIndex(4);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}


void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_retour_3_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_retour_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
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
historique hs;
hs.save_txt(ui->leid->text(),nom_donateur,prenom_donateur,type_donateur,mail_donateur);
ui->historique_3->setText(hs.hist());
   if ((id_don==0) || (nom_donateur=="") || (prenom_donateur=="")|| (mail_donateur=="")|| (ui->letypedon->currentIndex ()==0))
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Champs vides!!\n""Click Cancel to exit."),QMessageBox::Cancel);
               test=false;
           }





        QMessageBox msgbox;
        if(test)
        {msgbox.setText("Ajout avec succes.");
           ui->tableView_4->setModel(d.afficher_don());
           ui->leid->clear();
              ui->lenomdonateur->clear();
              ui->leprenomdonateur->clear();
              ui->letypedon->clear();
              ui->lemaildonateur->clear();


        }
        else
            msgbox.setText("Echec d'ajout");

        msgbox.exec();
         ui->stackedWidget_4->setCurrentIndex(2);

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
    ui->tableView_4->setModel(d.afficher_don());

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
        ui->tableView_4->setModel(d.afficher_don());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}
void MainWindow::on_trier_clicked()
{ don d;
    QString choix = ui->tri->currentText();
        if (choix =="ID" ){
            ui->tableView_4->setModel(d.triID());
        }else if(choix=="type") {

            ui->tableView_4->setModel(d.tritype());

    }else if(choix=="nom") {
            ui->tableView_4->setModel(d.trinom());
        }
}
void MainWindow::on_rech_textChanged(const QString &arg1)
{
    don d;
     ui->tableView_4->setModel(d.search(arg1));
}

void MainWindow::on_retour_5_clicked()
{
     ui->stackedWidget_4->setCurrentIndex(1);
}



void MainWindow::on_hist_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(5);
}

void MainWindow::on_chatbox_clicked()
{
ui->stackedWidget_4->setCurrentIndex(6);
}

void MainWindow::on_connecter_clicked()
{
    mSocket->connectToHost("localhost",3333);
}

void MainWindow::on_pushButton_clicked()
{
    QTextStream T(mSocket);
    T << ui->username->text()<<": "<<ui->line_message->text();
    mSocket->flush();
    ui->line_message->clear();
}

void MainWindow::on_retour_6_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_chatbox_2_clicked()
{
     ui->stackedWidget_4->setCurrentIndex(7);
}

void MainWindow::on_modifier_don_2_clicked()
{
    res="";
    don d;
    QString cin=ui->lineard->text();
    res=d.searchcin(cin);
    qDebug()<<res;
    if (res!="false")
    {
        A.write_to_arduino(res);

    }
}

void MainWindow::on_retour_7_clicked()
{
      ui->stackedWidget_4->setCurrentIndex(1);
}
/************************************************ACTIVITES******************************************************************/

void MainWindow::on_affiche_emp_16_clicked()
{
   ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_affiche_emp_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_supprimer_activites_clicked()
{
       ui->comboBox_supprimer->clear();
        QSqlQuery qry;
            qry.prepare("select ID_ACTIVITE from activite");
            qry.exec();
            while(qry.next()){
            ui->comboBox_supprimer->addItem(qry.value(0).toString());
            }
        ui->stackedWidget_2->setCurrentIndex(4);
}

void MainWindow::on_ajouter_activite_clicked()
{
    //recuperation des informations saises:
         int id_activite=ui->lineEdit->text().toInt();
         QString titre=ui->lemontant_2->text();
         QDate date_activite=ui->ledateoperation->date();
         QString localisation=ui->lemontant->text();
          QString type_activite=ui->letypeoperation->currentText();
     activite a (id_activite ,titre,date_activite ,localisation,type_activite);

          bool test=a.ajouter();
          QMessageBox msgBox;

            if(test)
              {
                historique h;
                h.save(titre);
                ui->historique_5->setText(h.imp_hist());
                if (date_activite <QDate::currentDate())
                {

                    notif n ("date dépassé","vous avez ajouté une ancienne date");
                    n.afficher();
                }
                ui->lineEdit->clear();
                ui->lemontant->clear();
                msgBox.setText("Ajout avec succes.");
                ui->tableactivite_2->setModel(a.afficher());
            }
            else
               { msgBox.setText("Echec d'ajout");}
                msgBox.exec();

}

void MainWindow::on_ajouter_activites_clicked()
{
  ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_supprimer_activite_clicked()
{
    activite a;
        int id=ui->comboBox_supprimer->currentText().toInt();
            bool test=a.supprimer(id);
            QMessageBox msgBox;
            if(test)
               { msgBox.setText("Suppression avec succes.");
            ui->tableactivite_2->setModel(a.afficher());
            }
            else
               { msgBox.setText("Echec de suppression");}
                msgBox.exec();
}

void MainWindow::on_tableactivite_2_clicked(const QModelIndex &index)
{
    int id_activite=ui->tableactivite_2->model()->data(index).toInt();
          activite a;

          a=a.SelectModif(id_activite);

          if(a.get_id()!=0)
          {

         ui->lineEdit->setText(QString(QString::number(a.get_id())));
         ui->ledateoperation->date();
         ui->letypeoperation->setCurrentText(a.get_type_activite());
         ui->lemontant->setText(QString (a.get_localisation()));
         ui->lemontant_2->setText(QString (a.get_titre()));

}
}

void MainWindow::on_modifier_activite_clicked()
{
               int id_activite=ui->lineEdit->text().toInt();
               QString titre=ui->lemontant_2->text();
               QDate date_activite=ui->ledateoperation->date();
               QString type_activite=ui->letypeoperation->currentText();
               QString localisation=ui->lemontant->text();
               bool test=false;
               activite a(id_activite,titre,date_activite,localisation,type_activite);
               test=a.modifier(id_activite);

               if(test==true)
               {
                 QMessageBox::information(nullptr,QObject::tr("ok"),
                 QObject::tr("Modifier avec success\n""click ok to exit"),QMessageBox::Ok);
                 ui->tableactivite_2->setModel(a.afficher()); //affichage automatique apres modification
                 if (date_activite <QDate::currentDate())
                 {

                     notif n ("evenemnt à venir","vous avez un evénemnt bientot");
                     n.afficher();
                 }               }
               else
               {

                       QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                       QObject::tr("modification non effectue\n""click cancel to exit"),QMessageBox::Cancel);

               }
                        ui->lineEdit->clear();
                        ui->lemontant_2->clear();
                        ui->ledateoperation->clear();
                        ui->lemontant->clear();

   }


void MainWindow::on_lineEdit_13_textEdited(const QString &arg1)
{activite a;
    QString arg=ui->lineEdit_13->text();
    ui->tableactivite_2->setModel(a.rechercher(arg));
}

void MainWindow::on_modifier_activites_clicked()
{
       ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_historique_3_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(5);}

void MainWindow::on_comboBox_Tri_activated(const QString &arg1)
{

    activite act;
       QString a;
       if (ui->croissant->isChecked()) a="ASC";
       else if (ui->decroissant->isChecked()) a="DESC";

       // a="ASC" ou a="DESC"
       switch (ui->comboBox_Tri->currentIndex()) {
       case 0:
           ui->tableactivite_2->setModel((act.Trititre(a)));
           break;
       case 1:
           ui->tableactivite_2->setModel((act.Trilocalisation(a)));
           break;
       case 2:
           ui->tableactivite_2->setModel((act.Tritype_act(a)));
           break;


       }
}


void MainWindow::on_sms_clicked()
{
    QString link = "https://console.twilio.com/us1/develop/sms/try-it-out/send-an-sms?frameUrl=%2Fconsole%2Fsms%2Fget-setup%3F__override_layout__%3Dembed%26bifrost%3Dtrue%26x-target-region%3Dus1&currentFrameUrl=%2Fconsole%2Fsms%2Fgetting-started%2Fbuild%3F__override_layout__%3Dembed%26bifrost%3Dtrue%26x-target-region%3Dus1";
       QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_mailing_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_mailing_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_mailing_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}
/********************************************************************************************************************************************/

void MainWindow::on_btn_clicked()
{
data=A.read_from_arduino();


int o=data.toInt();
qDebug() << "read2: " << 0;
bool v=c.rechercher_id(o);
if(v)
{
    ui->label_14->setText("id trouve");
    A.write_to_arduino("o");

}
else
{
      ui->label_14->setText("id non trouve");
      A.write_to_arduino("f");
}
ui->label_16 ->setText(data);
}
void MainWindow::on_ajouter_caisses_clicked()
{
ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::on_afficher_caisses_clicked()
{
ui->stackedWidget_5->setCurrentIndex(2);
 ui->tablecaisse_2->setModel(c.afficher());
 QSqlQuery qry1;
qry1.prepare("select * from caisse");
qry1.exec();
QStringList completionlist;
while(qry1.next()){
completionlist <<qry1.value("id_operation").toString()<<qry1.value("type_operation").toString() <<qry1.value("montant").toString()<<qry1.value("details").toString();


               }

              // stringcompleter=new QCompleter(completionlist,this);
               //stringcompleter->setCaseSensitivity(Qt::CaseInsensitive);
              //ui->lineEdit_12->setCompleter(stringcompleter);
}




void MainWindow::on_supprimer_caisses_clicked()
{
ui->comboBox_supprimer->clear();
QSqlQuery qry;
    qry.prepare("select ID_OPERATION from caisse");
    qry.exec();
    while(qry.next()){
    ui->comboBox_supprimer->addItem(qry.value(0).toString());
    }

ui->stackedWidget_5->setCurrentIndex(5);


}


void MainWindow::on_ajoute_caisse_clicked()
{
//recuperation des informations saises:
 int id_operation=ui->leidoperation1->text().toInt();
 QString date_operation=ui->ledateoperation1->text();
  QString type_operation=ui->letypeoperation1->currentText();
  int montant=ui->lemontant1->text().toInt();
  QString details=ui->ledetails1->currentText();
  caisse c (id_operation,date_operation,type_operation,montant,details);
  bool test=c.ajouter();
  QMessageBox msgBox;

    if(test)
      {
        historique h;
        h.save_t(ui->leidoperation1->text(),date_operation,type_operation,ui->lemontant1->text(),details,"ajout");
        ui->historique_caisse->setText(h.imp());
        ui->leidoperation1->clear();
        ui->lemontant1->clear();
        msgBox.setText("Ajout avec succes.");
        ui->tablecaisse_2->setModel(c.afficher());
        ui->leidoperation_21->setModel(c.showid());
        c.excel_dynamique();




    }
    else
       { msgBox.setText("Echec d'ajout");}
        msgBox.exec();


}


void MainWindow::on_supprimer_caisse_clicked()
{
caisse c;
int id=ui->comboBox_supprimer->currentText().toInt();
    bool test=c.supprimer(id);
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tablecaisse_2->setModel(c.afficher());
    }
    else
       { msgBox.setText("Echec de suppression");}
        msgBox.exec();
        ui->tablecaisse_2->setModel(c.afficher());
        c.excel_dynamique();

}


void MainWindow::on_historique_3_caisses_clicked()
{
  ui->stackedWidget_5->setCurrentIndex(6);
}


void MainWindow::on_tablecaisse_2_clicked(const QModelIndex &index)
{


//int id_operation=ui->tablecaisse_2->model()->data(index).toInt();
//int id_operation = ui->leidoperation_2->currentText().toInt();
int id_operation=ui->leidoperation_21->currentText().toInt();

caisse c;
qDebug()<< id_operation;



   c=c.SelectModif(id_operation);

   if(c.getid_operation()!=0)
   {

 // ui->leidoperation_2->setText(QString(QString::number(c.getid_operation())));
  ui->ledateoperation1->date();
  ui->letypeoperation1->setCurrentText(c.gettype_operation());
  ui->lemontant_31->setText(QString(QString::number(c.getmontant())));
  ui->ledetails1->setCurrentText(c.getdetails());





}

}

void MainWindow::on_lineEdit_20_textEdited(const QString &arg1)
{
QString arg=ui->lineEdit_20->text();
if (arg1 == NULL)
    ui->tablecaisse_2->setModel(c.afficher());
else
     ui->tablecaisse_2->setModel(c.rechercher(arg));
}

void MainWindow::on_toolButton_6_clicked()
{
third = new stat_caisse(this); // pour ouvrir la fenetre contenant stat
 third->choix_pie();
  third->show();

}
void MainWindow::on_n1_2_clicked()
{
if(flag==1)
{
    n=n+(1/t);
    t=t*10;
}else{
n=(n*10)+1;
ui->label_13->setNum(n);
}
}

void MainWindow::on_n2_2_clicked()
{
n=(n*10)+2;
ui->label_13->setNum(n);
}

void MainWindow::on_n3_2_clicked()
{
n=(n*10)+3;
ui->label_13->setNum(n);
}

void MainWindow::on_n4_2_clicked()
{
n=(n*10)+4;
ui->label_13->setNum(n);
}

void MainWindow::on_n5_2_clicked()
{
n=(n*10)+5;
ui->label_13->setNum(n);
}

void MainWindow::on_n6_2_clicked()
{
n=(n*10)+6;
ui->label_13->setNum(n);
}

void MainWindow::on_n7_2_clicked()
{
n=(n*10)+7;
ui->label_13->setNum(n);
}

void MainWindow::on_n8_2_clicked()
{
n=(n*10)+8;
ui->label_13->setNum(n);
}

void MainWindow::on_n9_2_clicked()
{
n=(n*10)+9;
ui->label_13->setNum(n);
}

void MainWindow::on_n0_2_clicked()
{
n=(n*10)+0;
ui->label_13->setNum(n);
}


void MainWindow::on_Clear_2_clicked()
{
n=0;
r=0;
n1=0;
ui->label_13->setNum(n);
}

void MainWindow::on_add_2_clicked()
{
ui->label_13->setText("+");
o='+';
/*if(c>=1){
    n1=n1+n;
    ui->label->setNum(n1);
    n=0;
}
c=c+1;*/
n1=n;
n=0;

}

void MainWindow::on_sub_2_clicked()
{
ui->label_13->setText("-");
o='-';
/*if(c>=1){
    n1=n1-n;
    ui->label->setNum(n1);
    n=0;
}
c=c+1;*/
n1=n;
n=0;


}


void MainWindow::on_mult_2_clicked()
{
ui->label_13->setText("*");
o='*';
/*if(c>=1){
    n1=n1*n;
    ui->label->setNum(n1);
    n=0;
}
c=c+1;*/
n1=n;
n=0;

}


void MainWindow::on_div_2_clicked()
{
ui->label_13->setText("/");
o='/';
/*if(c>=1){
    n1=n1/n;
    ui->label->setNum(n1);
    n=0;
}
c=c+1;*/
n1=n;
n=0;

}

void MainWindow::on_equal_2_clicked()
{
if(o=='+'){
    r=n+n1;
    n=0;
    n1=r;
    ui->label_13->setNum(r);
}else if (o=='-') {
    r=n1-n;
    n=0;
    n1=r;
    ui->label_13->setNum(r);
}else if (o=='*') {
    r=n1*n;
    n=0;
    n1=r;
    ui->label_13->setNum(r);
}else if (o=='/') {
    r=n1/n;
    n=0;
    n1=r;
    ui->label_13->setNum(r);
}
}

void MainWindow::on_Back_2_clicked()
{
n=n-10;
ui->label_13->setNum(n);
}

void MainWindow::on_sin_2_clicked()
{
r=sin(n);
ui->label_13->setNum(r);
}

void MainWindow::on_cos_2_clicked()
{
r=cos(n);
ui->label_13->setNum(r);
}

void MainWindow::on_tan_2_clicked()
{
r=tan(n);
ui->label_13->setNum(r);
}


void MainWindow::on_asin_2_clicked()
{
r=asin(n);
ui->label_13->setNum(r);
}

void MainWindow::on_acos_2_clicked()
{
r=acos(n);
ui->label_13->setNum(r);
}


void MainWindow::on_atan_2_clicked()
{
r=atan(n);
ui->label_13->setNum(r);
}


void MainWindow::on_modifier_caisses_clicked()
{
ui->stackedWidget_5->setCurrentIndex(3);
}


void MainWindow::on_toolButton_5_clicked()
{
QTableView *table;
                 table = ui->tablecaisse_2;

                 QString filters("CSV files (.csv);;All files (.*)");
                 QString defaultFilter("CSV files (*.csv)");
                 QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                    filters, &defaultFilter);
                 QFile file(fileName);

                 QAbstractItemModel *model =  table->model();
                 if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                     QTextStream data(&file);
                     QStringList strList;
                     for (int i = 0; i < model->columnCount(); i++) {
                         if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                             strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                         else
                             strList.append("");
                     }
                     data << strList.join(";") << "\n";
                     for (int i = 0; i < model->rowCount(); i++) {
                         strList.clear();
                         for (int j = 0; j < model->columnCount(); j++) {

                             if (model->data(model->index(i, j)).toString().length() > 0)
                                 strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                             else
                                 strList.append("");
                         }
                         data << strList.join(";") + "\n";
                     }
                     file.close();
                     QMessageBox::information(nullptr, QObject::tr("export excel"),
                                               QObject::tr("export avec succes .\n"
                                                           "Click OK to exit."), QMessageBox::Ok);
                 }
}

void MainWindow::on_leidoperation_2_activated(const QString &arg1)
{
int id_operation=ui->leidoperation_21->currentText().toInt();

caisse c;
qDebug()<< id_operation;



   c=c.SelectModif(id_operation);

   if(c.getid_operation()!=0)
   {

 // ui->leidoperation_2->setText(QString(QString::number(c.getid_operation())));
  ui->ledateoperation_21->date();
  ui->letypeoperation_21->setCurrentText(c.gettype_operation());
  ui->lemontant_31->setText(QString(QString::number(c.getmontant())));
  ui->ledetails_21->setCurrentText(c.getdetails());

}


}

void MainWindow::on_modifier_caisse_3_clicked()
{
//int id_operation=ui->leidoperation->text().toInt();
int id_operation=ui->leidoperation_21->currentText().toInt();
QString date_operation=ui->ledateoperation_21->text();
QString type_operation=ui->letypeoperation_21->currentText();
int montant=ui->lemontant_31->text().toInt();
QString details=ui->ledetails_21->currentText();
bool test=false;
caisse c(id_operation,date_operation,type_operation,montant,details);
test=c.modifier(id_operation);

if(test==true)
{
  QMessageBox::information(nullptr,QObject::tr("ok"),
  QObject::tr("Modifier avec success\n""click ok to exit"),QMessageBox::Ok);
  ui->tablecaisse_2->setModel(c.afficher()); //affichage automatique apres modification


}
else
{

        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
        QObject::tr("modification non effectue\n""click cancel to exit"),QMessageBox::Cancel);

}


ui->lemontant_31->clear();
c.excel_dynamique();

}

void MainWindow::on_toolButton_7_clicked()
{
ui->stackedWidget_5->setCurrentIndex(1);
}

void MainWindow::on_toolButton_2_clicked()
{
QString nom = ui->lineEdit_20->text();
    ui->tablecaisse_2->setModel(c.rechercher(nom));
}




void MainWindow::on_Arduino_caisses_clicked()
{
QPixmap m_logo_pic;
m_logo_pic.load("C:/Users/asus/Desktop/Gestion_Caisse/caisse1.png");
   ui->label_15->setPixmap(m_logo_pic);
   //ui->label_15->show();
   //ui->label_15->setStyleSheet("background-image: url(C:/Users/asus/Desktop/Gestion_Caisse/caisse1.png);");
   ui->stackedWidget_5->setCurrentIndex(4);
}


void MainWindow::on_affiche_emp_12_clicked()
{
               ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_mailing_15_clicked()
{
      ui->stackedWidget->setCurrentIndex(12);
}

 /********************************   Gestion_Patients   ****************************************/

void MainWindow::on_affiche_emp_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_calendrier_clicked()
{
    secDialog= new secformdialog(this);
    secDialog->show();

}

void MainWindow::on_add_patient_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(0);
}

void MainWindow::on_dispaly_patients_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(3);
        ui->tableView_2->setModel(p.afficher_patient());
}

void MainWindow::on_update_patients_clicked()
{

    ui->stackedWidget_6->setCurrentIndex(4);
    Connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_5->setModel(modal);
}

void MainWindow::on_delete_patients_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(5);
    Connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_sup_2->setModel(modal);

}

void MainWindow::on_retour_9_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_retour_10_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_retour_11_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_retour_8_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_ajoute_pati_clicked()
{const QString RESULTS_PATH2 = "C:/Users/rayan/OneDrive/Bureau/MainWindowV2/auto_QRcode/";
    QDir().rmpath(RESULTS_PATH2);
    QDir().mkpath(RESULTS_PATH2);
    int cin=ui->lecin->text().toInt();
    QString cin1=ui->lecin->text();
    int age=ui->leage->text().toInt();
    int num_chambre=ui->lenumchambre->text().toInt();
    int contact_famille=ui->lecontact->text().toInt();
    QString nom=ui->lenom->text();
    QString prenom=ui->leprenom->text();
    QString type_maladie=ui->comboBox_3->currentText();
QString dateR=ui->dateEdit->date().toString();
   QDate rendez_vous=ui->dateEdit->date();
   QString nomimg=nom+".JPG";
         QString chemain=RESULTS_PATH2+nomimg;

   QString image=chemain;

//QDate rendez_vous =ui->calendarAjout->selectedDate();
   patient P(cin,nom,prenom,num_chambre,rendez_vous,type_maladie,age,contact_famille,image);

 //QString nomimg=nom+".PNG";

   QString QR="Nom \t "+nom+"Prenom \t"+prenom+"Date Rendez_vous \t"+dateR;
QString date=ui->dateEdit->text();

        QMessageBox msgbox;


        int erreur=0;

                if(!P.chaine_Valid(nom)||nom=="")
                erreur=1;
                if(P.DateValide(rendez_vous))
                erreur=2;
                if(!P.chaine_Valid(prenom)||prenom=="")
                erreur=3;
                if(cin1=="")
                erreur=4;
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
                case 4:
                msgbox.setText("Echec d'ajout");
                break;
                }
                if(erreur==0){
                 historique h;

 bool test=P.ajouter_patient();
        if(test)
        {


          h.save_txt_p(ui->lecin->text(),ui->lenom->text(),ui->leprenom->text(),ui->leage->text(),type_maladie,date,ui->lenumchambre->text(),ui->lecontact->text());
ui->historique_6->setText(h.imp_hist_p());


          QrCode qr = QrCode::encodeText(QR.toUtf8().constData(), QrCode::Ecc::HIGH);


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
          im.save(chemain,"JPG");

          //ui->labe_i->setText(chemain);

         ui->Qr->setPixmap(QPixmap::fromImage(im));

            msgbox.setText("Ajout avec succes.");
           ui->tableView->setModel(P.afficher_patient());

           ui->lecin->clear();
           ui->lenom->clear();
           ui->leprenom->clear();
           ui->lecontact->clear();
           ui->lenumchambre->clear();
           ui->dateEdit->clear();
           ui->comboBox_3->clear();
           ui->leage->clear();
           ui->dateEdit->clear();

        }
        else
            msgbox.setText("Echec d'ajout");


                }
                msgbox.exec();
                 //ui->stackedWidget->setCurrentIndex(3);
                ui->stackedWidget_6->setCurrentIndex(3);


}

void MainWindow::on_comboBox_sup_2_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_sup_2->currentText();
    Connection c;


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

void MainWindow::on_comboBox_5_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_5->currentText();
    Connection c;


    QSqlQuery qry;
    qry.prepare("select * from patient where cin='"+cin+"'");
    if(qry.exec()){
      while(qry.next()){

       ui->lenom2->setText(qry.value(1).toString());
       ui->leprenom2->setText(qry.value(2).toString());
       ui->leage2->setText(qry.value(3).toString());
       ui->dateEdit_2->setDate(qry.value(4).toDate());
       ui->comboBox_6->setCurrentText(qry.value(5).toString());
       ui->lenum_chambre2->setText(qry.value(6).toString());
       ui->lecontact2->setText(qry.value(7).toString());
ui->leqr->setText(qry.value(8).toString());

      }
    }

    else
    {
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

}

void MainWindow::on_modifier_pati_clicked()
{
    const QString RESULTS_PATH2 = "C:/Users/rayan/Downloads/Aid-Association_integration/Aid-Association-2A7-main/auto_QRcode";
        QDir().rmpath(RESULTS_PATH2);
        QDir().mkpath(RESULTS_PATH2);
    patient P;

    QMessageBox msg;

P.setcin(ui->comboBox_5->currentText().toInt());
    P.setage(ui->leage2->text().toInt());
    P.setnum_chambre(ui->lenum_chambre2->text().toInt());
    P.setcontact_famille(ui->lecontact2->text().toInt());
P.setprenom(ui->leprenom2->text());
P.setnom(ui->lenom2->text());

P.settype_maladie(ui->comboBox_6->currentText());
P.setrendez_vous(ui->dateEdit_2->date());
P.setimage(ui->leqr->text());
/*int cin=ui->comboBox->currentText().toInt();
int age=ui->leage2->text().toInt();
int num_chambre=ui->lenum_chambre2->text().toInt();
int contact_famille=ui->lecontact2->text().toInt();*/
QString nom=ui->lenom2->text();
QString prenom=ui->leprenom2->text();
//QDate dateR=ui->dateEdit_2->date();
QString nomimg=nom+".JPG";
      QString chemain2=RESULTS_PATH2+nomimg;
//String image=ui->l_chemain->text();
     QString image=chemain2;
   QString dateR=ui->dateEdit_2->date().toString();
      QString QR="Nom \t "+nom+"Prenom \t"+prenom+"Date Rendez_vous \t"+dateR;

//QString image=chemain2;
      QrCode qr = QrCode::encodeText(QR.toUtf8().constData(), QrCode::Ecc::HIGH);


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
      im.save(chemain2,"JPG");

      //ui->l_chemain->setText(chemain2);
      ui->leqr->setText(chemain2);

     ui->Qrmodif->setPixmap(QPixmap::fromImage(im));
bool test=P.modifier_patient();


    if(test)
    {

       msg.setText("modification avec succès");
       ui->stackedWidget_6->setCurrentIndex(3);
      // ui->stackedWidget->setCurrentIndex(3);

       // ui->tableView->setModel(P.afficher_patient());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void MainWindow::on_supprimer_patient_clicked()
{
    int cin=ui->comboBox_sup_2->currentText().toInt();

   bool test=p.supprimer_patient(cin);


    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("supprimer avec succée");
    ui->tableView_2->setModel(p.afficher_patient());

    // Put the focus back into the input box so they can type again:
    ui->comboBox_sup_2->setFocus();

    }

    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
    //ui->stackedWidget_6->setCurrentIndex(3);
}

void MainWindow::on_lineEdit_14_textChanged(const QString &arg1)
{
     ui->tableView_2->setModel(p.search(arg1));
}

void MainWindow::on_toolButton_16_clicked()
{
    QString nom = ui->lineEdit_12->text();
    ui->tableView_2->setModel(p.search(nom));
}

void MainWindow::on_toolButton_17_clicked()
{
    QString l=ui->comboBox_4->currentText();
    ui->tableView_2->setModel(p.trier(l));
}

void MainWindow::on_toolButton_18_clicked()
{

    QString l=ui->comboBox_4->currentText();
    ui->tableView_2->setModel(p.trierdesc(l));
}


void MainWindow::on_toolButton_15_clicked()
{
    ui->stackedWidget_6->setCurrentIndex(2);
}

void MainWindow::on_toolButton_14_clicked()
{   /*int cin=ui->lecin->text().toInt();
    int age=ui->leage->text().toInt();
    int num_chambre=ui->lenumchambre->text().toInt();
    int contact_famille=ui->lecontact->text().toInt();
    QString nom=ui->lenom->text();
    QString prenom=ui->leprenom->text();
    QString type_maladie=ui->comboBox_2->currentText();
QString image;
   QDate rendez_vous=ui->dateEdit->date();
//QDate rendez_vous =ui->calendarAjout->selectedDate();
   patient P(cin,nom,prenom,num_chambre,rendez_vous,type_maladie,age,contact_famille,image);


QString date=ui->dateEdit->text();

        QMessageBox msgbox;

        Historique h;
      h.save_txt(ui->lecin->text(),ui->lenom->text(),ui->leprenom->text(),ui->leage->text(),type_maladie,date,ui->lenumchambre->text(),ui->lecontact->text());
      ui->historique->setText(h.imp_hist());*/
    ui->stackedWidget_6->setCurrentIndex(1);
}

void MainWindow::on_calendarAjout_clicked(const QDate &rendez_vous)
{
   ui->calendarAjout->selectedDate();
}





void MainWindow::on_qrCode_clicked()
{

    int tabeq=ui->tableView_2->currentIndex().row();
                       QVariant cinn=ui->tableView_2->model()->data(ui->tableView_2->model()->index(tabeq,0));
                       QString cin=cinn.toString();
                      // QString code=idd.toSTring();
                       QSqlQuery qry;
                       qry.prepare("select * from patient where cin=:cin");
                       qry.bindValue(":cin",cin);
                       qry.exec();

                        QString nom,prenom,type_maladie;//attributs
                        int age,num_chambre,contact_famille;
                        QString rendez_vous;
                        QString image;

                      while(qry.next()){

                          cin=qry.value(0).toString();
                           nom=qry.value(1).toString();
                            prenom=qry.value(2).toString();
                           age=qry.value(3).toInt();
                            rendez_vous=qry.value(4).toString();
                        type_maladie=qry.value(5).toString();
                            num_chambre=qry.value(6).toInt();
                             contact_famille=qry.value(7).toInt();
                             image=qry.value(8).toString();



                       }

                      const char* myChar=image.toStdString().c_str() ;
                      QImage im(tr(myChar));
                      ui->qrcode->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_calendarAjout_selectionChanged()
{
    ui->dateEdit->setDate(ui->calendarAjout->selectedDate());
}





void MainWindow::on_toolButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}




