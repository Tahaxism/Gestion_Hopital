#ifndef MEDECINDIALOG_H
#define MEDECINDIALOG_H

#include <QDialog>
#include <QVector>

namespace Ui {
class MedecinDialog;
}

class MedecinDialog : public QDialog {
    Q_OBJECT

public:
    explicit MedecinDialog(QWidget *parent = nullptr);
    ~MedecinDialog();

private slots:
    void ajouterMedecin();
    void supprimerMedecin();
    void modifierMedecin();
    void remplirFormulaire(int row);

    // **Déclarer ici la méthode de modification directe dans la table**
    void modifierDepuisTable(int row, int column);

    void chargerMedecins();

private:
    Ui::MedecinDialog *ui;
};

#endif // MEDECINDIALOG_H
