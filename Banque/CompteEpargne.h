#pragma once
#include "Compte.h"
namespace Banque {
    class CompteEpargne : virtual public Compte
    {
        double TauxInterêt;
    public:
        CompteEpargne(Client*, Devise*, double);
        void calculInteret();
        bool debiter(Devise* D);
    };
}
