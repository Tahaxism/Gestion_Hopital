/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnGererPatients;
    QPushButton *btnGererMedecins;
    QPushButton *btnGererRendezVous;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        btnGererPatients = new QPushButton(centralwidget);
        btnGererPatients->setObjectName("btnGererPatients");

        verticalLayout->addWidget(btnGererPatients);

        btnGererMedecins = new QPushButton(centralwidget);
        btnGererMedecins->setObjectName("btnGererMedecins");

        verticalLayout->addWidget(btnGererMedecins);

        btnGererRendezVous = new QPushButton(centralwidget);
        btnGererRendezVous->setObjectName("btnGererRendezVous");

        verticalLayout->addWidget(btnGererRendezVous);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion Hospitali\303\250re", nullptr));
        btnGererPatients->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les Patients", nullptr));
        btnGererMedecins->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les M\303\251decins", nullptr));
        btnGererRendezVous->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les Rendez-vous", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
