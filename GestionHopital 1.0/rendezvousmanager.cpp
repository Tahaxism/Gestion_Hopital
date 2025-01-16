#include "rendezvousmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Ajouter un rendez-vous
bool RendezVousManager::ajouterRendezVous(const RendezVous &rdv) {
    QSqlQuery query;
    query.prepare("INSERT INTO RendezVous (id_patient, id_medecin, date_rdv, heure_rdv, motif) "
                  "VALUES (:id_patient, :id_medecin, :date_rdv, :heure_rdv, :motif)");

    query.bindValue(":id_patient", rdv.getIdPatient());
    query.bindValue(":id_medecin", rdv.getIdMedecin());
    query.bindValue(":date_rdv", rdv.getDate());
    query.bindValue(":heure_rdv", rdv.getHeure());
    query.bindValue(":motif", rdv.getMotif());

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du rendez-vous : " << query.lastError().text();
        return false;
    }
    return true;
}

// Récupérer les rendez-vous avec noms
QVector<RendezVous> RendezVousManager::getRendezVous() {
    QVector<RendezVous> rendezVousList;
    QSqlQuery query;

    query.prepare(
        "SELECT r.id_rdv, p.nom AS nom_patient, m.nom AS nom_medecin, "
        "r.date_rdv, r.heure_rdv, r.motif "
        "FROM RendezVous r "
        "INNER JOIN Patients p ON r.id_patient = p.id_patient "
        "INNER JOIN Medecins m ON r.id_medecin = m.id_medecin "
        "ORDER BY r.date_rdv ASC"
        );

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des rendez-vous : " << query.lastError().text();
        return rendezVousList;
    }

    while (query.next()) {
        RendezVous rdv(query.value("id_rdv").toInt(),
                       query.value("nom_patient").toString(),
                       query.value("nom_medecin").toString(),
                       query.value("date_rdv").toString(),
                       query.value("heure_rdv").toString(),
                       query.value("motif").toString());
        rendezVousList.append(rdv);
    }

    return rendezVousList;
}

bool RendezVousManager::modifierRendezVous(const RendezVous &rdv) {
    QSqlQuery query;
    query.prepare("UPDATE RendezVous SET id_patient = :id_patient, id_medecin = :id_medecin, "
                  "date = :date, heure = :heure, motif = :motif WHERE id = :id");
    query.bindValue(":id_patient", rdv.getIdPatient());
    query.bindValue(":id_medecin", rdv.getIdMedecin());
    query.bindValue(":date", rdv.getDate());
    query.bindValue(":heure", rdv.getHeure());
    query.bindValue(":motif", rdv.getMotif());
    query.bindValue(":id", rdv.getId());

    return query.exec();
}

// Suppression d'un rendez-vous
bool RendezVousManager::supprimerRendezVous(int id_rdv) {
    QSqlQuery query;
    query.prepare("DELETE FROM RendezVous WHERE id_rdv = :id_rdv");
    query.bindValue(":id_rdv", id_rdv);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la suppression du rendez-vous : " << query.lastError().text();
        return false;
    }
    return true;
}
