#ifndef RENDEZVOUSDIALOG_H
#define RENDEZVOUSDIALOG_H

#include <QDialog>

namespace Ui {
class RendezVousDialog;
}

class RendezVousDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RendezVousDialog(QWidget *parent = nullptr);
    ~RendezVousDialog();

private slots:
    void ajouterRendezVous();
    void supprimerRendezVous();
    void chargerRendezVous();


private:
    Ui::RendezVousDialog *ui;
    void remplirComboBoxPatients();
    void remplirComboBoxMedecins();
};

#endif // RENDEZVOUSDIALOG_H
