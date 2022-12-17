#include <iostream>
#include <string>
#include "TestareBiletFULL.h"
#include "CaracteristiciEveniment.h"
#include "CaracteristiciLocatie.h"
#include "Zone.h"
#include "Bilet.h"
#include <stdlib.h>
#include <time.h> 
using namespace std;

bool isNumber3(const string& s)
{
	for (char const& ch : s)
	{
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}


void apelLocatie(CaracteristiciLocatie& locatie)
{
	cin >> locatie;
}

void apelEveniment(CaracteristiciEveniment& eveniment)
{
	cin >> eveniment;
}

int main()
{
	srand(time(0));
	int timpInit = (rand() % 100) * 1000000 + (rand() % 100) * 10000 + (rand() % 100) * 100 + (rand() % 100);
	cout << "Meniu"<<endl;
	int x = 99;
	int sw=0;
	float* pret=nullptr;
	Bilet* bil=nullptr;
	CaracteristiciLocatie locatie;
	CaracteristiciEveniment eveniment;
	bil->setCtid2(timpInit);
	TestareBiletFULL* bilete=nullptr;
	while (x != 0)
	{
		cout << "Alegeti o optiune prin tastarea cifrei corespunzatoare."<<endl;
		cout << "1) Introducere caracteristici locatie. "<<endl;
		cout << "2) Introducere caracteristici eveniment. "<<endl;
		cout << "3) Generare bilete."<<endl;
		cout << "4)Validare bilet." << endl;
		cin >> sw;
		if (sw == 1)
		{
			apelLocatie(locatie);
		}
		if (sw == 2)
		{
			apelEveniment(eveniment);
		}
		pret = new float[locatie.getNrZone()];
		if (sw == 3)
		{
			string auxs;
			bil = new Bilet[locatie.getMaxLocuri()];
			bil->setCtid2(timpInit);
			bil->setAdresa(locatie.getAdresa());
			for (int i = 0; i < locatie.getNrZone(); i++)
			{
				cout << "Pretul pentru zona " << locatie.getZoind(i).getDenumireZona() << " este: " ;
				cin >> ws;
				getline(cin, auxs);
				while (isNumber3(auxs) == 0)
				{
					cout << "Formatul zilei este gresit. Introduceti doar cifre: ";
					cin >> ws;
					getline(cin, auxs);
				}
				pret[i] = stoi(auxs);
			}
			int bilAux = 0;
			for (int i = 0; i < locatie.getNrZone(); i++)
			{
				for (int j = 0; j < locatie.getZoind(i).getNrRanduri(); j++)
				{
					for (int q = 0; q < locatie.getZoind(i).getNrScaunePeRand(j); q++)
					{
					Bilet biletAux(0, eveniment.getDenumire(), eveniment.getTip(), locatie.locFinal(i, j + 1,q+1), pret[i], eveniment.data(eveniment.getZi(), eveniment.getLuna(), eveniment.getAn()), eveniment.oraStr(eveniment.getOra(), eveniment.getMinut()), eveniment.getMentiuni());
					bil[bilAux++] = biletAux;
					}
				}
			}
			for (int i = 0; i < locatie.getMaxLocuri(); i++)
			{
				cout << bil[i] << endl;
			}
		}
		if (sw == 4)
		{
			if (bil != nullptr)
			{
				int idValidare;
				string auxs;
				cout << "Introduceti ID-ul biletului: ";
				cin >> ws;
				getline(cin, auxs);
				while (isNumber3(auxs) == 0)
				{
					cout << "Formatul zilei este gresit. Introduceti doar cifre: ";
					cin >> ws;
					getline(cin, auxs);
				}
				idValidare = stoi(auxs);
				cout << endl << idValidare << endl;
				bool valid;
				for (int i = 0; i < locatie.getTotalLocuri(); i++)
				{
					if (idValidare == bil[i].getId())
					{
						valid = true;
					}
					else
					{
						valid = false;
					}
				}
				if (valid == true)
				{
					cout << endl << "Biletul este valid." << endl;
				}
				else
				{
					cout << endl << "Biletul este invalid." << endl;
				}
			}
			else
			{
				cout << "Nu exista bilete disponibile." << endl;
			}
		}
		cout << "Daca doriti sa va opriti apasati 0 (altfel tastati orice alt numar)." << endl;
		cin >> x;
	}
	for (int i = 0; i < locatie.getTotalLocuri(); i++)
	{
		cout << bil[i] << endl;
	}
}
