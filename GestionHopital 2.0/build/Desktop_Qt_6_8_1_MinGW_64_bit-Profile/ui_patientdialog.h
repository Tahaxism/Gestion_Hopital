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
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PatientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxForm;
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
    QTableView *tableViewPatients;

    void setupUi(QDialog *PatientDialog)
    {
        if (PatientDialog->objectName().isEmpty())
            PatientDialog->setObjectName("PatientDialog");
        PatientDialog->setMinimumSize(QSize(800, 600));
        verticalLayout = new QVBoxLayout(PatientDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxForm = new QGroupBox(PatientDialog);
        groupBoxForm->setObjectName("groupBoxForm");
        gridLayout = new QGridLayout(groupBoxForm);
        gridLayout->setObjectName("gridLayout");
        labelNom = new QLabel(groupBoxForm);
        labelNom->setObjectName("labelNom");

        gridLayout->addWidget(labelNom, 0, 0, 1, 1);

        lineEditNom = new QLineEdit(groupBoxForm);
        lineEditNom->setObjectName("lineEditNom");

        gridLayout->addWidget(lineEditNom, 0, 1, 1, 1);

        labelPrenom = new QLabel(groupBoxForm);
        labelPrenom->setObjectName("labelPrenom");

        gridLayout->addWidget(labelPrenom, 1, 0, 1, 1);

        lineEditPrenom = new QLineEdit(groupBoxForm);
        lineEditPrenom->setObjectName("lineEditPrenom");

        gridLayout->addWidget(lineEditPrenom, 1, 1, 1, 1);

        labelDateNaissance = new QLabel(groupBoxForm);
        labelDateNaissance->setObjectName("labelDateNaissance");

        gridLayout->addWidget(labelDateNaissance, 2, 0, 1, 1);

        dateEditNaissance = new QDateEdit(groupBoxForm);
        dateEditNaissance->setObjectName("dateEditNaissance");

        gridLayout->addWidget(dateEditNaissance, 2, 1, 1, 1);

        labelTelephone = new QLabel(groupBoxForm);
        labelTelephone->setObjectName("labelTelephone");

        gridLayout->addWidget(labelTelephone, 3, 0, 1, 1);

        lineEditTelephone = new QLineEdit(groupBoxForm);
        lineEditTelephone->setObjectName("lineEditTelephone");

        gridLayout->addWidget(lineEditTelephone, 3, 1, 1, 1);

        labelAdresse = new QLabel(groupBoxForm);
        labelAdresse->setObjectName("labelAdresse");

        gridLayout->addWidget(labelAdresse, 4, 0, 1, 1);

        textEditAdresse = new QTextEdit(groupBoxForm);
        textEditAdresse->setObjectName("textEditAdresse");

        gridLayout->addWidget(textEditAdresse, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAjouter = new QPushButton(groupBoxForm);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxForm);
        btnModifier->setObjectName("btnModifier");

        horizontalLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxForm);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout->addWidget(btnSupprimer);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);


        verticalLayout->addWidget(groupBoxForm);

        tableViewPatients = new QTableView(PatientDialog);
        tableViewPatients->setObjectName("tableViewPatients");

        verticalLayout->addWidget(tableViewPatients);


        retranslateUi(PatientDialog);

        QMetaObject::connectSlotsByName(PatientDialog);
    } // setupUi

    void retranslateUi(QDialog *PatientDialog)
    {
        PatientDialog->setWindowTitle(QCoreApplication::translate("PatientDialog", "Gestion des Patients", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("PatientDialog", "Formulaire Patient", nullptr));
        labelNom->setText(QCoreApplication::translate("PatientDialog", "Nom :", nullptr));
        labelPrenom->setText(QCoreApplication::translate("PatientDialog", "Pr\303\251nom :", nullptr));
        labelDateNaissance->setText(QCoreApplication::translate("PatientDialog", "Date de naissance :", nullptr));
        labelTelephone->setText(QCoreApplication::translate("PatientDialog", "T\303\251l\303\251phone :", nullptr));
        labelAdresse->setText(QCoreApplication::translate("PatientDialog", "Adresse :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("PatientDialog", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("PatientDialog", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("PatientDialog", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientDialog: public Ui_PatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTDIALOG_H
