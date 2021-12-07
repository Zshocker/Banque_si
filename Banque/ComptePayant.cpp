#include "ComptePayant.h"

Banque::ComptePayant::ComptePayant(Client*C, Devise*D, Devise*E):CompteCourant(C,D,E),Compte(C,D)
{
}

bool Banque::ComptePayant::debiter(Devise *D)
{
	if(!this->CompteCourant::debiter(D)) return false;
	Devise* E=D->Clone();
	*E = *E * 0.05;
	this->debiter_direct(E);
	return true;
}

void Banque::ComptePayant::crediter(Devise* M)
{
	this->CompteCourant::crediter(M);
	Devise *E=M->Clone();
	*E = *E * 0.05;
	this->debiter_direct(E);
}
