#include "medecin.h"

Medecin::Medecin(int id, const QString &nom, const QString &prenom, const QString &specialite, const QString &telephone, const QString &email)
    : id(id), nom(nom), prenom(prenom), specialite(specialite), telephone(telephone), email(email) {}

int Medecin::getId() const { return id; }
QString Medecin::getNom() const { return nom; }
QString Medecin::getPrenom() const { return prenom; }
QString Medecin::getSpecialite() const { return specialite; }
QString Medecin::getTelephone() const { return telephone; }
QString Medecin::getEmail() const { return email; }
