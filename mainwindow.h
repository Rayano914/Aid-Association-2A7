#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
