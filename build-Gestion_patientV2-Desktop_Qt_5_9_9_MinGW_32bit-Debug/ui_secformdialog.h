/********************************************************************************
** Form generated from reading UI file 'secformdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECFORMDIALOG_H
#define UI_SECFORMDIALOG_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SECFORMDialog
{
public:
    QQuickWidget *quickWidget;

    void setupUi(QDialog *SECFORMDialog)
    {
        if (SECFORMDialog->objectName().isEmpty())
            SECFORMDialog->setObjectName(QStringLiteral("SECFORMDialog"));
        SECFORMDialog->resize(591, 481);
        quickWidget = new QQuickWidget(SECFORMDialog);
        quickWidget->setObjectName(QStringLiteral("quickWidget"));
        quickWidget->setGeometry(QRect(10, 10, 571, 461));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        retranslateUi(SECFORMDialog);

        QMetaObject::connectSlotsByName(SECFORMDialog);
    } // setupUi

    void retranslateUi(QDialog *SECFORMDialog)
    {
        SECFORMDialog->setWindowTitle(QApplication::translate("SECFORMDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SECFORMDialog: public Ui_SECFORMDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECFORMDIALOG_H
