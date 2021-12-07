#include "Dollar.h"
#include"MAD.h"
#include"Euro.h"
#include<iostream>
using namespace std;
using namespace Banque;
const double Banque::Dollar::RatioToMAD = 9.24;
const double Banque::Dollar::RatioToEuro = 1/1.13;
Banque::Dollar::Dollar(double Val) :Devise(Val)
{
}

Banque::Dollar::Dollar(const Dollar& Val) : Devise(Val)
{
}

void Banque::Dollar::afficher() const
{
	this->Devise::afficher();
	cout << " Dollar" << endl;
}

Devise* Banque::Dollar::Clone() const
{
	return new Dollar(*this);
}

Dollar* Banque::Dollar::ConverToDollar() const
{
	return new Dollar(*this);
}

MAD* Banque::Dollar::ConverToMAD() const
{
	return new MAD(this->convert(RatioToMAD));
}

Euro* Banque::Dollar::ConverToEuro() const
{
	return new Euro(this->convert(RatioToEuro));
}

