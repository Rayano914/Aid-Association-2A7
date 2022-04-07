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
constexpr int MAX = 1000000;



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
