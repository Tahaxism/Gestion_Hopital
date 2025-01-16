#include "rendezvous.h"

// Constructeur par défaut
RendezVous::RendezVous() : id(0), id_patient(0), id_medecin(0), date(""), heure(""), motif("") {}

// Constructeur avec identifiants
RendezVous::RendezVous(int id, int id_patient, int id_medecin, const QString &date, const QString &heure, const QString &motif)
    : id(id), id_patient(id_patient), id_medecin(id_medecin), date(date), heure(heure), motif(motif) {}

// Constructeur avec noms (affichage)
RendezVous::RendezVous(int id, const QString &nomPatient, const QString &nomMedecin,
                       const QString &date, const QString &heure, const QString &motif)
    : id(id), nomPatient(nomPatient), nomMedecin(nomMedecin), date(date), heure(heure), motif(motif) {}

// Getters
int RendezVous::getId() const { return id; }
int RendezVous::getIdPatient() const { return id_patient; }
int RendezVous::getIdMedecin() const { return id_medecin; }
QString RendezVous::getNomPatient() const { return nomPatient; }
QString RendezVous::getNomMedecin() const { return nomMedecin; }
QString RendezVous::getDate() const { return date; }
QString RendezVous::getHeure() const { return heure; }
QString RendezVous::getMotif() const { return motif; }

// Setters
void RendezVous::setId(int id) { this->id = id; }
void RendezVous::setIdPatient(int id_patient) { this->id_patient = id_patient; }
void RendezVous::setIdMedecin(int id_medecin) { this->id_medecin = id_medecin; }
void RendezVous::setNomPatient(const QString &nom) { this->nomPatient = nom; }
void RendezVous::setNomMedecin(const QString &nom) { this->nomMedecin = nom; }
void RendezVous::setDate(const QString &date) { this->date = date; }
void RendezVous::setHeure(const QString &heure) { this->heure = heure; }
void RendezVous::setMotif(const QString &motif) { this->motif = motif; }
