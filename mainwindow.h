#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

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

private:
    Ui::MainWindow *ui;
    Employe Empl;
};
#endif // MAINWINDOW_H
