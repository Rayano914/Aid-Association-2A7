#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "equipements.h"

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


    void on_ajouter_equipement_clicked();

    void on_ajouter_equipements_clicked();

    void on_supprimer_equipements_clicked();

    void on_modifier_equipements_clicked();

    void on_affiche_equipements_clicked();

    void on_return_2_clicked();

    void on_modifier_equipement_clicked();

    void on_supprimer_equipement_clicked();

private:
    Ui::MainWindow *ui;
    equipements Equi;
};
#endif // MAINWINDOW_H
