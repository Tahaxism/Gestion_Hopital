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
    void modifierDepuisTable(int row, int column);

private:
    Ui::PatientDialog *ui;
    void chargerPatients();
};

#endif // PATIENTDIALOG_H
