#ifndef MEDECINMANAGER_H
#define MEDECINMANAGER_H

#include <QVector>
#include <QString>

class Medecin;

class MedecinManager {
public:
    bool ajouterMedecin(const Medecin &medecin);
    bool modifierMedecin(const Medecin &medecin);
    bool modifierMedecinDepuisTable(int id, const QString &colonne, const QString &valeur);
    bool supprimerMedecin(int id);
    QVector<Medecin> getMedecins();
};

#endif // MEDECINMANAGER_H
