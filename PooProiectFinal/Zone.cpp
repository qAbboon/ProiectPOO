#include <iostream>
#include <string>
using namespace std;
#include "Zone.h"

Zone::Zone()
{
	denumireZona = "";
	nrRanduri = 0;
	nrScaunePeRand = nullptr;
}

Zone::Zone(string denumireZona, int nrRanduri, int* nrScaunePeRand)
{
	this->denumireZona = denumireZona;
	this->nrRanduri = nrRanduri;
	if (nrRanduri > 0 && nrScaunePeRand != nullptr)
	{
		this->nrScaunePeRand = new int[nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
		{
			this->nrScaunePeRand[i] = nrScaunePeRand[i];
		}
	}
	else
	{
		this->nrScaunePeRand = nullptr;
	}
}

string Zone::getDenumireZona()
{
	return denumireZona;
}

void Zone::setDenumireZona(string denumireZona)
{
	this->denumireZona = denumireZona;
}
void Zone::setNrRanduri(int nrRanduri)
{
	this->nrRanduri = nrRanduri;
}
void Zone::setNrScaunePeRand(int* nrScaunePeRand)
{
	if (nrScaunePeRand != nullptr)
	{
		delete[] this->nrScaunePeRand;
		this->nrScaunePeRand = new int[nrRanduri];
		for (int i = 0; i < nrRanduri; i++)
		{
			this->nrScaunePeRand[i] = nrScaunePeRand[i];
		}
	}
}

int Zone::getNrRanduri()
{
	return nrRanduri;
}

int Zone::getNrScaunePeRand(int i)
{
	if (i >= 0 && i < nrRanduri)
	{
		return nrScaunePeRand[i];
	}
	else
	{
		return 0;
	}
}

int* Zone::getNrScaunePeRandadr() 
{
	return nrScaunePeRand;
}

int Zone::scauneZona()
{
	int suma = 0;
	if (nrRanduri > 0 && nrScaunePeRand!=nullptr)
	{
		for (int i = 0; i < nrRanduri; i++)
		{
			suma = suma + nrScaunePeRand[i];
		}
		return suma;
	}
	else
	{
		return 0;
	}
}

float Zone::medieScaunePeRand(Zone x)
{
	float med = 0;
	if (x.scauneZona() != 0)
	{
		med = x.scauneZona();
		med = med / x.nrRanduri;
	}
	return med;
}

Zone::~Zone()
{
	if (nrScaunePeRand != nullptr)
	{
		delete[] nrScaunePeRand;
		nrScaunePeRand = nullptr;
	}
}

Zone::Zone(const Zone& con)
{
	denumireZona = con.denumireZona;
	if (con.nrRanduri > 0 && con.nrScaunePeRand != nullptr)
	{
		nrScaunePeRand = new int[con.nrRanduri];
		for (int i = 0; i < con.nrRanduri; i++)
		{
			nrScaunePeRand[i] = con.nrScaunePeRand[i];
		}
		nrRanduri = con.nrRanduri;
	}
	else
	{
		nrScaunePeRand = nullptr;
		nrRanduri = 0;
	}
}

Zone& Zone::operator=(const Zone& con)
{
	if (this != &con)
	{
		denumireZona = con.denumireZona;
		if (nrScaunePeRand != nullptr)
		{
			delete[] nrScaunePeRand;
		}
		if (con.nrRanduri > 0 && con.nrScaunePeRand != nullptr)
		{
			nrScaunePeRand = new int[con.nrRanduri];
			for (int i = 0; i < con.nrRanduri; i++)
			{
				nrScaunePeRand[i] = con.nrScaunePeRand[i];
			}
			nrRanduri = con.nrRanduri;
		}
		else
		{
			nrScaunePeRand = nullptr;
			nrRanduri = 0;
		}
	}
	return *this;
}

int& Zone::operator[](int i)
{
	if (i >= 0 && i < nrRanduri && nrScaunePeRand != nullptr)
	{
		return nrScaunePeRand[i];
	}
}

bool Zone::operator!()
{
	if (nrScaunePeRand = nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ostream& operator<<(ostream& out, Zone t)
{
	out << "Denumirea zonei este: " << t.denumireZona << endl;
	out << "Numarul de randuri pentru zona " << t.denumireZona << " este: " <<t.nrRanduri<< endl;
	if (t.nrRanduri > 0 && t.nrScaunePeRand != nullptr)
	{
		for (int i = 0; i < t.nrRanduri; i++)
		{
			out << "Numarul de scaune pentru randul " << i + 1 << " este: " << t.nrScaunePeRand[i]<<endl;
		}
	}
	else
	{
		out << "Nu exista randuri."<<endl;
	}
	return out;
}

istream& operator>>(istream& in, Zone& t)
{
	cout << "Denumirea zonei este: " ;
	in >> ws;
	getline(in, t.denumireZona);
	cout << "Numarul de randuri pentru zona " << t.denumireZona << " este: " ;
	in >> t.nrRanduri;
	if (t.nrRanduri > 0)
	{
		if (t.nrScaunePeRand != nullptr)
		{
			delete[] t.nrScaunePeRand;
			t.nrScaunePeRand = nullptr;
		}
		t.nrScaunePeRand = new int[t.nrRanduri];
		for (int i = 0; i < t.nrRanduri; i++)
		{
			cout << "Numarul de scaune pentru randul " << i + 1 << " este: ";
			in >> t.nrScaunePeRand[i];
		}
	}
	return in;
}
