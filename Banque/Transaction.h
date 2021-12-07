#pragma once
#include"Devise.h"
#include<iostream>
using namespace std;
namespace Banque {
	class Compte;
	class Transaction
	{
		static long incr;
		const long numT;
		string date;
		string heure;
		Devise* Val;
		Compte* E;
	public:
		Transaction(Devise* Val, Compte*);
		void print_detail()const;
		void print_Montant()const;
		virtual void Print()const=0;
	};
}