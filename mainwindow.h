#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipements.h"
#include <QSqlQueryModel>
#include<QCompleter>
#include<QDirModel>


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


    void on_ajouter_equipement_clicked();

    void on_ajouter_equipements_clicked();

    void on_supprimer_equipements_clicked();

    void on_modifier_equipements_clicked();

    void on_affiche_equipements_clicked();

    void on_return_2_clicked();
    void on_return_3_clicked();
    void on_return_4_clicked();
    void on_return_5_clicked();
    void on_return_6_clicked();

    void on_modifier_equipement_clicked();

    void on_supprimer_equipement_clicked();

    void on_recherche_equipement_clicked();

    void on_tri_prix_clicked();

    void on_tri_id_clicked();

    void on_tri_nombre_clicked();

    void on_historique_2_clicked();

    void on_lineEdit_id_equi_modif_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    equipements Equi;
    QCompleter *stringcompleter,*modelcompleter;
};
#endif // MAINWINDOW_H
