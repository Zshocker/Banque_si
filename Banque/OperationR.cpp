#include "OperationR.h"
string Banque::OperationR::libel = "-";
Banque::OperationR::OperationR(Devise* E, Compte* c):Transaction(E, c)
{
}

void Banque::OperationR::Print() const
{
	this->print_detail();
	cout<<"Mantant: "<< libel;
	this->print_Montant();
	cout << endl;
}
