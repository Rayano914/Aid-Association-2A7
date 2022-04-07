#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "caisse.h"
#include <QSqlQueryModel>
#include<QCompleter>
#include<QDirModel>
#include <QtCharts> //stat
#include <QChartView> //stat
#include<QLineSeries> //stat
#include "stat_caisse.h"
#include <QtGlobal>
#include <cstdlib>
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


    void on_supprimer_caisses_clicked();

    void on_modifier_caisses_clicked();

    void on_afficher_caisses_clicked();

    void on_ajouter_caisses_clicked();

    void on_fleche_clicked();

    void on_ajoute_caisse_clicked();

    void on_supprimer_caisse_clicked();

    void on_modifier_caisse_clicked();
     void on_historique_3_clicked();

     void on_toolButton_2_clicked();

     void on_tablecaisse_2_clicked(const QModelIndex &index);

     void on_modifier_caisse_2_clicked();

     void on_lineEdit_12_textEdited(const QString &arg1);

     void on_toolButton_6_clicked();

     void on_modif_clicked();

     void on_toolButton_5_clicked();

     void on_leidoperation_2_activated(const QString &arg1);

     void on_modifier_caisse_3_clicked();

     void on_toolButton_7_clicked();


private slots:
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

    void on_pushButton_clicked();

    void on_sin_2_clicked();

    void on_cos_2_clicked();

    void on_tan_2_clicked();

    void on_asin_2_clicked();

    void on_acos_2_clicked();

    void on_atan_2_clicked();



    void on_lineEdit_12_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    caisse c;
     QCompleter *stringcompleter,*modelcompleter;
     stat_caisse *third;
    qreal n,n1,r,cp;
    qint32 flag,t;
    char o;

};
#endif // MAINWINDOW_H
