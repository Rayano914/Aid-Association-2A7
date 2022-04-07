#include "mainwindow.h"
#include <QSqlQuery>
#include "ui_mainwindow.h"
#include "caisse.h"
#include "QMessageBox"
#include <QDebug>
#include "historique.h"
#include <QSqlQueryModel>
#include "excel.h"
#include<QTableView> //excel

MainWindow::MainWindow(QWidget *parent) // parent Constructeur de la classe mainwindow généré automatiquement
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    n=0;
    cp=0;
    t=10;
    ui->letypeoperation->addItem("Revenue");
    ui->letypeoperation->addItem("Depense");
    ui->letypeoperation_2->addItem("Revenue");
    ui->letypeoperation_2->addItem("Depense");
    ui->ledetails->addItem("Dons");
    ui->ledetails->addItem("Adherents");
    ui->ledetails->addItem("Depense");
    ui->ledetails_2->addItem("Dons");
    ui->ledetails_2->addItem("Adherents");
    ui->ledetails_2->addItem("Depense");
    ui->tablecaisse_2->setModel(c.afficher());
   // ui->calculatrice->setModel(c.calculatrice());
    ui->leidoperation_2->setModel(c.showid());
    ui->stackedWidget->setCurrentIndex(2);
    //control de saisi
      ui->leidoperation->setValidator(new QIntValidator(0, 999999, this));
      //ui->lineEdit_modif_id->setValidator(new QIntValidator(0, 99999999, this));
      ui->lemontant->setValidator(new QIntValidator(0, 999999, this));
      historique h;
      ui->historique->setText(h.imp_hist());

      QSqlQuery qry1;
 qry1.prepare("select * from caisse");
   qry1.exec();
 QStringList completionlist;
 while(qry1.next()){
 completionlist <<qry1.value("id_operation").toString()<<qry1.value("type_operation").toString() <<qry1.value("montant").toString()<<qry1.value("details").toString();


                    }

                    stringcompleter=new QCompleter(completionlist,this);
                    stringcompleter->setCaseSensitivity(Qt::CaseInsensitive);
                   ui->lineEdit_12->setCompleter(stringcompleter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fleche_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ajouter_caisses_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_afficher_caisses_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
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

    ui->stackedWidget->setCurrentIndex(5);


}


void MainWindow::on_ajoute_caisse_clicked()
{
    //recuperation des informations saises:
     int id_operation=ui->leidoperation->text().toInt();
     QString date_operation=ui->ledateoperation->text();
      QString type_operation=ui->letypeoperation->currentText();
      int montant=ui->lemontant->text().toInt();
      QString details=ui->ledetails->currentText();
      caisse c (id_operation,date_operation,type_operation,montant,details);
      bool test=c.ajouter();
      QMessageBox msgBox;

        if(test)
          {
            historique h;
            h.save_txt(ui->leidoperation->text(),date_operation,type_operation,ui->lemontant->text(),details,"ajout");
            ui->historique->setText(h.imp_hist());
            ui->leidoperation->clear();
            ui->lemontant->clear();
            msgBox.setText("Ajout avec succes.");
            ui->tablecaisse_2->setModel(c.afficher());
            ui->leidoperation_2->setModel(c.showid());
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


void MainWindow::on_historique_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_tablecaisse_2_clicked(const QModelIndex &index)
{


    //int id_operation=ui->tablecaisse_2->model()->data(index).toInt();
    //int id_operation = ui->leidoperation_2->currentText().toInt();
    int id_operation=ui->leidoperation_2->currentText().toInt();

    caisse c;
    qDebug()<< id_operation;



       c=c.SelectModif(id_operation);

       if(c.getid_operation()!=0)
       {

     // ui->leidoperation_2->setText(QString(QString::number(c.getid_operation())));
      ui->ledateoperation->date();
      ui->letypeoperation->setCurrentText(c.gettype_operation());
      ui->lemontant_3->setText(QString(QString::number(c.getmontant())));
      ui->ledetails->setCurrentText(c.getdetails());





   }

}

void MainWindow::on_modifier_caisse_2_clicked()
{



}

void MainWindow::on_modifier_caisses_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_lineEdit_12_textEdited(const QString &arg1)
{
    QString arg=ui->lineEdit_12->text();
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

void MainWindow::on_pushButton_clicked()
{

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


void MainWindow::on_modif_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
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
    int id_operation=ui->leidoperation_2->currentText().toInt();

    caisse c;
    qDebug()<< id_operation;



       c=c.SelectModif(id_operation);

       if(c.getid_operation()!=0)
       {

     // ui->leidoperation_2->setText(QString(QString::number(c.getid_operation())));
      ui->ledateoperation_2->date();
      ui->letypeoperation_2->setCurrentText(c.gettype_operation());
      ui->lemontant_3->setText(QString(QString::number(c.getmontant())));
      ui->ledetails_2->setCurrentText(c.getdetails());





   }


}

void MainWindow::on_modifier_caisse_3_clicked()
{
    //int id_operation=ui->leidoperation->text().toInt();
    int id_operation=ui->leidoperation_2->currentText().toInt();
    QString date_operation=ui->ledateoperation_2->text();
    QString type_operation=ui->letypeoperation_2->currentText();
 int montant=ui->lemontant_3->text().toInt();
 QString details=ui->ledetails_2->currentText();
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


    ui->lemontant_3->clear();
    c.excel_dynamique();

}

void MainWindow::on_toolButton_7_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_toolButton_2_clicked()
{
    QString nom = ui->lineEdit_12->text();
        ui->tablecaisse_2->setModel(c.rechercher(nom));
}



