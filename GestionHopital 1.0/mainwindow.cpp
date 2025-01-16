#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patientdialog.h"
#include "medecindialog.h"
#include "rendezvousdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connexion du bouton pour les patients
    connect(ui->btnGererPatients, &QPushButton::clicked, this, &MainWindow::ouvrirPatientDialog);

    // Connexion du bouton pour les médecins
    connect(ui->btnGererMedecins, &QPushButton::clicked, this, &MainWindow::ouvrirMedecinDialog);

    // Connexion du bouton pour les rendez-vous
    connect(ui->btnGererRendezVous, &QPushButton::clicked, this, &MainWindow::ouvrirRendezVousDialog);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Ouvrir la fenêtre de gestion des patients
void MainWindow::ouvrirPatientDialog() {
    patientDialog = new PatientDialog(this);
    patientDialog->exec();
    delete patientDialog;
}

// Ouvrir la fenêtre de gestion des médecins
void MainWindow::ouvrirMedecinDialog() {
    medecinDialog = new MedecinDialog(this);
    medecinDialog->exec();
    delete medecinDialog;
}

// Ouvrir la fenêtre de gestion des rendez-vous
void MainWindow::ouvrirRendezVousDialog() {
    RendezVousDialog dialog(this);
    dialog.setModal(true);  // Empêche l'interaction avec la fenêtre principale
    dialog.exec();
}
