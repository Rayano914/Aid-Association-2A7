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
#include "equipements.h"
#include<QTcpSocket>
#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "widgetheart.h"
#include "duscene.h"
#include "don.h"
#include "arduino.h"
#include "historique.h"
#include "activite.h"
#include<QDirModel>
#include <QtCharts> //stat
#include <QChartView> //stat
#include<QLineSeries> //stat
#include "stat_caisse.h"
#include <QtGlobal>
#include "caisse.h"
#include <cstdlib>
#include "patient.h"
#include "secformdialog.h"

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

    //void on_comboBox_modif_activated(int index);

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

    //void on_login_3_clicked();

    void on_login_4_clicked();

    void on_login_10_clicked();

    void on_envoyer_code_ajouter_clicked();

    void on_mailing_9_clicked();

    void myfunction();

    void on_mailing_8_clicked();

    void on_mailing_10_clicked();

    void on_mailing_11_clicked();

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

    void on_return_22_clicked();

    void on_return_18_clicked();

    void on_return_19_clicked();

    void on_return_20_clicked();

    void on_return_21_clicked();

    void on_affiche_emp_4_clicked();

    void on_affiche_emp_13_clicked();

    void on_affiche_emp_17_clicked();

    void on_affiche_emp_14_clicked();

    void on_ajouter_dons_clicked();

    void on_afficher_dons_clicked();

    void on_modifier_dons_clicked();

    void on_supprimer_dons_clicked();

    void on_retour_clicked();

    void on_retour_2_clicked();

    void on_retour_3_clicked();

    void on_retour_4_clicked();

    void on_ajoute_don_clicked();

    void on_supprimer_don_clicked();

    void on_modifier_don_clicked();

    void on_trier_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_retour_5_clicked();

    void on_hist_clicked();

    void on_chatbox_clicked();

    void on_connecter_clicked();

    void on_pushButton_clicked();

    void on_retour_6_clicked();

    void on_chatbox_2_clicked();

    void on_modifier_don_2_clicked();

    void update_label();

    void on_retour_7_clicked();

    void on_affiche_emp_16_clicked();

    void on_affiche_emp_7_clicked();

    /************************************************************************************/
    void on_ajouter_activites_clicked();

    void on_supprimer_activites_clicked();

    void on_modifier_activites_clicked();

    void on_lineEdit_13_textEdited(const QString &arg1);

    void on_ajouter_activite_clicked();

    void on_supprimer_activite_clicked();

    void on_modifier_activite_clicked();

    void on_modifier_caisse_3_clicked();

    void on_historique_3_clicked();

    void on_comboBox_Tri_activated(const QString &arg1);

    void on_sms_clicked();

    void on_mailing_14_clicked();

    void on_mailing_13_clicked();

    void on_mailing_12_clicked();

    void on_tableactivite_2_clicked(const QModelIndex &index);
    /**************************************************************************/
    void on_supprimer_caisses_clicked();

    void on_modifier_caisses_clicked();

    void on_afficher_caisses_clicked();

    void on_ajouter_caisses_clicked();

    void on_btn_clicked();

    void on_ajoute_caisse_clicked();

    void on_supprimer_caisse_clicked();

     void on_historique_3_caisses_clicked();

     void on_toolButton_2_clicked();

     void on_tablecaisse_2_clicked(const QModelIndex &index);

     void on_lineEdit_20_textEdited(const QString &arg1);

     void on_toolButton_6_clicked();

     void on_toolButton_5_clicked();

     void on_leidoperation_2_activated(const QString &arg1);

     void on_toolButton_7_clicked();

    void on_n1_2_clicked();

    void on_n2_2_clicked();

    void on_n3_2_clicked();

    void on_n4_2_clicked();

    void on_n5_2_clicked();

    void on_n6_2_clicked();

    void on_n7_2_clicked();

    void on_n8_2_clicked();

    void on_n9_2_clicked();

    void on_n0_2_clicked();

    void on_Clear_2_clicked();

    void on_add_2_clicked();

    void on_sub_2_clicked();

    void on_mult_2_clicked();

    void on_div_2_clicked();

    void on_equal_2_clicked();

    void on_Back_2_clicked();

    void on_sin_2_clicked();

    void on_cos_2_clicked();

    void on_tan_2_clicked();

    void on_asin_2_clicked();

    void on_acos_2_clicked();

    void on_atan_2_clicked();

    void on_Arduino_caisses_clicked();

    void on_affiche_emp_12_clicked();

    void on_mailing_15_clicked();
    /********************************************************************************/

    void on_calendrier_clicked();

    void on_add_patient_clicked();

    void on_dispaly_patients_clicked();

    void on_update_patients_clicked();

    void on_delete_patients_clicked();

    void on_retour_9_clicked();

    void on_retour_10_clicked();

    void on_retour_11_clicked();

    void on_retour_8_clicked();

    void on_ajoute_pati_clicked();

    //void on_comboBox_sup_currentIndexChanged(const QString &arg1);

    //void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_modifier_pati_clicked();

    void on_supprimer_patient_clicked();

    //void on_lineEdit_12_textChanged(const QString &arg1);

    void on_toolButton_16_clicked();

    void on_toolButton_17_clicked();

    //void on_toolButton_clicked();

    void on_toolButton_15_clicked();

    //void on_toolButton_4_clicked();

    void on_calendarAjout_clicked(const QDate &date);

    void on_qrCode_clicked();

    void on_calendarAjout_selectionChanged();


    void on_affiche_emp_15_clicked();

    void on_comboBox_5_currentIndexChanged(const QString &arg1);

    void on_comboBox_sup_2_currentIndexChanged(const QString &arg1);

    void on_toolButton_19_clicked();

    void on_toolButton_14_clicked();

    void on_lineEdit_14_textChanged(const QString &arg1);

    void on_toolButton_18_clicked();

private:
    Ui::MainWindow *ui;
    Employe Empl;
    QCompleter *stringcompleter,*modelcompleter;
    Connection C;
    login l;
    QTimer timer;
    equipements Equi;
    QTcpSocket *mSocket;
    QByteArray data;
    Duscene *mScene;
    arduino A;
    QString res="";
    activite act;
    caisse c;
    stat_caisse *third;
   qreal n,n1,r,cp;
   qint32 flag,t;
   char o;
   QString selected;
   QCompleter *StringCompleter;
patient p;
   secformdialog *secDialog;
};
#endif // MAINWINDOW_H
