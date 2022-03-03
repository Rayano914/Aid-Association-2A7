#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "activites.h"

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


    void on_ajouter_act_clicked();

    void on_affiche_act_clicked();

    void on_modifier_act_clicked();

    void on_supprimer_act_clicked();

    void on_return_2_clicked();


    void on_ajouter_activite_clicked();

    void on_modifier_activite_clicked();

    void on_supprimer_activite_clicked();

    void on_pushButton_clicked();

    void on_ajouteractivite_clicked();

    void on_pushButton_2_clicked();

    void on_supprimer_employe_clicked();

private:
    Ui::MainWindow *ui;
    activite act;
};
#endif // MAINWINDOW_H

