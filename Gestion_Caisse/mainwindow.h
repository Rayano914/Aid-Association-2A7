#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caisse.h"

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

    void on_pushButton_clicked();

    void on_afficher_clicked();

    void on_ajoute_caisse_clicked();

    void on_supprimer_caisse_clicked();

private:
    Ui::MainWindow *ui;
    caisse c;
};
#endif // MAINWINDOW_H
