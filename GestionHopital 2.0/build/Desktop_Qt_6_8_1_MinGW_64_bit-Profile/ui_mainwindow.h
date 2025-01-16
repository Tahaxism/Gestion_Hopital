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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayoutMain;
    QLabel *labelDate;
    QLabel *labelLogo;
    QFrame *lineSeparator;
    QGridLayout *gridLayoutButtons;
    QPushButton *btnGererPatients;
    QPushButton *btnGererMedecins;
    QPushButton *btnGererRendezVous;
    QPushButton *btnGererOperations;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutMain = new QVBoxLayout(centralwidget);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        labelDate = new QLabel(centralwidget);
        labelDate->setObjectName("labelDate");
        labelDate->setAlignment(Qt::AlignCenter);

        verticalLayoutMain->addWidget(labelDate);

        labelLogo = new QLabel(centralwidget);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setAlignment(Qt::AlignCenter);
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/icons/logo.png")));

        verticalLayoutMain->addWidget(labelLogo);

        lineSeparator = new QFrame(centralwidget);
        lineSeparator->setObjectName("lineSeparator");
        lineSeparator->setFrameShape(QFrame::HLine);
        lineSeparator->setFrameShadow(QFrame::Sunken);
        lineSeparator->setLineWidth(2);

        verticalLayoutMain->addWidget(lineSeparator);

        gridLayoutButtons = new QGridLayout();
        gridLayoutButtons->setObjectName("gridLayoutButtons");
        btnGererPatients = new QPushButton(centralwidget);
        btnGererPatients->setObjectName("btnGererPatients");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":icons/patient.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnGererPatients->setIcon(icon);
        btnGererPatients->setIconSize(QSize(32, 32));

        gridLayoutButtons->addWidget(btnGererPatients, 0, 0, 1, 1);

        btnGererMedecins = new QPushButton(centralwidget);
        btnGererMedecins->setObjectName("btnGererMedecins");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":icons/docteur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnGererMedecins->setIcon(icon1);
        btnGererMedecins->setIconSize(QSize(32, 32));

        gridLayoutButtons->addWidget(btnGererMedecins, 0, 1, 1, 1);

        btnGererRendezVous = new QPushButton(centralwidget);
        btnGererRendezVous->setObjectName("btnGererRendezVous");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":icons/rdv.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnGererRendezVous->setIcon(icon2);
        btnGererRendezVous->setIconSize(QSize(32, 32));

        gridLayoutButtons->addWidget(btnGererRendezVous, 1, 0, 1, 1);

        btnGererOperations = new QPushButton(centralwidget);
        btnGererOperations->setObjectName("btnGererOperations");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":icons/operation.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btnGererOperations->setIcon(icon3);
        btnGererOperations->setIconSize(QSize(32, 32));

        gridLayoutButtons->addWidget(btnGererOperations, 1, 1, 1, 1);


        verticalLayoutMain->addLayout(gridLayoutButtons);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion Hospitali\303\250re", nullptr));
        labelDate->setText(QCoreApplication::translate("MainWindow", "15 janvier 2025", nullptr));
        labelDate->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"        color: #333;\n"
"       ", nullptr));
        btnGererPatients->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les Patients", nullptr));
        btnGererMedecins->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les M\303\251decins", nullptr));
        btnGererRendezVous->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les Rendez-vous", nullptr));
        btnGererOperations->setText(QCoreApplication::translate("MainWindow", "G\303\251rer les Op\303\251rations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
