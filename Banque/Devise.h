#pragma once
namespace Banque {
	class MAD;
	class Dollar;
	class Euro;
	class Devise
	{
	private:
		double valeur;
	public:
		Devise(double val);
		Devise(const Devise& val);
		Devise& operator+(const Devise& M) const;
		Devise& operator-(const Devise& M) const;
		Devise& operator*(const Devise& M) const;
		Devise& operator*(double val) const;
		Devise& operator/(const Devise& M) const;
		Devise& operator/(double value) const;
		bool operator<=(const Devise& M)const;
		bool operator>=(const Devise& M) const;
		double convert(double Ratio)const;
		virtual void afficher() const;
		virtual Devise* Clone() const=0;
		virtual Dollar* ConverToDollar()const=0;
		virtual MAD* ConverToMAD()const=0;
		virtual Euro* ConverToEuro()const=0;
	private:
		Devise* ConvertToMe(const Devise& D)const;
	};
};
