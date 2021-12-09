#pragma once
#include"CompteCourant.h"
#include"CompteEpargne.h"
#include"ComptePayant.h"
#include"CompteEpagnePayant.h"
#include"Client.h"
#include "MAD.h"
#include"Dollar.h"
#include"Euro.h"
#include<iostream>
namespace Banque {
	class AppBanque
	{
		vector<Client*> Clients;
		int i = 0;
	public:
		void MyMain();
		void ManipCompte(Compte&);
		void Read_Client();
		void Read_Compte(Client&);
		Devise* Read_Devise();
		void Select_Client();
		void Select_Compte(Client&);
		~AppBanque();
	};
}
