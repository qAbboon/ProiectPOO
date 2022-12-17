#include <iostream>
#include <string>
using namespace std;
#include "CaracteristiciLocatie.h"
#include "Zone.h"

bool isNumber2(const string& s)
{
	for (char const& ch : s)
	{
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}

CaracteristiciLocatie::CaracteristiciLocatie()
{
	maxLocuri = 0;
	adresa = "";
	nrZone = 0;
	zo = nullptr;
}

CaracteristiciLocatie::CaracteristiciLocatie(int maxLocuri, string adresa, int nrZone, Zone* zo)
{
	this->maxLocuri = maxLocuri;
	this->adresa = adresa;
	if (nrZone > 0 && zo != nullptr)
	{
		this->zo = new Zone[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			this->zo[i] = zo[i];
		}
		this->nrZone = nrZone;
	}
	else
	{
		this->zo = nullptr;
		nrZone = 0;
	}
}

int CaracteristiciLocatie::getMaxLocuri()
{
	return maxLocuri;
}

int CaracteristiciLocatie::getNrZone()
{
	return nrZone;
}

string CaracteristiciLocatie::getAdresa()
{
	return adresa;
}

int* CaracteristiciLocatie::vectorContor()
{
	int* vector = nullptr;
	if (nrZone > 0)
	{
		vector = new int[nrZone+1];
		vector[0] = 0;
		for (int i = 1; i <= nrZone; i++)
		{
			vector[i] = vector[i-1] + zo[i-1].scauneZona();
		}
	}
	return vector;
}

Zone* CaracteristiciLocatie::getZo()
{
	return zo;
}

Zone CaracteristiciLocatie::getZoind(int i)
{
	if (i >= 0 && i < nrZone)
	{
		return zo[i];
	}
}

void CaracteristiciLocatie::setNrZone(int nrZone)
{
	this->nrZone = nrZone;
}

void CaracteristiciLocatie::setMaxLocuri(int maxLocuri)
{
	this->maxLocuri = maxLocuri;
}

void CaracteristiciLocatie::setAdresa(string adresa)
{
	this->adresa = adresa;
}

void CaracteristiciLocatie::setZone(Zone* zo)
{
	if (nrZone > 0 && zo != nullptr)
	{
		if (this->zo != nullptr)
		{
			delete[] this->zo;
		}
		this->zo = new Zone[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			this->zo[i] = zo[i];
		}
	}
	else
	{
		this->zo = nullptr;
	}
}

int CaracteristiciLocatie::getTotalLocuri()
{
	int suma = 0;
	if (zo != nullptr && nrZone > 0)
	{
		for (int i = 0; i < nrZone; i++)
		{
			suma = suma + zo[i].scauneZona();
		}
	}
	return suma;
}

string CaracteristiciLocatie::locFinal(int i,int j,int q)
{
	return "Zona: " + getZoind(i).getDenumireZona() + " Randul: " + to_string(j) + " Locul: " + to_string(q);
}

CaracteristiciLocatie::CaracteristiciLocatie(const CaracteristiciLocatie& t)
{
	maxLocuri = t.maxLocuri;
	adresa = t.adresa;
	if (t.zo != nullptr && t.nrZone > 0)
	{
		zo = new Zone[t.nrZone];
		for (int i = 0; i < t.nrZone; i++)
		{
			zo[i] = t.zo[i];
		}
		nrZone = t.nrZone;
	}
	else
	{
		zo = nullptr;
		nrZone = 0;
	}
}

CaracteristiciLocatie::~CaracteristiciLocatie()
{
	if (zo != nullptr)
	{
		delete[] zo;
		zo = nullptr;
	}
}

CaracteristiciLocatie CaracteristiciLocatie::operator=(const CaracteristiciLocatie& t)
{
	if (this != &t)
	{
		maxLocuri = t.maxLocuri;
		adresa = t.adresa;
		if (zo != nullptr)
		{
			delete[] zo;
		}
		if (t.zo != nullptr && t.nrZone > 0)
		{
			zo = new Zone[t.nrZone];
			for (int i = 0; i < t.nrZone; i++)
			{
				zo[i] = t.zo[i];
			}
			nrZone = t.nrZone;
		}
		else
		{
			this->zo = nullptr;
			nrZone = 0;
		}
	}
	return *this;
}

int CaracteristiciLocatie::operator+(CaracteristiciLocatie t)
{
	return maxLocuri + t.maxLocuri;
}

bool CaracteristiciLocatie::operator>=(CaracteristiciLocatie t)
{
	if (maxLocuri > t.maxLocuri)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& out, CaracteristiciLocatie t)
{
	out << "Adresa locatiei este: " << t.adresa << endl;
	out << "Numarul maxim de locuri este: " << t.maxLocuri << endl;
	out << "Numarul de zone este: " << t.nrZone << endl;
	if (t.zo != nullptr && t.nrZone > 0)
	{
		for (int i = 0; i < t.nrZone; i++)
		{
			out << "Denumirea zonei cu numarul "<<i+1<<" este: " << t.zo[i].getDenumireZona() << endl;
			out << "Numarul de randuri pentru zona " << t.zo[i].getDenumireZona() << " este: " << t.zo[i].getNrRanduri() << endl;
			if (t.zo[i].getNrRanduri() > 0 && t.zo[i].getNrScaunePeRandadr() != nullptr)
			{
				for (int j = 0; j < t.zo[i].getNrRanduri(); j++)
				{
					out << "Numarul de scaune pentru randul " << j + 1 << " este: " << t.zo[i].getNrScaunePeRand(j) << endl;
				}
			}
		}
	}
	else
	{
		out << "Nu exista zone disponibile." << endl;
	}
	return out;
}
istream& operator>>(istream& in, CaracteristiciLocatie& t)
{
	string auxs;
	cout << "Adresa locatiei este: ";
	in >> ws;
	getline(in, t.adresa);
	cout << "Numarul maxim de locuri este: ";
	in >> ws;
	getline(in, auxs);
	while (isNumber2(auxs) == 0)
	{
		cout << "Formatul numarului maxim de locuri este gresit. Introduceti doar cifre: ";
		in >> ws;
		getline(in, auxs);
	}
	t.maxLocuri = stoi(auxs);
	while (t.maxLocuri - t.getTotalLocuri() != 0)
	{
		if (t.maxLocuri <= 0)
		{
			while (t.maxLocuri <= 0)
			{
				cout << "Ati introdus gresit numarul maxim de locuri. Va rugam sa reintroduceti numarul maxim de locuri: ";
				in >> ws;
				getline(in, auxs);
				while (isNumber2(auxs) == 0)
				{
					cout << "Formatul numarului maxim de locuri este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, auxs);
				}
				t.maxLocuri = stoi(auxs);
			}
		}
		cout << "Numarul de zone este: ";
		in >> ws;
		getline(in, auxs);
		while (isNumber2(auxs) == 0)
		{
			cout << "Formatul numarului de zone este gresit. Introduceti doar cifre: ";
			in >> ws;
			getline(in, auxs);
		}
		t.nrZone = stoi(auxs);
		if ((t.nrZone <= 0) || (t.nrZone > t.maxLocuri))
		{
			while ((t.nrZone <= 0) || (t.nrZone > t.maxLocuri))
			{
				cout << "Ati introdus gresit numarul zonelor. Va rugam sa reintroduceti numarul zonelor: ";
				in >> ws;
				getline(in, auxs);
				while (isNumber2(auxs) == 0)
				{
					cout << "Formatul numarului de zone este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, auxs);
				}
				t.nrZone = stoi(auxs);
			}
		}
		if (t.nrZone > 0)
		{
			if (t.zo != nullptr)
			{
				delete[] t.zo;
				t.zo = nullptr;
			}
			t.zo = new Zone[t.nrZone];
			for (int i = 0; i < t.nrZone; i++)
			{
				cout << endl << "Numarul de locuri ramase este: " << t.getMaxLocuri() - t.getTotalLocuri() << endl;
				string auxs;
				int auxi;
				int* auxii = nullptr;
				cout << "Denumirea zonei cu numarul " << i + 1 << " este: ";
				in >> ws;
				getline(in, auxs);
				t.zo[i].setDenumireZona(auxs);
				cout << "Numarul de randuri pentru zona " << t.zo[i].getDenumireZona() << " este: ";
				in >> ws;
				getline(in, auxs);
				while (isNumber2(auxs) == 0)
				{
					cout << "Formatul numarului de randuri este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, auxs);
				}
				auxi = stoi(auxs);
				if ((auxi <= 0) || (auxi > t.nrZone))
				{
					while ((auxi <= 0) || (auxi >t.maxLocuri- t.getTotalLocuri()))
					{
						cout << "Ati introdus gresit numarul randurilor. Va rugam sa reintroduceti numarul randurilor: ";
						in >> ws;
						getline(in, auxs);
						while (isNumber2(auxs) == 0)
						{
							cout << "Formatul numarului de randuri este gresit. Introduceti doar cifre: ";
							in >> ws;
							getline(in, auxs);
						}
						auxi = stoi(auxs);
					}
				}
				t.zo[i].setNrRanduri(auxi);
				if (t.zo[i].getNrRanduri() > 0)
				{
					auxii = new int[t.zo[i].getNrRanduri()];
					for (int j = 0; j < t.zo[i].getNrRanduri(); j++)
					{
						cout << "Numarul de scaune pentru randul " << j + 1 << " este: ";
						in >> ws;
						getline(in, auxs);
						while (isNumber2(auxs) == 0)
						{
							cout << "Formatul numarului de scaune este gresit. Introduceti doar cifre: ";
							in >> ws;
							getline(in, auxs);
						}
						auxii[j] = stoi(auxs);
						if (auxii[j] <= 0)
						{
							while (auxii[j] <= 0)
							{
								cout << "Ati introdus gresit numarul de scaune. Va rugam sa reintroduceti numarul de scaune pentru randul " << j + 1 << " : ";
								in >> ws;
								getline(in, auxs);
								while (isNumber2(auxs) == 0)
								{
									cout << "Formatul numarului de scaune este gresit. Introduceti doar cifre: ";
									in >> ws;
									getline(in, auxs);
								}
								auxii[j] = stoi(auxs);
							}
						}
					}
				}
				t.zo[i].setNrScaunePeRand(auxii);
				if (t.getMaxLocuri() - t.getTotalLocuri() < 0)
				{
					while (t.getMaxLocuri() - t.getTotalLocuri() < 0)
					{
						cout << "Numarul locurilor maxime a fost depasit. Va rugam sa reintroduceti locurile pentru ultima zona." << endl;
						if (t.zo[i].getNrRanduri() > 0)
						{
							auxii = new int[t.zo[i].getNrRanduri()];
							for (int j = 0; j < t.zo[i].getNrRanduri(); j++)
							{
								cout << "Numarul de scaune pentru randul " << j + 1 << " este: ";
								in >> ws;
								getline(in, auxs);
								while (isNumber2(auxs) == 0)
								{
									cout << "Formatul numarului de scaune este gresit. Introduceti doar cifre: ";
									in >> ws;
									getline(in, auxs);
								}
								auxii[j] = stoi(auxs);
								if (auxii[j] <= 0)
								{
									while (auxii[j] <= 0)
									{
										cout << "Ati introdus gresit numarul de scaune. Va rugam sa reintroduceti numarul de scaune pentru randul "<<j+1<<" : ";
										in >> ws;
										getline(in, auxs);
										while (isNumber2(auxs) == 0)
										{
											cout << "Formatul numarului de scaune este gresit. Introduceti doar cifre: ";
											in >> ws;
											getline(in, auxs);
										}
										auxii[j] = stoi(auxs);
									}
								}
							}
						}
						t.zo[i].setNrScaunePeRand(auxii);
					}
				}
			}
		}
		if (t.maxLocuri - t.getTotalLocuri() != 0)
		{
			cout << "Datele despre numarul zonelor, randurilor sau a locurilor pe randuri au fost introduse gresit, va rugam sa incercati din nou!";
		}
	}
	return in;
}