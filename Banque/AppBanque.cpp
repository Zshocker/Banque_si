#include "AppBanque.h"
using namespace Banque;
void Banque::AppBanque::MyMain()
{
	int choix;
	Read_Client();
	Read_Compte(*(Clients[0]));
	do
	{
		cout << "1-Create Client" << endl;
		cout << "2-Select Client" << endl;
		cout << "other-exit" << endl;
		cout << "donner votre choix:";
		cin >> choix;
		cout << "------------------------------------------" << endl;
		switch (choix)
		{
		case 1:
			Read_Client();
			break;
		case 2:
			Select_Client();
			break;
		default:
			exit(0);
			break;
		}
		cout << "------------------------------------------" << endl;
	} while (true);
}
void Banque::AppBanque::ManipCompte(Compte&A)
{
	int choix;
	double Val;
	Devise* Esd;
	do
	{
		cout << "0-return To Comptes Section" << endl;
		cout << "1-retrait" << endl;
		cout << "2-crediter" << endl;
		cout << "3-consuler" << endl;
		cout << "4-history" << endl;
		cout << "donner votre choix:";
		cin >> choix;
		cout << "------------------------------------------" << endl;
		switch (choix)
		{
		case 1:
			Esd = Read_Devise();
			if (A.debiter(Esd))cout << "Done!" << endl;
			else cout << "Not Enough money" << endl;
			break;
		case 2:
			Esd = Read_Devise();
			A.crediter(Esd);
			break;
		case 3:
			A.consulter();
			break;
		case 4:
			A.consulter_with_history();
			break;
		default:
			return;
		}
		cout << "------------------------------------------" << endl;
	} while (1);
}

void Banque::AppBanque::Read_Client()
{
	cout << "------------------------------------------" << endl;
	Client* E;
	string nom,prenom,adres;
	cout << "\nnom:";
	cin >> nom;
	cout << "\nprenom:";
	cin >> prenom;
	cout << "\naddress:";
	cin >> adres;
	E= new Client(nom, prenom, adres);
	Clients.push_back(E);
	cout << "------------------------------------------" << endl;
}

void Banque::AppBanque::Read_Compte(Client&Cli)
{
	Devise* Mant;
	Devise* dec;
	double pur;
	cout << "------------------------------------------" << endl;
	int choix;
	cout << "\nSelect type de Compte \n1-Compte Courant \n2-Compte Epargne \n3-Compte Payant\nother-Compte Epargne Payant\n";
	cin >> choix;
	switch (choix)
	{
	case 1:
		cout << "\ndécouvert: ";
		dec = Read_Devise();
		cout << "\nSolde De depart: ";
		Mant = Read_Devise();
		new CompteCourant(&Cli, Mant, dec);
		break;
	case 2:
		cout << "\TauxInterêt: ";
		cin >> pur;
		cout << "\TauxInterêt: ";
		cout << "\nSolde De depart: ";
		Mant = Read_Devise();
		new CompteEpargne(&Cli, Mant, pur);
		break;
	case 3:
		cout << "\ndécouvert: ";
		dec = Read_Devise();
		cout << "\nSolde De depart: ";
		 Mant = Read_Devise();
		new ComptePayant(&Cli, Mant, dec);
		break;
	default:
		cout << "\TauxInterêt: ";
		cin >> pur;
		cout << "\ndécouvert: ";
		dec = Read_Devise();
		cout << "\nSolde De depart: ";
		Mant = Read_Devise();
		new CompteEpagnePayant(&Cli, Mant, dec, pur);
		break;
	}
	cout << "------------------------------------------" << endl;
}
Devise* Banque::AppBanque::Read_Devise()
{
	int choix;
	double Es;
	Devise* E;
	cout << "\nSelect type de Montant \n1-MAD \n2-Dollar \nother-Euro\n";
	cin >> choix;
	cout << "Mantant:";
	cin >> Es;
	switch (choix)
	{
	case 1:
		E = new MAD(Es);
		break;
	case 2:
		E = new Dollar(Es);
		break;
	default:
		E = new Euro(Es);
		break;
	}
	return E;
}

void Banque::AppBanque::Select_Client()
{
	cout << "\nSelect un Client:";
	for (int i = 0; i < Clients.size(); i++)
	{
		cout << "\n"<<i<<"-{";
		Clients[i]->Afficher();
		cout << "}";
	}
	cout << endl;
	int a;
	cin >> a;
	do
	{
		int choix;
		cout << "\n1-ajouter un Compte:";
		cout << "\n2-Select un Compte:";
		cout << "\nother-Return To Client Section:";
		cin >> choix;
		switch (choix)
		{
		case 1:
			Read_Compte(*Clients[a]);
			break;
		case 2:
			Select_Compte(*Clients[a]);
			break;
		case 3:
			return;
			break;
		}
	} while (true);
	
}

void Banque::AppBanque::Select_Compte(Client&E)
{
	Compte &Com=E.Select_Compte();
	ManipCompte(Com);
}
