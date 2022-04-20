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
#include "equipements.h"
#include "qrcode.h"
#include "patient.h"
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSystemTrayIcon>
#include "connection.h"
constexpr int MAX = 1000000;
using std::int8_t;
using std::uint8_t;
using std::size_t;
using std::vector;
using namespace ::qrcodegen;
const QString RESULTS_PATH = "C:/Users/Ghada/Desktop/integration/MainWindowV2/Qrcode";
const QString RESULTS_PATH2 = "C:/Users/Ghada/Desktop/integration/MainWindowV2/auto_QRcode";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()),this,SLOT(myfunction()));
    //timer->start(1000);
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
    ui->lineEdit_id_emp->setValidator(new QIntValidator(10000000, 99999999, this));
    ui->lineEdit_age->setValidator(new QIntValidator(0, 65, this));
    ui->lineEdit_age_modif->setValidator(new QIntValidator(20, 65, this));
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
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
    /*************************************/
    ui->lecin->setValidator(new QIntValidator(0,99999999,this));
     ui->lenumchambre->setValidator(new QIntValidator(0,9999,this));
      ui->lecontact->setValidator(new QIntValidator(0,99999999,this));
     selected="";
     Connection c;
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
        //Appel du constructeur parametré
        Employe E(id,nom,prenom,spec,mail,age);

         if ((id=="") || (nom=="") || (prenom=="")|| (mail=="")||(age==0) || (ui->comboBox->currentIndex ()==0))
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
         else if(id.length()!=8)
         {
             test=false;
             QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                      QObject::tr("!!\n""Verifier longueur de CIN"),QMessageBox::Cancel);
         }


            if(test)//si requete executer ==>QMessageBox::information
            {
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
    int id_employe=ui->comboBox_modif->currentText().toInt();
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
    QString query="select mdp from EMPLOYE where nom_utilisateur=:nom_utilisateur";
    if ((mdp_anc==query )&&(mdp==mdp_nvconf))
            {
        l.modifierLogin();
        ui->lineEdit_mdp_anc->clear();
        ui->lineEdit_mdp_nv->clear();
        ui->lineEdit_mdp_nvconf->clear();

            }
        else
        {
           QMessageBox::critical(this,"ERREURS"," Mot de passe incorrecte!");
        }

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
/*************************************EQUIPEMENT***************************************************/
void MainWindow::on_ajouter_equipements_clicked()
{
  combo();
    ui->stackedWidget_3->setCurrentIndex(0);

}

void MainWindow::on_affiche_equipements_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->tableView_3->setModel(Equi.afficher_equipement());
    QSqlQuery qry1;
    qry1.prepare("select * from equipement");
               qry1.exec();
               QStringList completionlist;
               while(qry1.next()){
                   completionlist <<qry1.value("id_equipement").toString()<<qry1.value("type_equipement").toString() <<qry1.value("prix").toString();


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

        QMessageBox::StandardButton reply = QMessageBox::information(this,"Suppression","Voulez-vous vraiment supprimer cet equipements definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

        if(reply==QMessageBox::Yes)
        {
            /*historique hs;
            hs.enregistrer_txt(ui->supprimer_equipement_2->currentText(),"","","","supprimer");
            ui->historique->setText(hs.imprimer_hist());*/
            bool test=Equi.supprimer(id_equipement);
            ui->tableView_3->setModel(Equi.afficher_equipement());

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

void MainWindow::on_retourner_aff_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_retourner_modif_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_retourner_supp_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_retourner_hist_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_retourner_ajout_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_affiche_emp_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_affiche_emp_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    ui->stackedWidget_3->setCurrentIndex(1);

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
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_affiche_emp_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    ui->stackedWidget_3->setCurrentIndex(1);
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

void MainWindow::on_mailing_12_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}

void MainWindow::on_mailing_8_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnexion","êtes-vous sûr de vouloir vous déconnecter?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    { ui->stackedWidget->setCurrentIndex(6);}
    else
    {}
}

void MainWindow::on_affiche_emp_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}
/*******************************************GESTION PATIENT**********************************************************************************************/

void MainWindow::on_calendrier_clicked()
{
    secDialog= new secformdialog(this);
    secDialog->show();

}

void MainWindow::on_add_patient_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_dispaly_patients_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(3);
        ui->tableView_4->setModel(p.afficher_patient());
}

void MainWindow::on_update_patients_clicked()
{

    ui->stackedWidget->setCurrentIndex(4);
    Connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
}

void MainWindow::on_delete_patients_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(5);
    Connection c;
    QSqlQueryModel * modal =new QSqlQueryModel();
    //c.createconnect();
    QSqlQuery *qry =new QSqlQuery(c.db);
    qry->prepare("SELECT CIN FROM patient");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_sup->setModel(modal);

}

void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::on_retour_3_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::on_retour_4_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
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
    QString type_maladie=ui->comboBox_2->currentText();
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
                // Historique h;
 //ui->historique->setText(h.imp_hist());
 bool test=P.ajouter_patient();
        if(test)
        {


          //h.save_txt(ui->lecin->text(),ui->lenom->text(),ui->leprenom->text(),ui->leage->text(),type_maladie,date,ui->lenumchambre->text(),ui->lecontact->text());
         // ui->historique->setText(h.imp_hist());


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
           ui->comboBox->clear();
           ui->leage->clear();
           ui->dateEdit->clear();
           ui->comboBox->clear();
        }
        else
            msgbox.setText("Echec d'ajout");


                }
                msgbox.exec();
                 //ui->stackedWidget->setCurrentIndex(3);


}

void MainWindow::on_comboBox_sup_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox_sup->currentText();
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

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString cin=ui->comboBox->currentText();
    Connection c;


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
    const QString RESULTS_PATH2 = "C:/Users/Ghada/Desktop/integration/MainWindowV2/auto_QRcode";
        QDir().rmpath(RESULTS_PATH2);
        QDir().mkpath(RESULTS_PATH2);
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
      // ui->stackedWidget->setCurrentIndex(3);

       // ui->tableView->setModel(P.afficher_patient());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void MainWindow::on_supprimer_patient_clicked()
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
    ui->stackedWidget_4->setCurrentIndex(3);
}

void MainWindow::on_lineEdit_12_textChanged(const QString &arg1)
{
     ui->tableView_4->setModel(p.search(arg1));
}

void MainWindow::on_toolButton_2_clicked()
{
    QString nom = ui->lineEdit_12->text();
    ui->tableView_4->setModel(p.search(nom));
}

void MainWindow::on_toolButton_5_clicked()
{
    QString l=ui->comboBox_4->currentText();
    ui->tableView_4->setModel(p.trier(l));
}

void MainWindow::on_toolButton_clicked()
{

    QString l=ui->comboBox_4->currentText();
    ui->tableView->setModel(p.trierdesc(l));
}


void MainWindow::on_toolButton_6_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}

void MainWindow::on_toolButton_4_clicked()
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
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_calendarAjout_clicked(const QDate &rendez_vous)
{
   ui->calendarAjout->selectedDate();
}





void MainWindow::on_qrCode_clicked()
{

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



void MainWindow::on_calendarWidget_selectionChanged()
{ QDate date;

    date=ui->calendarWidget->selectedDate();

    ui->dateEdit_C->setDate(ui->calendarWidget->selectedDate());

//ui->tablC->setModel(p.afficher_patient());

QString m=date.toString();
ui->tablC->setModel(p.afficher_C(date));
ui->tablC->setModel(p.afficher_C2());

}

void MainWindow::on_addButton_clicked()
{
    QDate r=ui->dateEdit_C->date();
   // ui->tablC->setModel(p.afficher_C(r));
}

