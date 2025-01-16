#ifndef RENDEZVOUSMANAGER_H
#define RENDEZVOUSMANAGER_H

#include <QVector>
#include "rendezvous.h"

class RendezVousManager {
public:
    bool ajouterRendezVous(const RendezVous &rdv);
    bool modifierRendezVous(const RendezVous &rdv);
    bool supprimerRendezVous(int id_rdv);

    QVector<RendezVous> getRendezVous();
};

#endif // RENDEZVOUSMANAGER_H
