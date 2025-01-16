#include "medecinmanager.h"
#include "medecin.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Ajouter un médecin dans la base de données
bool MedecinManager::ajouterMedecin(const Medecin &medecin) {
    QSqlQuery query;

    query.prepare("INSERT INTO Medecins (nom, prenom, specialite, telephone, email) "
                  "VALUES (:nom, :prenom, :specialite, :telephone, :email)");

    query.bindValue(":nom", medecin.getNom());
    query.bindValue(":prenom", medecin.getPrenom());
    query.bindValue(":specialite", medecin.getSpecialite());
    query.bindValue(":telephone", medecin.getTelephone());
    query.bindValue(":email", medecin.getEmail());

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du médecin:" << query.lastError().text();
        return false;
    }

    // Récupérer l'ID du dernier médecin ajouté
    int idMedecin = query.lastInsertId().toInt();
    qDebug() << "Médecin ajouté avec l'ID:" << idMedecin;

    return true;
}

// Modifier un médecin complet (via bouton Modifier)
bool MedecinManager::modifierMedecin(const Medecin &medecin) {
    QSqlQuery query;

    query.prepare("UPDATE Medecins SET nom = :nom, prenom = :prenom, "
                  "specialite = :specialite, telephone = :telephone, email = :email "
                  "WHERE id_medecin = :id_medecin");

    query.bindValue(":nom", medecin.getNom());
    query.bindValue(":prenom", medecin.getPrenom());
    query.bindValue(":specialite", medecin.getSpecialite());
    query.bindValue(":telephone", medecin.getTelephone());
    query.bindValue(":email", medecin.getEmail());
    query.bindValue(":id_medecin", medecin.getId());

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du médecin:" << query.lastError().text();
        return false;
    }

    return true;
}

// Modifier un médecin directement dans la table
bool MedecinManager::modifierMedecinDepuisTable(int id, const QString &colonne, const QString &valeur) {
    QSqlQuery query;
    QString sql = QString("UPDATE Medecins SET %1 = :valeur WHERE id_medecin = :id").arg(colonne);

    query.prepare(sql);
    query.bindValue(":valeur", valeur);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification directe:" << query.lastError().text();
        return false;
    }

    qDebug() << "Médecin modifié directement dans la colonne:" << colonne;
    return true;
}

// Supprimer un médecin
bool MedecinManager::supprimerMedecin(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Medecins WHERE id_medecin = :id_medecin");
    query.bindValue(":id_medecin", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du médecin:" << query.lastError().text();
        return false;
    }
    qDebug() << "Médecin supprimé avec succès. ID:" << id;
    return true;
}

// Récupérer tous les médecins
QVector<Medecin> MedecinManager::getMedecins() {
    QVector<Medecin> medecins;
    QSqlQuery query("SELECT * FROM Medecins ORDER BY id_medecin ASC");

    while (query.next()) {
        medecins.append(Medecin(query.value("id_medecin").toInt(),
                                query.value("nom").toString(),
                                query.value("prenom").toString(),
                                query.value("specialite").toString(),
                                query.value("telephone").toString(),
                                query.value("email").toString()));
    }

    return medecins;
}
