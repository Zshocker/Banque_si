#pragma once
#include"Client.h"
#include"Transaction.h"
#include "Devise.h"
#include<vector>
using namespace std;
namespace Banque {
	class Client;
	class Compte
	{
	private:
		const int numcompte;
		static int count;
		Client* titulaire;
		Devise* solde;
		static Devise* plafond;
		vector<Transaction*> Trans;
	public:
		Compte(Client*, Devise*);
		Compte(Devise*);
		Compte(const Compte&);
		void Link_Client(Client*);
		virtual void crediter(Devise* M);
		virtual bool debiter(Devise* M)=0;
		bool verser(Devise* M, Compte& C);
		void consulter()const;
		void consulter_with_history()const;
		virtual ~Compte();
	protected:
		void add_pursontage(double D);
		bool check_moitier(Devise* D)const;
		bool check_Solde_sup(Devise& D)const;
		void debiter_direct(Devise*M);
		void add_transaction(Devise* Amount, bool Type);
	};
};