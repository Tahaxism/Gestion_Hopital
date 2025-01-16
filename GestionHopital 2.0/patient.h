#ifndef PATIENT_H
#define PATIENT_H

#include <QString>

class Patient {
public:
    Patient(int id, QString nom, QString prenom, QString dateNaissance, QString telephone, QString adresse);

    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getDateNaissance() const;
    QString getTelephone() const;
    QString getAdresse() const;

private:
    int id;
    QString nom;
    QString prenom;
    QString dateNaissance;
    QString telephone;
    QString adresse;  // Nouveau champ adresse
};

#endif // PATIENT_H
