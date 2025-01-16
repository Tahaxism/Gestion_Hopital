#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patientdialog.h"
#include "medecindialog.h"
#include "rendezvousdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ouvrirPatientDialog();
    void ouvrirMedecinDialog();
    void ouvrirRendezVousDialog();

private:
    Ui::MainWindow *ui;
    PatientDialog *patientDialog;
    MedecinDialog *medecinDialog;
};

#endif // MAINWINDOW_H
