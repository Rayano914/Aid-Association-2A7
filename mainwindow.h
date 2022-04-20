#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "activite.h"

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


    void on_ajouter_activites_clicked();

    void on_ajouter_activite_clicked();

    void on_supprimer_activites_clicked();

    void on_modifier_activites_clicked();

    void on_affiche_activites_clicked();

    void on_return_2_clicked();

    void on_modifier_activite_clicked();

    void on_supprimer_activite_clicked();

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_lineEdit_type_activite_modif_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_lineEdit_recherche_triggered(QAction *arg1);

    void on_lineEdit_recherche_objectNameChanged(const QString &objectName);

    void on_lineEdit_12_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_12_textChanged(const QString &arg1);

    void on_lineEdit_12_textEdited(const QString &arg1);

    void on_fleche_clicked();

    void on_ajoute_caisse_clicked();

    void on_afficher_clicked();

    void on_supprimer_caisses_clicked();

    void on_ajouter_caisses_clicked();

    void on_supprimer_caisse_clicked();

    void on_tablecaisse_2_clicked(const QModelIndex &index);

    void on_modifier_caisse_2_clicked();

    void on_modif_clicked();

    void on_historique_3_clicked();

    void on_historique_anchorClicked(const QUrl &arg1);

    void on_modifier_caisse_3_clicked();

    void on_trier_clicked();

    void on_comboBox_Tri_activated(const QString &arg1);

    void on_historique_3_triggered(QAction *arg1);

    void on_sms_clicked();

private:
    Ui::MainWindow *ui;
    activite act;
};
#endif // MAINWINDOW_H
