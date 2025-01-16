#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

#include <QVector>
#include <QSqlQuery>
#include "patient.h"

class PatientManager {
public:
    bool ajouterPatient(const Patient& patient);
    bool supprimerPatient(int id);
    bool modifierPatient(const Patient& patient);
    bool modifierPatientDepuisTable(int id, const QString &colonne, const QString &valeur);


    QVector<Patient> getPatients();
};

#endif // PATIENTMANAGER_H
