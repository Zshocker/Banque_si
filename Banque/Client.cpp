#include "Client.h"
#include"Compte.h"
#include <iostream>
using namespace Banque;
using namespace std;
Banque::Client::Client(string n, string p, string a)
{
	this->nom = n;
	this->prenom = p;
	this->adresse = a;
}

void Banque::Client::add_Compte(Compte*A)
{
	bool notFound = (std::find(Comptes.begin(), Comptes.end(), A) == Comptes.end());
	if (notFound)Comptes.push_back(A);
}

Compte& Banque::Client::Select_Compte()
{
	cout << "\nSelect un Compte:";
	for (int i = 0; i < Comptes.size(); i++)
	{
		cout << "\n" << i << "-{";
		Comptes[i]->consulter();
		cout << "}";
	}
	cout << endl;
	int a;
	cin >> a;
	return *Comptes[a];
}

void Banque::Client::Afficher() const
{
	cout << "nom :" << this->nom << "\n" << "prenom:" << this->prenom << "\n" << "Adresse:" << this->adresse << endl;
}

Banque::Client::~Client()
{
	for (int i = 0; i < Comptes.size(); i++)
	{
		delete Comptes[i];
		Comptes[i] = NULL;
	}
}
