#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpSocket>
#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Duscene;
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

    void on_trier_clicked();
    void on_rech_textChanged(const QString &arg1);
    void on_retour_5_clicked();



    void on_hist_clicked();

    void on_chatbox_clicked();

    void on_connecter_clicked();

    void on_pushButton_clicked();

    void on_retour_6_clicked();

    void on_chatbox_2_clicked();

    void on_modifier_don_2_clicked();
    void update_label();

    void on_retour_7_clicked();

private:
    Ui::MainWindow *ui;

    QTcpSocket *mSocket;

    QByteArray data;
    Duscene *mScene;

    arduino A;

    QString res="";
};
#endif // MAINWINDOW_H
