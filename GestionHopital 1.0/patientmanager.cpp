#include "patientmanager.h"
#include <QSqlError>
#include <QDebug>

// Ajouter un patient avec l'adresse
bool PatientManager::ajouterPatient(const Patient& patient) {
    QSqlQuery query;
    QString sql = QString("INSERT INTO Patients (nom, prenom, date_naissance, telephone, adresse) "
                          "VALUES ('%1', '%2', '%3', '%4', '%5')")
                      .arg(patient.getNom())
                      .arg(patient.getPrenom())
                      .arg(patient.getDateNaissance())
                      .arg(patient.getTelephone())
                      .arg(patient.getAdresse());
    if (!query.exec(sql)) {
        qDebug() << "Erreur SQL (test direct):" << query.lastError().text();
        qDebug() << "Requête SQL : " << sql;
        return false;
    }
    return true;
}

// Modifier un patient avec l'adresse
bool PatientManager::modifierPatient(const Patient& patient) {
    QSqlQuery query;
    query.prepare("UPDATE Patients SET nom = :nom, prenom = :prenom, "
                  "date_naissance = :date_naissance, telephone = :telephone, adresse = :adresse "
                  "WHERE id_patient = :id_patient");
    query.bindValue(":nom", patient.getNom());
    query.bindValue(":prenom", patient.getPrenom());
    query.bindValue(":date_naissance", patient.getDateNaissance());
    query.bindValue(":telephone", patient.getTelephone());
    query.bindValue(":adresse", patient.getAdresse());
    query.bindValue(":id_patient", patient.getId());

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification du patient:" << query.lastError().text();
        return false;
    }
    return true;
}

// Supprimer un patient
bool PatientManager::supprimerPatient(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Patients WHERE id_patient = ?");
    query.addBindValue(id);
    return query.exec();
}

// Récupérer tous les patients avec l'adresse
QVector<Patient> PatientManager::getPatients() {
    QVector<Patient> patients;
    QSqlQuery query("SELECT * FROM Patients");
    while (query.next()) {
        patients.append(Patient(query.value("id_patient").toInt(),
                                query.value("nom").toString(),
                                query.value("prenom").toString(),
                                query.value("date_naissance").toString(),
                                query.value("telephone").toString(),
                                query.value("adresse").toString()));
    }
    return patients;
}

bool PatientManager::modifierPatientDepuisTable(int id, const QString &colonne, const QString &valeur) {
    QSqlQuery query;
    QString sql = QString("UPDATE Patients SET %1 = :valeur WHERE id_patient = :id").arg(colonne);

    query.prepare(sql);
    query.bindValue(":valeur", valeur);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification directe du patient:" << query.lastError().text();
        return false;
    }

    qDebug() << "Patient modifié directement dans la colonne:" << colonne;
    return true;
}

