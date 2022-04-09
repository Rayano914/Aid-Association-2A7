#ifndef GESTION_PATIENT_H
#define GESTION_PATIENT_H
#include <QMainWindow>
#include <QCompleter>
#include <QDirModel>
#include "patient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion_patient; }
QT_END_NAMESPACE

class Gestion_patient : public QMainWindow
{
    Q_OBJECT

public:
    Gestion_patient(QWidget *parent = nullptr);

    ~Gestion_patient();

private slots:



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

    void on_pushButton_clicked();

    void on_calendarWidget_selectionChanged();

    void on_addButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_pdf_currentIndexChanged(const QString &arg1);


    void on_pushButton_3_clicked();

private:
    Ui::Gestion_patient *ui;
    patient p;
      QString selected;
      QCompleter *StringCompleter;
};
#endif // GESTION_PATIENT_H
