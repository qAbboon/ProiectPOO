#include <iostream>
#include <string>
using namespace std;
#include "CaracteristiciLocatieText.h"
#include "Zone.h"

bool isNumber2T(const string& s)
{
	for (char const& ch : s)
	{
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}

CaracteristiciLocatieText::CaracteristiciLocatieText()
{
	maxLocuri = 0;
	adresa = "";
	nrZone = 0;
	zo = nullptr;
}

CaracteristiciLocatieText::CaracteristiciLocatieText(int maxLocuri, string adresa, int nrZone, Zone* zo)
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

int CaracteristiciLocatieText::getMaxLocuri()
{
	return maxLocuri;
}

int CaracteristiciLocatieText::getNrZone()
{
	return nrZone;
}

string CaracteristiciLocatieText::getAdresa()
{
	return adresa;
}

int* CaracteristiciLocatieText::vectorContor()
{
	int* vector = nullptr;
	if (nrZone > 0)
	{
		vector = new int[nrZone + 1];
		vector[0] = 0;
		for (int i = 1; i <= nrZone; i++)
		{
			vector[i] = vector[i - 1] + zo[i - 1].scauneZona();
		}
	}
	return vector;
}

Zone* CaracteristiciLocatieText::getZo()
{
	return zo;
}

Zone CaracteristiciLocatieText::getZoind(int i)
{
	if (i >= 0 && i < nrZone)
	{
		return zo[i];
	}
}

void CaracteristiciLocatieText::setNrZone(int nrZone)
{
	this->nrZone = nrZone;
}

void CaracteristiciLocatieText::setMaxLocuri(int maxLocuri)
{
	this->maxLocuri = maxLocuri;
}

void CaracteristiciLocatieText::setAdresa(string adresa)
{
	this->adresa = adresa;
}

void CaracteristiciLocatieText::setZone(Zone* zo)
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

int CaracteristiciLocatieText::getTotalLocuri()
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

string CaracteristiciLocatieText::locFinal(int i, int j, int q)
{
	return "Zona: " + getZoind(i).getDenumireZona() + " Randul: " + to_string(j) + " Locul: " + to_string(q);
}

CaracteristiciLocatieText::CaracteristiciLocatieText(const CaracteristiciLocatieText& t)
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

CaracteristiciLocatieText::~CaracteristiciLocatieText()
{
	if (zo != nullptr)
	{
		delete[] zo;
		zo = nullptr;
	}
}

CaracteristiciLocatieText CaracteristiciLocatieText::operator=(const CaracteristiciLocatieText& t)
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

int CaracteristiciLocatieText::operator+(CaracteristiciLocatieText t)
{
	return maxLocuri + t.maxLocuri;
}

bool CaracteristiciLocatieText::operator>=(CaracteristiciLocatieText t)
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

ostream& operator<<(ostream& out, CaracteristiciLocatieText t)
{
	out << "Adresa locatiei este: " << t.adresa << endl;
	out << "Numarul maxim de locuri este: " << t.maxLocuri << endl;
	out << "Numarul de zone este: " << t.nrZone << endl;
	if (t.zo != nullptr && t.nrZone > 0)
	{
		for (int i = 0; i < t.nrZone; i++)
		{
			out << "Denumirea zonei cu numarul " << i + 1 << " este: " << t.zo[i].getDenumireZona() << endl;
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
istream& operator>>(istream& in, CaracteristiciLocatieText& t)
{
	string auxs;
	in >> ws;
	getline(in, t.adresa);
	in >> ws;
	getline(in, auxs);
	while (isNumber2T(auxs) == 0)
	{
		in >> ws;
		getline(in, auxs);
	}
	t.maxLocuri = stoi(auxs);
	int hlp = 0;
	while (t.maxLocuri - hlp != 0)
	{
		if (t.maxLocuri <= 0)
		{
			while (t.maxLocuri <= 0)
			{
				
				in >> ws;
				getline(in, auxs);
				while (isNumber2T(auxs) == 0)
				{
					
					in >> ws;
					getline(in, auxs);
				}
				t.maxLocuri = stoi(auxs);
			}
		}
		in >> ws;
		getline(in, auxs);
		while (isNumber2T(auxs) == 0)
		{
			in >> ws;
			getline(in, auxs);
		}
		t.nrZone = stoi(auxs);
		if ((t.nrZone <= 0) || (t.nrZone > t.maxLocuri))
		{
			while ((t.nrZone <= 0) || (t.nrZone > t.maxLocuri))
			{
				in >> ws;
				getline(in, auxs);
				while (isNumber2T(auxs) == 0)
				{
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
				string auxs;
				int auxi;
				int* auxii = nullptr;
				in >> ws;
				getline(in, auxs);
				t.zo[i].setDenumireZona(auxs);
				in >> ws;
				getline(in, auxs);
				while (isNumber2T(auxs) == 0)
				{
					in >> ws;
					getline(in, auxs);
				}
				auxi = stoi(auxs);
				if ((auxi <= 0) || (auxi > t.nrZone))
				{
					while ((auxi <= 0) || (auxi > t.maxLocuri - t.getTotalLocuri()))
					{
						in >> ws;
						getline(in, auxs);
						while (isNumber2T(auxs) == 0)
						{
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
						in >> ws;
						getline(in, auxs);
						while (isNumber2T(auxs) == 0)
						{
							in >> ws;
							getline(in, auxs);
						}
						auxii[j] = stoi(auxs);
						if (auxii[j] <= 0)
						{
							while (auxii[j] <= 0)
							{
								in >> ws;
								getline(in, auxs);
								while (isNumber2T(auxs) == 0)
								{
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
						if (t.zo[i].getNrRanduri() > 0)
						{
							auxii = new int[t.zo[i].getNrRanduri()];
							for (int j = 0; j < t.zo[i].getNrRanduri(); j++)
							{
								in >> ws;
								getline(in, auxs);
								while (isNumber2T(auxs) == 0)
								{
									in >> ws;
									getline(in, auxs);
								}
								auxii[j] = stoi(auxs);
								if (auxii[j] <= 0)
								{
									while (auxii[j] <= 0)
									{
										in >> ws;
										getline(in, auxs);
										while (isNumber2T(auxs) == 0)
										{

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
		}
		hlp = t.getTotalLocuri();
	}
	return in;
}