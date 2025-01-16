#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include "mainwindow.h"

bool connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/QT_Projets/GestionHopital 1.00/hopital.db");  // Chemin relatif

    if (!db.open()) {
        qDebug() << "Erreur : Impossible de se connecter à la base de données.";
        qDebug() << "Détails de l'erreur : " << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion à la base de données réussie.";
    qDebug() << "Base de données utilisée : " << db.databaseName();
    return true;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    if (!connectToDatabase()) {
        return -1;  // Arrête si la connexion échoue
    }

    MainWindow w;
    w.show();
    return a.exec();
}
