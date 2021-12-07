#include "MAD.h"
#include"Dollar.h"
#include"Euro.h"
#include<iostream>
using namespace std;
using namespace Banque;
const double Banque::MAD::RatioToDollar = 1/9.24;
const double Banque::MAD::RatioToEuro = 1/10.4;
Banque::MAD::MAD(double Val):Devise(Val)
{
}

void Banque::MAD::afficher()const
{
	this->Devise::afficher();
	cout << " MAD" << endl;
}

Banque::MAD::MAD(const MAD& Val):Devise(Val)
{
}

Banque::Devise* Banque::MAD::Clone() const
{
	return new MAD(*this);
}
Dollar* Banque::MAD::ConverToDollar() const
{
	return new Dollar(this->convert(RatioToDollar));
}
Euro* Banque::MAD::ConverToEuro() const
{
	return new Euro(this->convert(RatioToEuro));
}

MAD* Banque::MAD::ConverToMAD() const
{
	return new MAD(*this);
}