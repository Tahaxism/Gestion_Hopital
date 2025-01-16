#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QString>

class RendezVous {
public:
    // Constructeurs
    RendezVous();
    RendezVous(int id, int id_patient, int id_medecin, const QString &date, const QString &heure, const QString &motif);
    RendezVous(int id, const QString &nomPatient, const QString &nomMedecin,
               const QString &date, const QString &heure, const QString &motif);

    // Getters
    int getId() const;
    int getIdPatient() const;
    int getIdMedecin() const;
    QString getNomPatient() const;
    QString getNomMedecin() const;
    QString getDate() const;
    QString getHeure() const;
    QString getMotif() const;

    // Setters
    void setId(int id);
    void setIdPatient(int id_patient);
    void setIdMedecin(int id_medecin);
    void setNomPatient(const QString &nom);
    void setNomMedecin(const QString &nom);
    void setDate(const QString &date);
    void setHeure(const QString &heure);
    void setMotif(const QString &motif);

private:
    int id;
    int id_patient;
    int id_medecin;
    QString nomPatient;
    QString nomMedecin;
    QString date;
    QString heure;
    QString motif;
};

#endif // RENDEZVOUS_H
