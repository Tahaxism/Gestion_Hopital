#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QStandardPaths>
#include <QFile>
#include <QDir>  // <--- Ajouté pour QDir
#include <QDebug>
#include "mainwindow.h"  // <--- Ajouté pour MainWindow

// Fonction pour vérifier et créer la base si nécessaire
void verifierOUcreer() {
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/GestionHopital/chu.db";
    QString dbFolder = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/GestionHopital";

    QDir dir;  // Crée un objet QDir
    if (!dir.exists(dbFolder)) {
        dir.mkpath(dbFolder);  // Crée le dossier GestionHopital si inexistant
    }

    QFile dbFile(dbPath);
    if (!dbFile.exists()) {
        qDebug() << "Base de données non trouvée, création d'une nouvelle.";
        QFile::copy(QApplication::applicationDirPath() + "/chu.db", dbPath);  // Copier la base
        QFile::setPermissions(dbPath, QFileDevice::WriteOwner | QFileDevice::ReadOwner);
    } else {
        qDebug() << "Base existante détectée.";
        if (!dbFile.setPermissions(QFileDevice::WriteOwner | QFileDevice::ReadOwner)) {
            qDebug() << "Impossible de modifier les permissions.";
        }
    }
}

// Connexion à la base de données
bool connectToDatabase() {
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/GestionHopital/chu.db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données : " << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion réussie à la base de données : " << dbPath;
    return true;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);  // QApplication déclaré correctement

    // Vérifier la base et la corriger si nécessaire
    verifierOUcreer();

    if (!connectToDatabase()) {
        return -1;  // Quitte l'application si la base ne s'ouvre pas
    }

    MainWindow w;  // Crée une fenêtre principale
    w.show();
    return a.exec();
}
