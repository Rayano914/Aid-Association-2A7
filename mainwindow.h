#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employe.h"
#include "login.h"
#include "equipements.h"
#include <QSqlQueryModel>
#include<QCompleter>
#include<QDirModel>
#include "connection.h"
#include<QTimer>
#include "secformdialog.h"
#include "patient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void combo();

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

    void on_ajouter_equipement_clicked();

    void on_ajouter_equipements_clicked();

    void on_supprimer_equipements_clicked();

    void on_modifier_equipements_clicked();

    void on_affiche_equipements_clicked();

    void on_modifier_equipement_clicked();

    void on_supprimer_equipement_clicked();

    void on_recherche_equipement_clicked();

    void on_tri_prix_clicked();

    void on_tri_id_clicked();

    void on_tri_nombre_clicked();

    void on_historique_2_clicked();

    void on_lineEdit_id_equi_modif_currentIndexChanged(int index);

    void on_retourner_aff_clicked();

    void on_retourner_modif_clicked();

    void on_retourner_supp_clicked();

    void on_retourner_hist_clicked();

    void on_retourner_ajout_clicked();

    void on_affiche_emp_4_clicked();

    void on_affiche_emp_13_clicked();

    void on_mailing_10_clicked();

    void on_affiche_emp_17_clicked();

    void on_mailing_11_clicked();

    void on_mailing_12_clicked();

    void on_mailing_8_clicked();

    void on_affiche_emp_15_clicked();
    /**************************************************************/
    void on_calendrier_clicked();

    void on_add_patient_clicked();

    void on_dispaly_patients_clicked();

    void on_update_patients_clicked();

    void on_delete_patients_clicked();

    void on_retour_2_clicked();

    void on_retour_3_clicked();

    void on_retour_4_clicked();

    void on_retour_clicked();

    void on_ajoute_pati_clicked();

    void on_comboBox_sup_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_modifier_pati_clicked();

    void on_supprimer_patient_clicked();

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_toolButton_2_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_4_clicked();

    void on_calendarAjout_clicked(const QDate &date);

    void on_qrCode_clicked();

    void on_calendarAjout_selectionChanged();

    void on_calendarWidget_selectionChanged();

    void on_addButton_clicked();

    void on_mailing_8_clicked();

    void on_mailing_10_clicked();

    void on_mailing_11_clicked();

private:
    Ui::MainWindow *ui;
    Employe Empl;
    QCompleter *stringcompleter,*modelcompleter, *StringCompleter;
    Connection C;
    login l;
    QTimer timer;
    equipements Equi;
    patient p;
    QString selected;
    secformdialog *secDialog;

    QCompleter *stringcompleter,*modelcompleter;
    Connection C;
    login l;
    QTimer timer;
};
#endif // MAINWINDOW_H
