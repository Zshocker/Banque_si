#include"Euro.h"
#include"Dollar.h"
#include"MAD.h"
#include<iostream>
using namespace std;
using namespace Banque;
const double Banque::Euro::RatioToDollar = 1.13;
const double Banque::Euro::RatioToMAD = 10.4;
Banque::Euro::Euro(double Val) :Devise(Val)
{
}

void Banque::Euro::afficher()const
{
	this->Devise::afficher();
	cout << " Euro" << endl;
}

Banque::Euro::Euro(const Euro& Val):Devise(Val)
{
}

Banque::Devise* Banque::Euro::Clone() const
{
	return new Euro(*this);
}


Dollar* Banque::Euro::ConverToDollar() const
{
	return new Dollar(this->convert(RatioToDollar));
}

MAD* Banque::Euro::ConverToMAD() const
{
	return new MAD(this->convert(RatioToMAD));
}

Euro* Banque::Euro::ConverToEuro() const
{
	return new Euro(*this);
}

