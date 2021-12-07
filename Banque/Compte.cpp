#include "Compte.h"
#include"OperationR.h"
#include"operationV.h"
#include"MAD.h"
#include<iostream>
using namespace std;
using namespace Banque;
Devise* Compte::plafond = new MAD(2000);
int Compte::count = 0;

Banque::Compte::Compte(Client* titu, Devise* sol) :numcompte(++count)
{
	this->titulaire = titu;
	this->solde = sol;
	this->titulaire->add_Compte(this);
}

void Banque::Compte::crediter(Devise* M)
{
	*(this->solde) = *(this->solde) + *M;
	this->add_transaction(M, true);
}

bool Banque::Compte::debiter(Devise* M)
{
	if (*solde>=*M && *M <= *(Compte::plafond))
	{
		this->debiter_direct(M);
		return true;
	}
	return false;
}

Banque::Compte::Compte(const Compte& c) :numcompte(c.numcompte)
{
	this->solde = c.solde;
	this->titulaire = c.titulaire;
}

bool Banque::Compte::verser(Devise* M, Compte& C)
{
	if (this->debiter(M) == true) {
		C.crediter(M);
		return true;
	}
	return false;
}

void Banque::Compte::add_pursontage(double D)
{
	*solde = *solde + *solde * (D/100);
}

bool Banque::Compte::check_moitier(Devise* D) const
{
	Devise&E = *solde / 2;
	bool Res = false;
	if (E >= *D) Res = true;
	delete &E;
	return Res;
}

bool Banque::Compte::check_Solde_sup(Devise& D) const
{
	return (*solde>=D);
}

void Banque::Compte::debiter_direct(Devise* M)
{
	*(this->solde) = *(this->solde) - *M;
	this->add_transaction(M, false);
}

void Banque::Compte::add_transaction(Devise * Amount, bool Type)
{
	if(Type)Trans.push_back(new OperationV(Amount, this));
	else Trans.push_back(new OperationR(Amount, this));
}
void Banque::Compte::consulter() const
{
	cout << "num compte=" << this->numcompte << endl<< "le solde est : ";
	this->solde->afficher();
	cout << "titulaire " << endl;
	this->titulaire->Afficher();
}

void Banque::Compte::consulter_with_history() const
{
	consulter();
	for (int i = 0; i < Trans.size(); i++)
	{
		Trans[i]->Print();
	}
}

Compte::~Compte() {
	delete solde;
	for (int i = 0; i < Trans.size(); i++)
	{
		delete Trans[i];
		Trans[i]=NULL;
	}
}