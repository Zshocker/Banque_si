#include "Devise.h"
#include"MAD.h"
#include"Dollar.h"
#include"Euro.h"
#include  <iostream>
#include<typeinfo>
#include<assert.h>
using namespace std;
using namespace Banque;
Devise::Devise(double val)
{
	this->valeur = val;
}

Banque::Devise::Devise(const Devise& val)
{
	this->valeur = val.valeur;
}

Devise& Devise::operator+(const Devise& M) const
{
	Devise* res = this->Clone();
	double value;
	if (typeid(*this).name() != typeid(M).name()) 
	{
		Devise* E = this->ConvertToMe(M);
		value = E->valeur;
		delete E;
	}else value = M.valeur;
	value += this->valeur;
	res->valeur = value;
	return *res;
}

Devise& Devise::operator-(const Devise& M) const
{
	Devise* res = this->Clone();
	double value;
	if (typeid(*this).name() != typeid(M).name())
	{
		Devise* E = this->ConvertToMe(M);
		value = E->valeur;
		delete E;
	}
	else value = M.valeur;
	value = this->valeur-value;
	res->valeur = value;
	return *res;
}

Devise& Banque::Devise::operator*(const Devise& M) const
{
	Devise* res = this->Clone();
	double value;
	if (typeid(*this).name() != typeid(M).name())
	{
		Devise* E = this->ConvertToMe(M);
		value = E->valeur;
		delete E;
	}
	else value = M.valeur;
	value *= this->valeur;
	res->valeur = value;
	return *res;
}

Devise& Banque::Devise::operator*(double val) const
{
	Devise* res = this->Clone();
	res->valeur = this->valeur * val;
	return *res;
}

Devise& Banque::Devise::operator/(const Devise& M) const
{
	assert(M.valeur!=0);
	Devise* res = this->Clone();
	double value;
	if (typeid(*this).name() != typeid(M).name())
	{
		Devise* E = this->ConvertToMe(M);
		value = E->valeur;
		delete E;
	}
	else value = M.valeur;
	value = this->valeur / value;
	res->valeur = value;
	return *res;
}

Devise& Banque::Devise::operator/(double value) const
{
	Devise * E= this->Clone();
	E->valeur = this->valeur / value;
	return *E;
}

bool Devise::operator<=(const Devise& M) const
{
	double value;
	if (typeid(*this).name() != typeid(M).name())
	{
		Devise* E = this->ConvertToMe(M);
		value = E->valeur;
		delete E;
	}
	else value = M.valeur;
	return this->valeur <=value;
}

bool Devise::operator>=(const Devise& M) const
{
	double value;
	if (typeid(*this).name() != typeid(M).name())
	{
		Devise* E = this->ConvertToMe(M);
		value = E->valeur;
		delete E;
	}
	else value = M.valeur;
	return this->valeur >= value;
}

double Banque::Devise::convert(double Ratio)const
{
	return valeur*Ratio;
}

void Banque::Devise::afficher() const
{
	cout<<valeur;
}

Devise* Banque::Devise::ConvertToMe(const Devise&D)const
{
	if (typeid(*this) == typeid(MAD))return D.ConverToMAD();
	if (typeid(*this) == typeid(Dollar))return D.ConverToDollar();
	if (typeid(*this) == typeid(Euro))return D.ConverToEuro();
}




