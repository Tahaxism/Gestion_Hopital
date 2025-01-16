#ifndef MEDECIN_H
#define MEDECIN_H

#include <QString>

class Medecin {
public:
    Medecin(int id, const QString &nom, const QString &prenom, const QString &specialite, const QString &telephone, const QString &email);

    int getId() const;
    QString getNom() const;
    QString getPrenom() const;
    QString getSpecialite() const;
    QString getTelephone() const;
    QString getEmail() const;

private:
    int id;
    QString nom;
    QString prenom;
    QString specialite;
    QString telephone;
    QString email;
};

#endif // MEDECIN_H
