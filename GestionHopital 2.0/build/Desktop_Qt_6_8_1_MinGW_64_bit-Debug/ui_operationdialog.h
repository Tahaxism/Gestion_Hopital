/********************************************************************************
** Form generated from reading UI file 'operationdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONDIALOG_H
#define UI_OPERATIONDIALOG_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OperationDialog
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
    QLabel *labelDescription;
    QTextEdit *textEditDescription;
    QLabel *labelSalle;
    QLineEdit *lineEditSalle;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QTableView *tableView;

    void setupUi(QDialog *OperationDialog)
    {
        if (OperationDialog->objectName().isEmpty())
            OperationDialog->setObjectName("OperationDialog");
        OperationDialog->resize(800, 600);
        verticalLayout = new QVBoxLayout(OperationDialog);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxForm = new QGroupBox(OperationDialog);
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
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

        labelDescription = new QLabel(groupBoxForm);
        labelDescription->setObjectName("labelDescription");

        gridLayout->addWidget(labelDescription, 3, 0, 1, 1);

        textEditDescription = new QTextEdit(groupBoxForm);
        textEditDescription->setObjectName("textEditDescription");

        gridLayout->addWidget(textEditDescription, 3, 1, 1, 1);

        labelSalle = new QLabel(groupBoxForm);
        labelSalle->setObjectName("labelSalle");

        gridLayout->addWidget(labelSalle, 4, 0, 1, 1);

        lineEditSalle = new QLineEdit(groupBoxForm);
        lineEditSalle->setObjectName("lineEditSalle");

        gridLayout->addWidget(lineEditSalle, 4, 1, 1, 1);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnAjouter = new QPushButton(groupBoxForm);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayoutButtons->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxForm);
        btnModifier->setObjectName("btnModifier");

        horizontalLayoutButtons->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxForm);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayoutButtons->addWidget(btnSupprimer);


        gridLayout->addLayout(horizontalLayoutButtons, 5, 0, 1, 2);


        verticalLayout->addWidget(groupBoxForm);

        tableView = new QTableView(OperationDialog);
        tableView->setObjectName("tableView");
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);


        retranslateUi(OperationDialog);

        QMetaObject::connectSlotsByName(OperationDialog);
    } // setupUi

    void retranslateUi(QDialog *OperationDialog)
    {
        OperationDialog->setWindowTitle(QCoreApplication::translate("OperationDialog", "Gestion des Op\303\251rations", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("OperationDialog", "Formulaire Op\303\251ration", nullptr));
        labelPatient->setText(QCoreApplication::translate("OperationDialog", "Patient :", nullptr));
        labelMedecin->setText(QCoreApplication::translate("OperationDialog", "M\303\251decin :", nullptr));
        labelDate->setText(QCoreApplication::translate("OperationDialog", "Date :", nullptr));
        labelDescription->setText(QCoreApplication::translate("OperationDialog", "Description :", nullptr));
        labelSalle->setText(QCoreApplication::translate("OperationDialog", "Salle :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("OperationDialog", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("OperationDialog", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("OperationDialog", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperationDialog: public Ui_OperationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONDIALOG_H
