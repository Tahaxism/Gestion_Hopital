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

    // Icônes pour les boutons
    ui->btnAjouter->setIcon(QIcon(":/icons/ajouter.png"));
    ui->btnModifier->setIcon(QIcon(":/icons/modifier.png"));
    ui->btnSupprimer->setIcon(QIcon(":/icons/supprimer.png"));

    // Charger les patients dès l'ouverture
    chargerPatients();

    // Connecter cellChanged après chargement des patients
    connect(ui->tableWidgetPatients, &QTableWidget::cellChanged, this, &PatientDialog::modifierPatientDepuisTable);
}

PatientDialog::~PatientDialog() {
    delete ui;
}

// Charger les patients dans le QTableWidget
void PatientDialog::chargerPatients() {
    PatientManager manager;
    QVector<Patient> patients = manager.getPatients();

    disconnect(ui->tableWidgetPatients, &QTableWidget::cellChanged, this, &PatientDialog::modifierPatientDepuisTable);

    ui->tableWidgetPatients->setRowCount(0);
    ui->tableWidgetPatients->setColumnCount(6);  // Assurez-vous qu'il y a bien 6 colonnes

    // Définition explicite des en-têtes de colonne
    QStringList headers = {"ID", "Nom", "Prénom", "Date de Naissance", "Téléphone", "Adresse"};
    ui->tableWidgetPatients->setHorizontalHeaderLabels(headers);

    for (const Patient& patient : patients) {
        int row = ui->tableWidgetPatients->rowCount();
        ui->tableWidgetPatients->insertRow(row);
        ui->tableWidgetPatients->setItem(row, 0, new QTableWidgetItem(QString::number(patient.getId())));
        ui->tableWidgetPatients->setItem(row, 1, new QTableWidgetItem(patient.getNom()));
        ui->tableWidgetPatients->setItem(row, 2, new QTableWidgetItem(patient.getPrenom()));
        ui->tableWidgetPatients->setItem(row, 3, new QTableWidgetItem(patient.getDateNaissance()));
        ui->tableWidgetPatients->setItem(row, 4, new QTableWidgetItem(patient.getTelephone()));
        ui->tableWidgetPatients->setItem(row, 5, new QTableWidgetItem(patient.getAdresse()));

        ui->tableWidgetPatients->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
        ui->tableWidgetPatients->setSelectionBehavior(QAbstractItemView::SelectRows);
    }

    connect(ui->tableWidgetPatients, &QTableWidget::cellChanged, this, &PatientDialog::modifierPatientDepuisTable);
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
    QString nom = ui->tableWidgetPatients->item(row, 1)->text();
    QString prenom = ui->tableWidgetPatients->item(row, 2)->text();

    // Popup de confirmation
    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::question(
        this,
        "Confirmation de suppression",
        QString("Voulez-vous vraiment supprimer le patient %1 %2 ?").arg(nom).arg(prenom),
        QMessageBox::Yes | QMessageBox::No
        );

    if (confirmation == QMessageBox::No) {
        return;  // Annuler la suppression
    }

    // Si l'utilisateur confirme, procéder à la suppression
    PatientManager manager;
    if (manager.supprimerPatient(id)) {
        QMessageBox::information(this, "Succès", "Patient supprimé avec succès.");
        chargerPatients();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du patient.");
    }
}

// Modification directe dans la table
void PatientDialog::modifierPatientDepuisTable(int row, int column) {
    if (row < 0 || column < 0) return;

    // Vérification si la cellule est vide
    if (!ui->tableWidgetPatients->item(row, column)) {
        qDebug() << "Erreur : Cellule inexistante.";
        return;
    }

    int id = ui->tableWidgetPatients->item(row, 0)->text().toInt();
    QString valeur = ui->tableWidgetPatients->item(row, column)->text();

    // Mapping des en-têtes de colonnes visibles vers les colonnes SQL réelles
    QMap<QString, QString> mappingColonnes;
    mappingColonnes["Nom"] = "nom";
    mappingColonnes["Prénom"] = "prenom";
    mappingColonnes["Date de Naissance"] = "date_naissance";
    mappingColonnes["Téléphone"] = "telephone";
    mappingColonnes["Adresse"] = "adresse";

    QString colonne = ui->tableWidgetPatients->horizontalHeaderItem(column)->text();

    if (!mappingColonnes.contains(colonne)) {
        qDebug() << "Erreur : Colonne non reconnue." << colonne;
        return;
    }

    QString colonneSQL = mappingColonnes[colonne];

    // Déconnecter temporairement pour éviter les boucles infinies
    disconnect(ui->tableWidgetPatients, &QTableWidget::cellChanged, this, &PatientDialog::modifierPatientDepuisTable);

    PatientManager manager;
    if (manager.modifierPatientDepuisTable(id, colonneSQL, valeur)) {
        qDebug() << "Patient modifié dans la colonne SQL :" << colonneSQL;
    } else {
        qDebug() << "Erreur lors de la mise à jour dans la colonne :" << colonneSQL;
    }

    // Reconnecter après modification
    connect(ui->tableWidgetPatients, &QTableWidget::cellChanged, this, &PatientDialog::modifierPatientDepuisTable);
}


// Remplir le formulaire lorsque l'utilisateur clique sur une ligne
void PatientDialog::remplirFormulaire(int row) {
    if (row < 0 || row >= ui->tableWidgetPatients->rowCount()) return;

    // Remplissage sécurisé des champs
    if (ui->tableWidgetPatients->item(row, 1))
        ui->lineEditNom->setText(ui->tableWidgetPatients->item(row, 1)->text());
    else
        ui->lineEditNom->clear();

    if (ui->tableWidgetPatients->item(row, 2))
        ui->lineEditPrenom->setText(ui->tableWidgetPatients->item(row, 2)->text());
    else
        ui->lineEditPrenom->clear();

    if (ui->tableWidgetPatients->item(row, 3))
        ui->dateEditNaissance->setDate(QDate::fromString(ui->tableWidgetPatients->item(row, 3)->text(), "yyyy-MM-dd"));
    else
        ui->dateEditNaissance->setDate(QDate::currentDate());

    if (ui->tableWidgetPatients->item(row, 4))
        ui->lineEditTelephone->setText(ui->tableWidgetPatients->item(row, 4)->text());
    else
        ui->lineEditTelephone->clear();

    if (ui->tableWidgetPatients->item(row, 5))
        ui->textEditAdresse->setPlainText(ui->tableWidgetPatients->item(row, 5)->text());
    else
        ui->textEditAdresse->clear();
}

void PatientDialog::modifierDepuisTable(int row, int column) {
    if (column == 0) {
        QMessageBox::warning(this, "Erreur", "La modification de l'ID est interdite.");
        chargerPatients();  // Recharger pour annuler la modification
        return;
    }

    if (!ui->tableWidgetPatients->item(row, column)) {
        qDebug() << "Erreur : Cellule inexistante lors de la modification.";
        return;
    }

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
        qDebug() << "Patient modifié dans la colonne :" << colonneModifiee;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
        chargerPatients();  // Recharger en cas d'erreur
    }
}

