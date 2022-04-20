/********************************************************************************
** Form generated from reading UI file 'gestion_patient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_PATIENT_H
#define UI_GESTION_PATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gestion_patient
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lecin;
    QLineEdit *lenom;
    QLineEdit *leprenom;
    QLineEdit *leage;
    QPushButton *ajoute_pati;
    QToolButton *retour;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lenumchambre;
    QLineEdit *lecontact;
    QDateEdit *dateEdit;
    QComboBox *comboBox_2;
    QToolButton *toolButton_4;
    QCalendarWidget *calendarAjout;
    QLabel *Qr;
    QWidget *page_3;
    QTextBrowser *historique;
    QToolButton *toolButton_6;
    QWidget *page;
    QPushButton *add_patient;
    QPushButton *dispaly_patients;
    QPushButton *update_patients;
    QPushButton *delete_patients;
    QWidget *stackedWidgetPage2;
    QToolButton *toolButton_2;
    QLineEdit *lineEdit_12;
    QToolButton *toolButton_5;
    QToolButton *retour_2;
    QTableView *tableView;
    QComboBox *comboBox_4;
    QToolButton *toolButton;
    QLabel *label_20;
    QLabel *qrcode;
    QPushButton *qrCode;
    QPushButton *calendrier;
    QWidget *stackedWidgetPage3;
    QPushButton *modifier_pati;
    QLabel *label_7;
    QLineEdit *leage2;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *leprenom2;
    QLineEdit *lenom2;
    QLabel *label_10;
    QToolButton *retour_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *lenum_chambre2;
    QLabel *label_17;
    QLineEdit *lecontact2;
    QDateEdit *dateEdit_2;
    QComboBox *comboBox;
    QComboBox *comboBox_3;
    QLabel *Qrmodif;
    QLineEdit *leqr;
    QWidget *stackedWidgetPage4;
    QPushButton *supprimer_patient;
    QLabel *label_6;
    QToolButton *retour_4;
    QComboBox *comboBox_sup;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lenom3;
    QLineEdit *leprenom3;
    QWidget *page_2;
    QPushButton *saveButton;
    QLabel *label_21;
    QLineEdit *taskLineEdit;
    QCalendarWidget *calendarWidget;
    QPushButton *addButton;
    QTableView *tablC;
    QDateEdit *dateEdit_C;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gestion_patient)
    {
        if (Gestion_patient->objectName().isEmpty())
            Gestion_patient->setObjectName(QStringLiteral("Gestion_patient"));
        Gestion_patient->resize(1109, 768);
        centralwidget = new QWidget(Gestion_patient);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 971, 671));
        stackedWidget = new QStackedWidget(groupBox);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(50, 30, 891, 621));
        stackedWidget->setStyleSheet(QLatin1String("QtabWidget{\n"
"	background-image: url(:/img/return.png);\n"
"border-radius:30px;\n"
"border-color:rgb(0, 0, 0)\n"
"}\n"
"*{\n"
"font-family:century gothic;\n"
"font-size:17px;\n"
"}\n"
"QLineEdit\n"
"{\n"
"border-radius:11px;\n"
"border-color:rgb(0, 0, 0);\n"
"\n"
"}\n"
"QPushButton\n"
"{\n"
"background:rgb(139, 4, 35);\n"
"border-radius:13px;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"background:rgb(216, 5, 37);\n"
"border-radius:13px;\n"
"color:rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"background:rgb(139, 4, 35);\n"
"border-radius:15px;\n"
"}\n"
"QToolButton:hover{\n"
"background:rgb(216, 5, 37);\n"
"border-radius:15px;\n"
"}"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        label = new QLabel(stackedWidgetPage1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 60, 151, 31));
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 120, 131, 31));
        label_3 = new QLabel(stackedWidgetPage1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 180, 131, 31));
        label_4 = new QLabel(stackedWidgetPage1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 240, 151, 31));
        lecin = new QLineEdit(stackedWidgetPage1);
        lecin->setObjectName(QStringLiteral("lecin"));
        lecin->setGeometry(QRect(280, 60, 211, 31));
        lenom = new QLineEdit(stackedWidgetPage1);
        lenom->setObjectName(QStringLiteral("lenom"));
        lenom->setGeometry(QRect(280, 120, 211, 31));
        leprenom = new QLineEdit(stackedWidgetPage1);
        leprenom->setObjectName(QStringLiteral("leprenom"));
        leprenom->setGeometry(QRect(280, 180, 211, 31));
        leage = new QLineEdit(stackedWidgetPage1);
        leage->setObjectName(QStringLiteral("leage"));
        leage->setGeometry(QRect(280, 240, 211, 31));
        ajoute_pati = new QPushButton(stackedWidgetPage1);
        ajoute_pati->setObjectName(QStringLiteral("ajoute_pati"));
        ajoute_pati->setGeometry(QRect(310, 540, 211, 41));
        retour = new QToolButton(stackedWidgetPage1);
        retour->setObjectName(QStringLiteral("retour"));
        retour->setGeometry(QRect(710, 10, 61, 41));
        retour->setStyleSheet(QLatin1String("\n"
"background-color: rgb(139, 4, 35);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/re.png"), QSize(), QIcon::Normal, QIcon::Off);
        retour->setIcon(icon);
        retour->setIconSize(QSize(30, 30));
        label_5 = new QLabel(stackedWidgetPage1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 300, 121, 20));
        label_11 = new QLabel(stackedWidgetPage1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 370, 121, 20));
        label_12 = new QLabel(stackedWidgetPage1);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(120, 430, 131, 20));
        label_13 = new QLabel(stackedWidgetPage1);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(120, 480, 131, 20));
        lenumchambre = new QLineEdit(stackedWidgetPage1);
        lenumchambre->setObjectName(QStringLiteral("lenumchambre"));
        lenumchambre->setGeometry(QRect(280, 430, 211, 31));
        lecontact = new QLineEdit(stackedWidgetPage1);
        lecontact->setObjectName(QStringLiteral("lecontact"));
        lecontact->setGeometry(QRect(280, 480, 211, 31));
        dateEdit = new QDateEdit(stackedWidgetPage1);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(280, 350, 211, 51));
        dateEdit->setStyleSheet(QStringLiteral(""));
        comboBox_2 = new QComboBox(stackedWidgetPage1);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(282, 300, 211, 31));
        toolButton_4 = new QToolButton(stackedWidgetPage1);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(586, 10, 51, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/1200px-OOjs_UI_icon_history.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon1);
        toolButton_4->setIconSize(QSize(30, 30));
        calendarAjout = new QCalendarWidget(stackedWidgetPage1);
        calendarAjout->setObjectName(QStringLiteral("calendarAjout"));
        calendarAjout->setGeometry(QRect(540, 200, 304, 261));
        Qr = new QLabel(stackedWidgetPage1);
        Qr->setObjectName(QStringLiteral("Qr"));
        Qr->setGeometry(QRect(590, 495, 161, 101));
        stackedWidget->addWidget(stackedWidgetPage1);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        historique = new QTextBrowser(page_3);
        historique->setObjectName(QStringLiteral("historique"));
        historique->setGeometry(QRect(55, 50, 701, 461));
        toolButton_6 = new QToolButton(page_3);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(800, 40, 71, 41));
        toolButton_6->setStyleSheet(QLatin1String("background-color: rgb(139, 4, 35);\n"
""));
        toolButton_6->setIcon(icon);
        toolButton_6->setIconSize(QSize(30, 30));
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        add_patient = new QPushButton(page);
        add_patient->setObjectName(QStringLiteral("add_patient"));
        add_patient->setGeometry(QRect(350, 110, 141, 41));
        add_patient->setLayoutDirection(Qt::LeftToRight);
        dispaly_patients = new QPushButton(page);
        dispaly_patients->setObjectName(QStringLiteral("dispaly_patients"));
        dispaly_patients->setGeometry(QRect(350, 200, 141, 41));
        update_patients = new QPushButton(page);
        update_patients->setObjectName(QStringLiteral("update_patients"));
        update_patients->setGeometry(QRect(350, 290, 141, 41));
        delete_patients = new QPushButton(page);
        delete_patients->setObjectName(QStringLiteral("delete_patients"));
        delete_patients->setGeometry(QRect(350, 380, 141, 41));
        stackedWidget->addWidget(page);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QStringLiteral("stackedWidgetPage2"));
        toolButton_2 = new QToolButton(stackedWidgetPage2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(200, 20, 31, 31));
        toolButton_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/1024px-Search_Icon.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(25, 25));
        lineEdit_12 = new QLineEdit(stackedWidgetPage2);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(30, 20, 191, 31));
        toolButton_5 = new QToolButton(stackedWidgetPage2);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(550, 20, 31, 31));
        toolButton_5->setStyleSheet(QLatin1String("QToolButton { /* all types of tool button */\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/31096.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon3);
        toolButton_5->setIconSize(QSize(30, 25));
        retour_2 = new QToolButton(stackedWidgetPage2);
        retour_2->setObjectName(QStringLiteral("retour_2"));
        retour_2->setGeometry(QRect(740, 20, 51, 41));
        retour_2->setTabletTracking(false);
        retour_2->setAutoFillBackground(false);
        retour_2->setStyleSheet(QLatin1String("\n"
"background-color: rgb(139, 4, 35);\n"
"\n"
"\n"
"\n"
""));
        retour_2->setIcon(icon);
        retour_2->setIconSize(QSize(30, 30));
        retour_2->setCheckable(false);
        retour_2->setAutoExclusive(false);
        retour_2->setAutoRaise(false);
        tableView = new QTableView(stackedWidgetPage2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEnabled(true);
        tableView->setGeometry(QRect(-5, 80, 891, 361));
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        comboBox_4 = new QComboBox(stackedWidgetPage2);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(370, 21, 151, 31));
        toolButton = new QToolButton(stackedWidgetPage2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(600, 21, 31, 31));
        toolButton->setStyleSheet(QLatin1String("QToolButton { /* all types of tool button */\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/t\303\251l\303\251chargement__2_-removebg-preview - Copie.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(30, 25));
        label_20 = new QLabel(stackedWidgetPage2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(270, 30, 101, 16));
        qrcode = new QLabel(stackedWidgetPage2);
        qrcode->setObjectName(QStringLiteral("qrcode"));
        qrcode->setGeometry(QRect(40, 460, 201, 141));
        qrCode = new QPushButton(stackedWidgetPage2);
        qrCode->setObjectName(QStringLiteral("qrCode"));
        qrCode->setGeometry(QRect(440, 470, 93, 41));
        calendrier = new QPushButton(stackedWidgetPage2);
        calendrier->setObjectName(QStringLiteral("calendrier"));
        calendrier->setGeometry(QRect(590, 470, 141, 41));
        stackedWidget->addWidget(stackedWidgetPage2);
        lineEdit_12->raise();
        toolButton_2->raise();
        toolButton_5->raise();
        retour_2->raise();
        tableView->raise();
        comboBox_4->raise();
        toolButton->raise();
        label_20->raise();
        qrcode->raise();
        qrCode->raise();
        calendrier->raise();
        stackedWidgetPage3 = new QWidget();
        stackedWidgetPage3->setObjectName(QStringLiteral("stackedWidgetPage3"));
        modifier_pati = new QPushButton(stackedWidgetPage3);
        modifier_pati->setObjectName(QStringLiteral("modifier_pati"));
        modifier_pati->setGeometry(QRect(300, 500, 211, 41));
        label_7 = new QLabel(stackedWidgetPage3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 210, 151, 31));
        leage2 = new QLineEdit(stackedWidgetPage3);
        leage2->setObjectName(QStringLiteral("leage2"));
        leage2->setGeometry(QRect(290, 210, 201, 31));
        label_8 = new QLabel(stackedWidgetPage3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 100, 141, 31));
        label_9 = new QLabel(stackedWidgetPage3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 150, 141, 31));
        leprenom2 = new QLineEdit(stackedWidgetPage3);
        leprenom2->setObjectName(QStringLiteral("leprenom2"));
        leprenom2->setGeometry(QRect(290, 150, 201, 31));
        lenom2 = new QLineEdit(stackedWidgetPage3);
        lenom2->setObjectName(QStringLiteral("lenom2"));
        lenom2->setGeometry(QRect(290, 100, 201, 31));
        lenom2->setStyleSheet(QStringLiteral(""));
        label_10 = new QLabel(stackedWidgetPage3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(140, 40, 151, 31));
        retour_3 = new QToolButton(stackedWidgetPage3);
        retour_3->setObjectName(QStringLiteral("retour_3"));
        retour_3->setGeometry(QRect(710, 20, 61, 41));
        retour_3->setStyleSheet(QStringLiteral("background-color: rgb(139, 4, 35);"));
        retour_3->setIcon(icon);
        retour_3->setIconSize(QSize(25, 25));
        label_14 = new QLabel(stackedWidgetPage3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(130, 280, 121, 16));
        label_15 = new QLabel(stackedWidgetPage3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(130, 330, 121, 20));
        label_16 = new QLabel(stackedWidgetPage3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(130, 380, 161, 20));
        lenum_chambre2 = new QLineEdit(stackedWidgetPage3);
        lenum_chambre2->setObjectName(QStringLiteral("lenum_chambre2"));
        lenum_chambre2->setGeometry(QRect(290, 380, 201, 31));
        label_17 = new QLabel(stackedWidgetPage3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(120, 440, 151, 20));
        lecontact2 = new QLineEdit(stackedWidgetPage3);
        lecontact2->setObjectName(QStringLiteral("lecontact2"));
        lecontact2->setGeometry(QRect(290, 440, 201, 31));
        dateEdit_2 = new QDateEdit(stackedWidgetPage3);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(290, 330, 201, 22));
        comboBox = new QComboBox(stackedWidgetPage3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(290, 40, 201, 31));
        comboBox_3 = new QComboBox(stackedWidgetPage3);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(292, 270, 191, 31));
        Qrmodif = new QLabel(stackedWidgetPage3);
        Qrmodif->setObjectName(QStringLiteral("Qrmodif"));
        Qrmodif->setGeometry(QRect(640, 410, 151, 111));
        leqr = new QLineEdit(stackedWidgetPage3);
        leqr->setObjectName(QStringLiteral("leqr"));
        leqr->setGeometry(QRect(320, 40, 113, 22));
        stackedWidget->addWidget(stackedWidgetPage3);
        leqr->raise();
        modifier_pati->raise();
        label_7->raise();
        leage2->raise();
        label_8->raise();
        label_9->raise();
        leprenom2->raise();
        lenom2->raise();
        label_10->raise();
        retour_3->raise();
        label_14->raise();
        label_15->raise();
        label_16->raise();
        lenum_chambre2->raise();
        label_17->raise();
        lecontact2->raise();
        dateEdit_2->raise();
        comboBox->raise();
        comboBox_3->raise();
        Qrmodif->raise();
        stackedWidgetPage4 = new QWidget();
        stackedWidgetPage4->setObjectName(QStringLiteral("stackedWidgetPage4"));
        supprimer_patient = new QPushButton(stackedWidgetPage4);
        supprimer_patient->setObjectName(QStringLiteral("supprimer_patient"));
        supprimer_patient->setGeometry(QRect(300, 360, 211, 41));
        label_6 = new QLabel(stackedWidgetPage4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 130, 151, 31));
        retour_4 = new QToolButton(stackedWidgetPage4);
        retour_4->setObjectName(QStringLiteral("retour_4"));
        retour_4->setGeometry(QRect(680, 30, 71, 41));
        retour_4->setStyleSheet(QLatin1String("\n"
"background-color: rgb(139, 4, 35);"));
        retour_4->setIcon(icon);
        retour_4->setIconSize(QSize(30, 30));
        comboBox_sup = new QComboBox(stackedWidgetPage4);
        comboBox_sup->setObjectName(QStringLiteral("comboBox_sup"));
        comboBox_sup->setGeometry(QRect(300, 130, 191, 31));
        label_18 = new QLabel(stackedWidgetPage4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(190, 200, 56, 16));
        label_19 = new QLabel(stackedWidgetPage4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(190, 270, 56, 16));
        lenom3 = new QLineEdit(stackedWidgetPage4);
        lenom3->setObjectName(QStringLiteral("lenom3"));
        lenom3->setGeometry(QRect(300, 190, 191, 31));
        leprenom3 = new QLineEdit(stackedWidgetPage4);
        leprenom3->setObjectName(QStringLiteral("leprenom3"));
        leprenom3->setGeometry(QRect(300, 260, 191, 31));
        stackedWidget->addWidget(stackedWidgetPage4);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        saveButton = new QPushButton(page_2);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(440, 490, 341, 28));
        saveButton->setStyleSheet(QLatin1String("border-radius:10px;\n"
"background-color: rgb(139, 4, 35);;\n"
"color:white;\n"
"font:11pt;"));
        label_21 = new QLabel(page_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(-40, 20, 851, 101));
        label_21->setStyleSheet(QLatin1String("font-size : 24pt;\n"
"background : rgb(139, 4, 35);\n"
"color:white;\n"
"border-radius:8px;"));
        label_21->setAlignment(Qt::AlignCenter);
        taskLineEdit = new QLineEdit(page_2);
        taskLineEdit->setObjectName(QStringLiteral("taskLineEdit"));
        taskLineEdit->setGeometry(QRect(440, 140, 241, 31));
        taskLineEdit->setStyleSheet(QStringLiteral("font:12pt;"));
        calendarWidget = new QCalendarWidget(page_2);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 150, 411, 311));
        calendarWidget->setStyleSheet(QStringLiteral("font:12pt;"));
        addButton = new QPushButton(page_2);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(690, 140, 93, 28));
        addButton->setStyleSheet(QLatin1String("border-radius:10px;\n"
"background-color: rgb(139, 4, 35);\n"
"color:white;\n"
""));
        tablC = new QTableView(page_2);
        tablC->setObjectName(QStringLiteral("tablC"));
        tablC->setGeometry(QRect(470, 220, 411, 192));
        dateEdit_C = new QDateEdit(page_2);
        dateEdit_C->setObjectName(QStringLiteral("dateEdit_C"));
        dateEdit_C->setGeometry(QRect(180, 490, 110, 22));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(830, 490, 41, 28));
        stackedWidget->addWidget(page_2);
        Gestion_patient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gestion_patient);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1109, 26));
        Gestion_patient->setMenuBar(menubar);
        statusbar = new QStatusBar(Gestion_patient);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Gestion_patient->setStatusBar(statusbar);

        retranslateUi(Gestion_patient);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Gestion_patient);
    } // setupUi

    void retranslateUi(QMainWindow *Gestion_patient)
    {
        Gestion_patient->setWindowTitle(QApplication::translate("Gestion_patient", "Gestion_patient", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Gestion_patient", "Gestion_Patient", Q_NULLPTR));
        label->setText(QApplication::translate("Gestion_patient", "CIN", Q_NULLPTR));
        label_2->setText(QApplication::translate("Gestion_patient", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("Gestion_patient", "Pr\303\251nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("Gestion_patient", "Age", Q_NULLPTR));
        ajoute_pati->setText(QApplication::translate("Gestion_patient", "Ajouter", Q_NULLPTR));
        retour->setText(QApplication::translate("Gestion_patient", "...", Q_NULLPTR));
        label_5->setText(QApplication::translate("Gestion_patient", "Type maladie", Q_NULLPTR));
        label_11->setText(QApplication::translate("Gestion_patient", "Rendez-vous", Q_NULLPTR));
        label_12->setText(QApplication::translate("Gestion_patient", "Num_chambre", Q_NULLPTR));
        label_13->setText(QApplication::translate("Gestion_patient", "Contact famille", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Gestion_patient", "Bonne Etat Sanitaire", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Diabete", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Arthrose", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Alzheimer", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Troubles anxieux", Q_NULLPTR)
        );
        toolButton_4->setText(QString());
        Qr->setText(QString());
        toolButton_6->setText(QString());
        add_patient->setText(QApplication::translate("Gestion_patient", "Ajouter", Q_NULLPTR));
        dispaly_patients->setText(QApplication::translate("Gestion_patient", "Afficher", Q_NULLPTR));
        update_patients->setText(QApplication::translate("Gestion_patient", "Modifier", Q_NULLPTR));
        delete_patients->setText(QApplication::translate("Gestion_patient", "Supprimer", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("Gestion_patient", "...", Q_NULLPTR));
        lineEdit_12->setPlaceholderText(QApplication::translate("Gestion_patient", " Recherche...", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("Gestion_patient", "...", Q_NULLPTR));
        retour_2->setText(QString());
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("Gestion_patient", "NOM", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "AGE", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "RENDEZ_VOUS", Q_NULLPTR)
        );
        toolButton->setText(QString());
        label_20->setText(QApplication::translate("Gestion_patient", "ORDER BY:", Q_NULLPTR));
        qrcode->setText(QString());
        qrCode->setText(QApplication::translate("Gestion_patient", "CODE QR", Q_NULLPTR));
        calendrier->setText(QApplication::translate("Gestion_patient", "Calendrier", Q_NULLPTR));
        modifier_pati->setText(QApplication::translate("Gestion_patient", "Modifier", Q_NULLPTR));
        label_7->setText(QApplication::translate("Gestion_patient", "Age", Q_NULLPTR));
        label_8->setText(QApplication::translate("Gestion_patient", "Nom", Q_NULLPTR));
        label_9->setText(QApplication::translate("Gestion_patient", "Prenom", Q_NULLPTR));
        label_10->setText(QApplication::translate("Gestion_patient", "CIN", Q_NULLPTR));
        retour_3->setText(QApplication::translate("Gestion_patient", "...", Q_NULLPTR));
        label_14->setText(QApplication::translate("Gestion_patient", "Type_maladie", Q_NULLPTR));
        label_15->setText(QApplication::translate("Gestion_patient", "Rendez_vous", Q_NULLPTR));
        label_16->setText(QApplication::translate("Gestion_patient", "Num_chambre", Q_NULLPTR));
        label_17->setText(QApplication::translate("Gestion_patient", "Contact_famille", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("Gestion_patient", "Bonne Etat Sanitaire", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Diabete", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Arthrose", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Alzheimer", Q_NULLPTR)
         << QApplication::translate("Gestion_patient", "Troubles anxieux", Q_NULLPTR)
        );
        Qrmodif->setText(QString());
        supprimer_patient->setText(QApplication::translate("Gestion_patient", "Supprimer", Q_NULLPTR));
        label_6->setText(QApplication::translate("Gestion_patient", "CIN", Q_NULLPTR));
        retour_4->setText(QApplication::translate("Gestion_patient", "...", Q_NULLPTR));
        label_18->setText(QApplication::translate("Gestion_patient", "Nom", Q_NULLPTR));
        label_19->setText(QApplication::translate("Gestion_patient", "Prenom", Q_NULLPTR));
        saveButton->setText(QApplication::translate("Gestion_patient", "Save Changes", Q_NULLPTR));
        label_21->setText(QApplication::translate("Gestion_patient", "Daily Task Planner", Q_NULLPTR));
        addButton->setText(QApplication::translate("Gestion_patient", "Add new", Q_NULLPTR));
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gestion_patient: public Ui_Gestion_patient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_PATIENT_H
