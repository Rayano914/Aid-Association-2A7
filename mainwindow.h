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

private:
    Ui::MainWindow *ui;
    activite act;
};
#endif // MAINWINDOW_H
