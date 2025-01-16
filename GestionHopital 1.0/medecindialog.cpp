#include "medecindialog.h"
#include "ui_medecindialog.h"
#include "medecinmanager.h"
#include "medecin.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>

MedecinDialog::MedecinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedecinDialog) {
    ui->setupUi(this);

    // Connecter les boutons aux fonctions correspondantes
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MedecinDialog::ajouterMedecin);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MedecinDialog::supprimerMedecin);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MedecinDialog::modifierMedecin);
    connect(ui->tableWidgetMedecins, &QTableWidget::cellClicked, this, &MedecinDialog::remplirFormulaire);

    // Permettre l'édition directe des cellules dans la table
    ui->tableWidgetMedecins->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    ui->tableWidgetMedecins->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Connecter la modification directe à la mise à jour SQL
    connect(ui->tableWidgetMedecins, &QTableWidget::cellChanged, this, &MedecinDialog::modifierDepuisTable);

    // Charger les médecins dans la table dès l'ouverture
    chargerMedecins();
}

MedecinDialog::~MedecinDialog() {
    delete ui;
}

// Charger les médecins dans le QTableWidget
void MedecinDialog::chargerMedecins() {
    MedecinManager manager;
    QVector<Medecin> medecins = manager.getMedecins();

    ui->tableWidgetMedecins->setRowCount(0);  // Nettoyer le tableau avant de le remplir
    for (const Medecin& medecin : medecins) {
        int row = ui->tableWidgetMedecins->rowCount();
        ui->tableWidgetMedecins->insertRow(row);
        ui->tableWidgetMedecins->setItem(row, 0, new QTableWidgetItem(QString::number(medecin.getId())));
        ui->tableWidgetMedecins->setItem(row, 1, new QTableWidgetItem(medecin.getNom()));
        ui->tableWidgetMedecins->setItem(row, 2, new QTableWidgetItem(medecin.getPrenom()));
        ui->tableWidgetMedecins->setItem(row, 3, new QTableWidgetItem(medecin.getSpecialite()));
        ui->tableWidgetMedecins->setItem(row, 4, new QTableWidgetItem(medecin.getTelephone()));
        ui->tableWidgetMedecins->setItem(row, 5, new QTableWidgetItem(medecin.getEmail()));
    }
}

// Ajouter un médecin à la base de données
void MedecinDialog::ajouterMedecin() {
    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPrenom->text();
    QString specialite = ui->lineEditSpecialite->text();
    QString telephone = ui->lineEditTelephone->text();
    QString email = ui->lineEditEmail->text();

    if (nom.isEmpty() || prenom.isEmpty() || specialite.isEmpty() || telephone.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    Medecin medecin(0, nom, prenom, specialite, telephone, email);

    MedecinManager manager;
    if (manager.ajouterMedecin(medecin)) {
        QMessageBox::information(this, "Succès", "Médecin ajouté avec succès.");
        chargerMedecins();  // Rafraîchir la table
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du médecin a échoué.");
    }
}

// Modifier un médecin existant via bouton
void MedecinDialog::modifierMedecin() {
    int row = ui->tableWidgetMedecins->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un médecin à modifier.");
        return;
    }

    int id = ui->tableWidgetMedecins->item(row, 0)->text().toInt();
    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPrenom->text();
    QString specialite = ui->lineEditSpecialite->text();
    QString telephone = ui->lineEditTelephone->text();
    QString email = ui->lineEditEmail->text();

    if (nom.isEmpty() || prenom.isEmpty() || specialite.isEmpty() || telephone.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    Medecin medecin(id, nom, prenom, specialite, telephone, email);

    MedecinManager manager;
    if (manager.modifierMedecin(medecin)) {
        QMessageBox::information(this, "Succès", "Médecin modifié avec succès.");
        chargerMedecins();
    } else {
        QMessageBox::critical(this, "Erreur", "La modification du médecin a échoué.");
    }
}

// Modifier un médecin en éditant directement dans la table
void MedecinDialog::modifierDepuisTable(int row, int column) {
    if (column == 0) {
        // Récupérer la valeur actuelle de l'ID avant modification
        QString ancienneValeur = ui->tableWidgetMedecins->item(row, column)->text();
        QString nouvelleValeur = ui->tableWidgetMedecins->item(row, column)->text();

        // Vérifier si la valeur a réellement changé
        if (ancienneValeur == nouvelleValeur) {
            // L'ID n'a pas changé => ne rien faire
            return;
        }

        // Si l'utilisateur essaie de modifier l'ID => bloquer
        QMessageBox::warning(this, "Erreur", "Vous ne pouvez pas modifier l'ID.");
        // Rafraîchir la table pour annuler la modification
        chargerMedecins();
        return;
    }

    // Continuer la modification si ce n'est pas la colonne ID
    int id = ui->tableWidgetMedecins->item(row, 0)->text().toInt();
    QString nouvelleValeur = ui->tableWidgetMedecins->item(row, column)->text();

    QString colonneModifiee;
    switch (column) {
    case 1: colonneModifiee = "nom"; break;
    case 2: colonneModifiee = "prenom"; break;
    case 3: colonneModifiee = "specialite"; break;
    case 4: colonneModifiee = "telephone"; break;
    case 5: colonneModifiee = "email"; break;
    default: return;
    }

    MedecinManager manager;
    if (manager.modifierMedecinDepuisTable(id, colonneModifiee, nouvelleValeur)) {
        qDebug() << "Médecin modifié directement dans la colonne:" << colonneModifiee;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
        chargerMedecins();
    }
}


// Supprimer un médecin sélectionné
void MedecinDialog::supprimerMedecin() {
    int row = ui->tableWidgetMedecins->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner un médecin à supprimer.");
        return;
    }

    int id = ui->tableWidgetMedecins->item(row, 0)->text().toInt();

    MedecinManager manager;
    if (manager.supprimerMedecin(id)) {
        QMessageBox::information(this, "Succès", "Médecin supprimé avec succès.");
        chargerMedecins();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du médecin.");
    }
}

// Remplir le formulaire lors de la sélection d'une ligne
void MedecinDialog::remplirFormulaire(int row) {
    if (row < 0) return;

    ui->lineEditNom->setText(ui->tableWidgetMedecins->item(row, 1)->text());
    ui->lineEditPrenom->setText(ui->tableWidgetMedecins->item(row, 2)->text());
    ui->lineEditSpecialite->setText(ui->tableWidgetMedecins->item(row, 3)->text());
    ui->lineEditTelephone->setText(ui->tableWidgetMedecins->item(row, 4)->text());
    ui->lineEditEmail->setText(ui->tableWidgetMedecins->item(row, 5)->text());
}
