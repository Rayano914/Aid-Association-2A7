#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employe.h"
#include "login.h"
#include <QSqlQueryModel>
#include<QCompleter>
#include<QDirModel>
#include "connection.h"
#include<QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouter_empl_clicked();

    void on_affiche_emp_clicked();

    void on_modifier_emp_clicked();

    void on_supprimer_emp_clicked();

    void on_return_2_clicked();


    void on_ajouter_employer_clicked();

    void on_modifier_employer_clicked();

    void on_supprimer_employe_clicked();


    void on_toolButton_pdf_clicked();


    void on_toolButton_recherche_employe_clicked();

    void on_mailing_clicked();

    void on_comboBox_modif_activated(int index);

    void on_comboBox_modif_currentIndexChanged(int index);

    void on_envoyer_mail_clicked();

    void on_toolButton_attach_1_clicked();

    void on_toolButton_attach_2_clicked();

    void on_toolButton_attach_3_clicked();

    QStringList getRecipientsAddress(QString str);

    void on_return_4_clicked();

    void on_return_5_clicked();

    void on_return_6_clicked();

    void on_return_3_clicked();

    void on_login_clicked();

    void on_affiche_emp_2_clicked();

    void on_ajouter_empl_3_clicked();

    void on_ajouter_empl_2_clicked();

    void on_ajouter_empl_4_clicked();

    void on_ajouter_empl_5_clicked();

    void on_mdp_oublier_clicked();

    void on_mailing_2_clicked();

    void on_mailing_4_clicked();

    void on_mailing_3_clicked();

    void on_affiche_emp_8_clicked();

    void on_return_14_clicked();

    void on_return_13_clicked();

    void on_return_12_clicked();

    void on_login_7_clicked();

    void on_login_9_clicked();

    void on_login_3_clicked();

    void on_login_4_clicked();

    void on_login_10_clicked();

    void on_envoyer_code_ajouter_clicked();

    void on_mailing_9_clicked();

    void myfunction();

    void on_mailing_8_clicked();

    void on_mailing_10_clicked();

    void on_mailing_11_clicked();

private:
    Ui::MainWindow *ui;
    Employe Empl;
    QCompleter *stringcompleter,*modelcompleter;
    Connection C;
    login l;
    QTimer timer;
};
#endif // MAINWINDOW_H
