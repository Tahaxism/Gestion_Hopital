#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>

namespace Ui {
class PatientDialog;
}

class PatientDialog : public QDialog {
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = nullptr);
    ~PatientDialog();

private slots:
    void ajouterPatient();
    void modifierPatient();
    void supprimerPatient();
    void remplirFormulaire(int row);

    // Modification depuis la table (différencier les méthodes)
    void modifierDepuisTable(int row, int column);   // Modification générale
    void modifierPatientDepuisTable(int row, int column);  // Modification spécifique patient

private:
    Ui::PatientDialog *ui;
    void chargerPatients();
};

#endif // PATIENTDIALOG_H
