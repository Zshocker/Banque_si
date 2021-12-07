#include "operationV.h"
string Banque::OperationV::libel = "+";
Banque::OperationV::OperationV(Devise* E, Compte* c):Transaction(E,c)
{
}

void Banque::OperationV::Print() const
{
	this->print_detail();
	cout << "Mantant: " << libel;
	this->print_Montant();
	cout << endl;
}
