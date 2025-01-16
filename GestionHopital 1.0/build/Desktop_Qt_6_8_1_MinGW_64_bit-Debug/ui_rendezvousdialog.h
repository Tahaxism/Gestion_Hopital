/********************************************************************************
** Form generated from reading UI file 'rendezvousdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDEZVOUSDIALOG_H
#define UI_RENDEZVOUSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RendezVousDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxForm;
    QGridLayout *gridLayout;
    QLabel *labelPatient;
    QComboBox *comboBoxPatient;
    QLabel *labelMedecin;
    QComboBox *comboBoxMedecin;
    QLabel *labelDate;
    QDateEdit *dateEdit;
    QLabel *labelHeure;
    QTimeEdit *timeEdit;
    QLabel *labelMotif;
    QTextEdit *textEditMotif;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAjouter;
    QPushButton *btnSupprimer;
    QTableWidget *tableWidgetRendezVous;

    void setupUi(QDialog *RendezVousDialog)
    {
        if (RendezVousDialog->objectName().isEmpty())
            RendezVousDialog->setObjectName("RendezVousDialog");
        RendezVousDialog->resize(700, 500);
        verticalLayout = new QVBoxLayout(RendezVousDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxForm = new QGroupBox(RendezVousDialog);
        groupBoxForm->setObjectName("groupBoxForm");
        gridLayout = new QGridLayout(groupBoxForm);
        gridLayout->setObjectName("gridLayout");
        labelPatient = new QLabel(groupBoxForm);
        labelPatient->setObjectName("labelPatient");

        gridLayout->addWidget(labelPatient, 0, 0, 1, 1);

        comboBoxPatient = new QComboBox(groupBoxForm);
        comboBoxPatient->setObjectName("comboBoxPatient");

        gridLayout->addWidget(comboBoxPatient, 0, 1, 1, 1);

        labelMedecin = new QLabel(groupBoxForm);
        labelMedecin->setObjectName("labelMedecin");

        gridLayout->addWidget(labelMedecin, 1, 0, 1, 1);

        comboBoxMedecin = new QComboBox(groupBoxForm);
        comboBoxMedecin->setObjectName("comboBoxMedecin");

        gridLayout->addWidget(comboBoxMedecin, 1, 1, 1, 1);

        labelDate = new QLabel(groupBoxForm);
        labelDate->setObjectName("labelDate");

        gridLayout->addWidget(labelDate, 2, 0, 1, 1);

        dateEdit = new QDateEdit(groupBoxForm);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

        labelHeure = new QLabel(groupBoxForm);
        labelHeure->setObjectName("labelHeure");

        gridLayout->addWidget(labelHeure, 3, 0, 1, 1);

        timeEdit = new QTimeEdit(groupBoxForm);
        timeEdit->setObjectName("timeEdit");

        gridLayout->addWidget(timeEdit, 3, 1, 1, 1);

        labelMotif = new QLabel(groupBoxForm);
        labelMotif->setObjectName("labelMotif");

        gridLayout->addWidget(labelMotif, 4, 0, 1, 1);

        textEditMotif = new QTextEdit(groupBoxForm);
        textEditMotif->setObjectName("textEditMotif");

        gridLayout->addWidget(textEditMotif, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnAjouter = new QPushButton(groupBoxForm);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout->addWidget(btnAjouter);

        btnSupprimer = new QPushButton(groupBoxForm);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout->addWidget(btnSupprimer);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);


        verticalLayout->addWidget(groupBoxForm);

        tableWidgetRendezVous = new QTableWidget(RendezVousDialog);
        if (tableWidgetRendezVous->columnCount() < 6)
            tableWidgetRendezVous->setColumnCount(6);
        tableWidgetRendezVous->setObjectName("tableWidgetRendezVous");
        tableWidgetRendezVous->setColumnCount(6);

        verticalLayout->addWidget(tableWidgetRendezVous);


        retranslateUi(RendezVousDialog);

        QMetaObject::connectSlotsByName(RendezVousDialog);
    } // setupUi

    void retranslateUi(QDialog *RendezVousDialog)
    {
        RendezVousDialog->setWindowTitle(QCoreApplication::translate("RendezVousDialog", "Gestion des Rendez-vous", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("RendezVousDialog", "Formulaire Rendez-vous", nullptr));
        labelPatient->setText(QCoreApplication::translate("RendezVousDialog", "Patient :", nullptr));
        labelMedecin->setText(QCoreApplication::translate("RendezVousDialog", "M\303\251decin :", nullptr));
        labelDate->setText(QCoreApplication::translate("RendezVousDialog", "Date :", nullptr));
        labelHeure->setText(QCoreApplication::translate("RendezVousDialog", "Heure :", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("RendezVousDialog", "HH:mm", nullptr));
        labelMotif->setText(QCoreApplication::translate("RendezVousDialog", "Motif :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("RendezVousDialog", "Ajouter", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("RendezVousDialog", "Supprimer", nullptr));
        tableWidgetRendezVous->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("RendezVousDialog", "ID", nullptr),
            QCoreApplication::translate("RendezVousDialog", "Patient", nullptr),
            QCoreApplication::translate("RendezVousDialog", "M\303\251decin", nullptr),
            QCoreApplication::translate("RendezVousDialog", "Date", nullptr),
            QCoreApplication::translate("RendezVousDialog", "Heure", nullptr),
            QCoreApplication::translate("RendezVousDialog", "Motif", nullptr)}));
    } // retranslateUi

};

namespace Ui {
    class RendezVousDialog: public Ui_RendezVousDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDEZVOUSDIALOG_H
