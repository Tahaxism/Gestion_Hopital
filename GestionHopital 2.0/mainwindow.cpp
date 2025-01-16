#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Définir les icônes des boutons
    ui->btnGererPatients->setIcon(QIcon(":/icons/ajouter.png"));
    ui->btnGererMedecins->setIcon(QIcon(":/icons/modifier.png"));
    ui->btnGererRendezVous->setIcon(QIcon(":/icons/supprimer.png"));

    // Ajuster la taille des icônes
    ui->btnGererPatients->setIconSize(QSize(32, 32));
    ui->btnGererMedecins->setIconSize(QSize(32, 32));
    ui->btnGererRendezVous->setIconSize(QSize(32, 32));

    // Définir l'icône pour la fenêtre principale
    this->setWindowIcon(QIcon(":/icons/app_icon.png"));

    // Appliquer le logo au QLabel
    QPixmap logo(":/icons/logo.png");
    ui->labelLogo->setPixmap(logo.scaled(256, 256, Qt::KeepAspectRatio));

    // Appliquer l'arrière-plan
    appliquerArrierePlan();

    // Connexion des boutons
    connect(ui->btnGererPatients, &QPushButton::clicked, this, &MainWindow::ouvrirPatientDialog);
    connect(ui->btnGererMedecins, &QPushButton::clicked, this, &MainWindow::ouvrirMedecinDialog);
    connect(ui->btnGererRendezVous, &QPushButton::clicked, this, &MainWindow::ouvrirRendezVousDialog);
}

void MainWindow::appliquerArrierePlan() {
    this->setStyleSheet("QMainWindow {"
                        "background-image: url(:/icons/arriereplan.png);"
                        "background-repeat: no-repeat;"
                        "background-position: center;"
                        "}");
}



void MainWindow::ouvrirPatientDialog() {
    patientDialog = new PatientDialog(this);
    patientDialog->exec();
    delete patientDialog;
}

void MainWindow::ouvrirMedecinDialog() {
    medecinDialog = new MedecinDialog(this);
    medecinDialog->exec();
    delete medecinDialog;
}

void MainWindow::ouvrirRendezVousDialog() {
    RendezVousDialog *rendezVousDialog = new RendezVousDialog(this);
    rendezVousDialog->exec();
    delete rendezVousDialog;
}


MainWindow::~MainWindow()
{
    delete ui;
}
