#include <iostream>
#include <string>
using namespace std;
#include "Admin.h"
#include <fstream>
#include <vector>

Admin::Admin()
{
	adminDrepturi = false;
}

Admin::Admin(bool adminDrepturi,string numeAngajat, bool angajatDrepturi, string userNick, int idFunctie, string parola):AngajatValidare(numeAngajat, angajatDrepturi,userNick,idFunctie,parola)
{
	this->adminDrepturi = adminDrepturi;
}

void Admin::setAdminDrepturi(bool adminDrepturi)
{
	this->adminDrepturi = adminDrepturi;
}

bool Admin::getAdminDrepturi()
{
	return adminDrepturi;
}

void Admin::afisareUseri()
{
	ifstream f;
	vector<AngajatValidare> a;
	int i = 0;
	f.open("angajati.txt");
	int citireInt; string citireString1; bool citireBool; string citireString2; string citireString3;
	while (!f.eof())
	{
		f >> ws;
		getline(f, citireString1);
		f >> citireInt;
		f >> ws;
		getline(f, citireString2);
		f >> ws;
		getline(f, citireString3);
		f >> citireBool;
		AngajatValidare angAux(citireString3, citireBool, citireString1, citireInt, citireString2);
		a.push_back(angAux);
	}	
	f.close();
	for (vector<AngajatValidare>::iterator it = a.begin(); it != a.end(); it++)
	{
		cout << *it << " ";
	}

}

void Admin::functie()
{
	if (adminDrepturi == true)
	{
		cout <<endl<< "Sunteti logat in calitate de admin. Puteti adauga locatii, evenimente si valida bilete." << endl<<endl;
	}
	if (adminDrepturi == false)
	{
		cout << "Sunteti conectat in calitate de admin, dar nu puteti face nimic pana nu activati drepturile." << endl<<endl;
	}
}

void Admin::setareFunctie()
{
	setIdFunctie(2);
	adminDrepturi = true;
	setAngajatDrepturi(true);
}