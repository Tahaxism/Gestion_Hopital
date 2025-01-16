/********************************************************************************
** Form generated from reading UI file 'patientdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTDIALOG_H
#define UI_PATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxPatientForm;
    QGridLayout *gridLayout;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QLabel *labelPrenom;
    QLineEdit *lineEditPrenom;
    QLabel *labelDateNaissance;
    QDateEdit *dateEditNaissance;
    QLabel *labelTelephone;
    QLineEdit *lineEditTelephone;
    QLabel *labelAdresse;
    QTextEdit *textEditAdresse;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QTableWidget *tableWidgetPatients;

    void setupUi(QWidget *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName("PatientDialog");
        PatientDialog->resize(600, 450);
        verticalLayout = new QVBoxLayout(PatientDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxPatientForm = new QGroupBox(PatientDialog);
        groupBoxPatientForm->setObjectName("groupBoxPatientForm");
        gridLayout = new QGridLayout(groupBoxPatientForm);
        gridLayout->setObjectName("gridLayout");
        labelNom = new QLabel(groupBoxPatientForm);
        labelNom->setObjectName("labelNom");

        gridLayout->addWidget(labelNom, 0, 0, 1, 1);

        lineEditNom = new QLineEdit(groupBoxPatientForm);
        lineEditNom->setObjectName("lineEditNom");

        gridLayout->addWidget(lineEditNom, 0, 1, 1, 1);

        labelPrenom = new QLabel(groupBoxPatientForm);
        labelPrenom->setObjectName("labelPrenom");

        gridLayout->addWidget(labelPrenom, 1, 0, 1, 1);

        lineEditPrenom = new QLineEdit(groupBoxPatientForm);
        lineEditPrenom->setObjectName("lineEditPrenom");

        gridLayout->addWidget(lineEditPrenom, 1, 1, 1, 1);

        labelDateNaissance = new QLabel(groupBoxPatientForm);
        labelDateNaissance->setObjectName("labelDateNaissance");

        gridLayout->addWidget(labelDateNaissance, 2, 0, 1, 1);

        dateEditNaissance = new QDateEdit(groupBoxPatientForm);
        dateEditNaissance->setObjectName("dateEditNaissance");

        gridLayout->addWidget(dateEditNaissance, 2, 1, 1, 1);

        labelTelephone = new QLabel(groupBoxPatientForm);
        labelTelephone->setObjectName("labelTelephone");

        gridLayout->addWidget(labelTelephone, 3, 0, 1, 1);

        lineEditTelephone = new QLineEdit(groupBoxPatientForm);
        lineEditTelephone->setObjectName("lineEditTelephone");

        gridLayout->addWidget(lineEditTelephone, 3, 1, 1, 1);

        labelAdresse = new QLabel(groupBoxPatientForm);
        labelAdresse->setObjectName("labelAdresse");

        gridLayout->addWidget(labelAdresse, 4, 0, 1, 1);

        textEditAdresse = new QTextEdit(groupBoxPatientForm);
        textEditAdresse->setObjectName("textEditAdresse");

        gridLayout->addWidget(textEditAdresse, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAjouter = new QPushButton(groupBoxPatientForm);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxPatientForm);
        btnModifier->setObjectName("btnModifier");

        horizontalLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxPatientForm);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout->addWidget(btnSupprimer);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);


        verticalLayout->addWidget(groupBoxPatientForm);

        tableWidgetPatients = new QTableWidget(PatientDialog);
        tableWidgetPatients->setObjectName("tableWidgetPatients");
        tableWidgetPatients->setColumnCount(6);

        verticalLayout->addWidget(tableWidgetPatients);


        retranslateUi(PatientDialog);

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QWidget *PatientDialog)
    {
        PatientDialog->setWindowTitle(QCoreApplication::translate("PatientDialog", "Gestion des Patients", nullptr));
        groupBoxPatientForm->setTitle(QCoreApplication::translate("PatientDialog", "Formulaire Patient", nullptr));
        labelNom->setText(QCoreApplication::translate("PatientDialog", "Nom :", nullptr));
        labelPrenom->setText(QCoreApplication::translate("PatientDialog", "Pr\303\251nom :", nullptr));
        labelDateNaissance->setText(QCoreApplication::translate("PatientDialog", "Date de Naissance :", nullptr));
        labelTelephone->setText(QCoreApplication::translate("PatientDialog", "T\303\251l\303\251phone :", nullptr));
        labelAdresse->setText(QCoreApplication::translate("PatientDialog", "Adresse :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("PatientDialog", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("PatientDialog", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("PatientDialog", "Supprimer", nullptr));
        tableWidgetPatients->setHorizontalHeaderLabels(QStringList{
            QCoreApplication::translate("PatientDialog", "ID", nullptr),
            QCoreApplication::translate("PatientDialog", "Nom", nullptr),
            QCoreApplication::translate("PatientDialog", "Pr\303\251nom", nullptr),
            QCoreApplication::translate("PatientDialog", "Date de Naissance", nullptr),
            QCoreApplication::translate("PatientDialog", "T\303\251l\303\251phone", nullptr),
            QCoreApplication::translate("PatientDialog", "Adresse", nullptr)});
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
