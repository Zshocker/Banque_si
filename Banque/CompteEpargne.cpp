#include "CompteEpargne.h"
#include <assert.h>
Banque::CompteEpargne::CompteEpargne(Client*C, Devise*E, double v):Compte(C,E)
{
	assert(v >= 0 && v <= 100);
	TauxInterêt = v;
}

void Banque::CompteEpargne::calculInteret()
{
	this->add_pursontage(TauxInterêt);
}

bool Banque::CompteEpargne::debiter(Devise*D)
{
	if (!this->check_moitier(D))return false;
	this->Compte::debiter(D);
	return true;
}
