/********************************************************************************
** Form generated from reading UI file 'medecindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDECINDIALOG_H
#define UI_MEDECINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MedecinDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxMedecinForm;
    QGridLayout *gridLayout;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QLabel *labelPrenom;
    QLineEdit *lineEditPrenom;
    QLabel *labelSpecialite;
    QLineEdit *lineEditSpecialite;
    QLabel *labelTelephone;
    QLineEdit *lineEditTelephone;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QTableWidget *tableWidgetMedecins;

    void setupUi(QWidget *MedecinDialog)
    {
        if (MedecinDialog->objectName().isEmpty())
            MedecinDialog->setObjectName("MedecinDialog");
        MedecinDialog->resize(600, 450);
        verticalLayout = new QVBoxLayout(MedecinDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxMedecinForm = new QGroupBox(MedecinDialog);
        groupBoxMedecinForm->setObjectName("groupBoxMedecinForm");
        gridLayout = new QGridLayout(groupBoxMedecinForm);
        gridLayout->setObjectName("gridLayout");
        labelNom = new QLabel(groupBoxMedecinForm);
        labelNom->setObjectName("labelNom");

        gridLayout->addWidget(labelNom, 0, 0, 1, 1);

        lineEditNom = new QLineEdit(groupBoxMedecinForm);
        lineEditNom->setObjectName("lineEditNom");

        gridLayout->addWidget(lineEditNom, 0, 1, 1, 1);

        labelPrenom = new QLabel(groupBoxMedecinForm);
        labelPrenom->setObjectName("labelPrenom");

        gridLayout->addWidget(labelPrenom, 1, 0, 1, 1);

        lineEditPrenom = new QLineEdit(groupBoxMedecinForm);
        lineEditPrenom->setObjectName("lineEditPrenom");

        gridLayout->addWidget(lineEditPrenom, 1, 1, 1, 1);

        labelSpecialite = new QLabel(groupBoxMedecinForm);
        labelSpecialite->setObjectName("labelSpecialite");

        gridLayout->addWidget(labelSpecialite, 2, 0, 1, 1);

        lineEditSpecialite = new QLineEdit(groupBoxMedecinForm);
        lineEditSpecialite->setObjectName("lineEditSpecialite");

        gridLayout->addWidget(lineEditSpecialite, 2, 1, 1, 1);

        labelTelephone = new QLabel(groupBoxMedecinForm);
        labelTelephone->setObjectName("labelTelephone");

        gridLayout->addWidget(labelTelephone, 3, 0, 1, 1);

        lineEditTelephone = new QLineEdit(groupBoxMedecinForm);
        lineEditTelephone->setObjectName("lineEditTelephone");

        gridLayout->addWidget(lineEditTelephone, 3, 1, 1, 1);

        labelEmail = new QLabel(groupBoxMedecinForm);
        labelEmail->setObjectName("labelEmail");

        gridLayout->addWidget(labelEmail, 4, 0, 1, 1);

        lineEditEmail = new QLineEdit(groupBoxMedecinForm);
        lineEditEmail->setObjectName("lineEditEmail");

        gridLayout->addWidget(lineEditEmail, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAjouter = new QPushButton(groupBoxMedecinForm);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxMedecinForm);
        btnModifier->setObjectName("btnModifier");

        horizontalLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxMedecinForm);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout->addWidget(btnSupprimer);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);


        verticalLayout->addWidget(groupBoxMedecinForm);

        tableWidgetMedecins = new QTableWidget(MedecinDialog);
        tableWidgetMedecins->setObjectName("tableWidgetMedecins");
        tableWidgetMedecins->setColumnCount(6);

        verticalLayout->addWidget(tableWidgetMedecins);


        retranslateUi(MedecinDialog);

        QMetaObject::connectSlotsByName(MedecinDialog);
    } // setupUi

    void retranslateUi(QWidget *MedecinDialog)
    {
        MedecinDialog->setWindowTitle(QCoreApplication::translate("MedecinDialog", "Gestion des M\303\251decins", nullptr));
        groupBoxMedecinForm->setTitle(QCoreApplication::translate("MedecinDialog", "Formulaire M\303\251decin", nullptr));
        labelNom->setText(QCoreApplication::translate("MedecinDialog", "Nom :", nullptr));
        labelPrenom->setText(QCoreApplication::translate("MedecinDialog", "Pr\303\251nom :", nullptr));
        labelSpecialite->setText(QCoreApplication::translate("MedecinDialog", "Sp\303\251cialit\303\251 :", nullptr));
        labelTelephone->setText(QCoreApplication::translate("MedecinDialog", "T\303\251l\303\251phone :", nullptr));
        labelEmail->setText(QCoreApplication::translate("MedecinDialog", "Email :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MedecinDialog", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("MedecinDialog", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MedecinDialog", "Supprimer", nullptr));
        tableWidgetMedecins->setHorizontalHeaderLabels(QStringList{
            QCoreApplication::translate("MedecinDialog", "ID", nullptr),
            QCoreApplication::translate("MedecinDialog", "Nom", nullptr),
            QCoreApplication::translate("MedecinDialog", "Pr\303\251nom", nullptr),
            QCoreApplication::translate("MedecinDialog", "Sp\303\251cialit\303\251", nullptr),
            QCoreApplication::translate("MedecinDialog", "T\303\251l\303\251phone", nullptr),
            QCoreApplication::translate("MedecinDialog", "Email", nullptr)});
    } // retranslateUi

};

namespace Ui {
    class MedecinDialog: public Ui_MedecinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDECINDIALOG_H
