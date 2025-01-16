#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "patientmanager.h"
#include "patient.h"
#include <QMessageBox>
#include <QString>
#include <QDate>
#include <QDebug>

PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog) {
    ui->setupUi(this);

    // Connecter les boutons aux fonctions correspondantes
    connect(ui->btnAjouter, &QPushButton::clicked, this, &PatientDialog::ajouterPatient);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &PatientDialog::supprimerPatient);
    connect(ui->btnModifier, &QPushButton::clicked, this, &PatientDialog::modifierPatient);
    connect(ui->tableWidgetPatients, &QTableWidget::cellClicked, this, &PatientDialog::remplirFormulaire);

    // Charger les patients dans la table dès l'ouverture
    chargerPatients();
}

PatientDialog::~PatientDialog() {
    delete ui;
}

// Charger les patients dans le QTableWidget
void PatientDialog::chargerPatients() {
    PatientManager manager;
    QVector<Patient> patients = manager.getPatients();

    ui->tableWidgetPatients->setRowCount(0);  // Nettoyer le tableau avant de le remplir
    for (const Patient& patient : patients) {
        int row = ui->tableWidgetPatients->rowCount();
        ui->tableWidgetPatients->insertRow(row);
        ui->tableWidgetPatients->setItem(row, 0, new QTableWidgetItem(QString::number(patient.getId())));
        ui->tableWidgetPatients->setItem(row, 1, new QTableWidgetItem(patient.getNom()));
        ui->tableWidgetPatients->setItem(row, 2, new QTableWidgetItem(patient.getPrenom()));
        ui->tableWidgetPatients->setItem(row, 3, new QTableWidgetItem(patient.getDateNaissance()));
        ui->tableWidgetPatients->setItem(row, 4, new QTableWidgetItem(patient.getTelephone()));
        ui->tableWidgetPatients->setItem(row, 5, new QTableWidgetItem(patient.getAdresse()));
        // Permettre l'édition directe des cellules dans la table des patients
        ui->tableWidgetPatients->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
        ui->tableWidgetPatients->setSelectionBehavior(QAbstractItemView::SelectRows);

        // Connecter la modification directe à la mise à jour SQL
        connect(ui->tableWidgetPatients, &QTableWidget::cellChanged, this, &PatientDialog::modifierDepuisTable);

    }
}

// Ajouter un patient à la base de données
void PatientDialog::ajouterPatient() {
    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPrenom->text();
    QString dateNaissance = ui->dateEditNaissance->text();
    QString telephone = ui->lineEditTelephone->text();
    QString adresse = ui->textEditAdresse->toPlainText();

    if (nom.isEmpty() || prenom.isEmpty() || telephone.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    Patient patient(0, nom, prenom, dateNaissance, telephone, adresse);

    PatientManager manager;
    if (manager.ajouterPatient(patient)) {
        QMessageBox::information(this, "Succès", "Patient ajouté avec succès.");
        chargerPatients();  // Rafraîchir la table
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du patient a échoué.");
    }
}

// Modifier un patient existant
void PatientDialog::modifierPatient() {
    int row = ui->tableWidgetPatients->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un patient à modifier.");
        return;
    }

    int id = ui->tableWidgetPatients->item(row, 0)->text().toInt();
    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPrenom->text();
    QString dateNaissance = ui->dateEditNaissance->text();
    QString telephone = ui->lineEditTelephone->text();
    QString adresse = ui->textEditAdresse->toPlainText();

    if (nom.isEmpty() || prenom.isEmpty() || telephone.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    Patient patient(id, nom, prenom, dateNaissance, telephone, adresse);

    PatientManager manager;
    if (manager.modifierPatient(patient)) {
        QMessageBox::information(this, "Succès", "Patient modifié avec succès.");
        chargerPatients();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification du patient a échoué.");
    }
}

// Supprimer un patient sélectionné
void PatientDialog::supprimerPatient() {
    int row = ui->tableWidgetPatients->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un patient à supprimer.");
        return;
    }

    int id = ui->tableWidgetPatients->item(row, 0)->text().toInt();

    PatientManager manager;
    if (manager.supprimerPatient(id)) {
        QMessageBox::information(this, "Succès", "Patient supprimé avec succès.");
        chargerPatients();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du patient.");
    }
}

// Remplir le formulaire en sélectionnant une ligne
void PatientDialog::remplirFormulaire(int row) {
    if (row < 0) return;

    ui->lineEditNom->setText(ui->tableWidgetPatients->item(row, 1)->text());
    ui->lineEditPrenom->setText(ui->tableWidgetPatients->item(row, 2)->text());
    ui->dateEditNaissance->setDate(QDate::fromString(ui->tableWidgetPatients->item(row, 3)->text(), "yyyy-MM-dd"));
    ui->lineEditTelephone->setText(ui->tableWidgetPatients->item(row, 4)->text());
    ui->textEditAdresse->setPlainText(ui->tableWidgetPatients->item(row, 5) ? ui->tableWidgetPatients->item(row, 5)->text() : "");
}

void PatientDialog::modifierDepuisTable(int row, int column) {
    if (column == 0) {
        // Vérifier si la valeur de l'ID a changé
        QString ancienneValeur = ui->tableWidgetPatients->item(row, column)->text();
        QString nouvelleValeur = ui->tableWidgetPatients->item(row, column)->text();

        if (ancienneValeur == nouvelleValeur) {
            // L'ID n'a pas été modifié, pas d'action nécessaire
            return;
        }

        // Empêcher la modification de l'ID
        QMessageBox::warning(this, "Erreur", "Vous ne pouvez pas modifier l'ID.");
        // Recharger la table pour annuler la modification
        chargerPatients();
        return;
    }

    // Continuer la modification pour les autres colonnes
    int id = ui->tableWidgetPatients->item(row, 0)->text().toInt();
    QString nouvelleValeur = ui->tableWidgetPatients->item(row, column)->text();

    QString colonneModifiee;
    switch (column) {
    case 1: colonneModifiee = "nom"; break;
    case 2: colonneModifiee = "prenom"; break;
    case 3: colonneModifiee = "date_naissance"; break;
    case 4: colonneModifiee = "telephone"; break;
    case 5: colonneModifiee = "adresse"; break;
    default: return;
    }

    PatientManager manager;
    if (manager.modifierPatientDepuisTable(id, colonneModifiee, nouvelleValeur)) {
        qDebug() << "Patient modifié directement dans la colonne:" << colonneModifiee;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
        chargerPatients();  // Recharger les données en cas d'erreur
    }
}

