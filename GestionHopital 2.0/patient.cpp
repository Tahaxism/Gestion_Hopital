#include "patient.h"

Patient::Patient(int id, QString nom, QString prenom, QString dateNaissance, QString telephone, QString adresse)
    : id(id), nom(nom), prenom(prenom), dateNaissance(dateNaissance), telephone(telephone), adresse(adresse) {}

int Patient::getId() const {
    return id;
}

QString Patient::getNom() const {
    return nom;
}

QString Patient::getPrenom() const {
    return prenom;
}

QString Patient::getDateNaissance() const {
    return dateNaissance;
}

QString Patient::getTelephone() const {
    return telephone;
}

QString Patient::getAdresse() const {
    return adresse;
}
