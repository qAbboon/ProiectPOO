#include <iostream>
#include <string>
using namespace std;
#include "Bilet.h"
#include <stdlib.h>
#include <time.h>

string Bilet::adresa = "";

int ctid2 = 0;

void Bilet::setCtid2(int x)
{
	ctid2 = x;
}

Bilet::Bilet():idBilet(ctid2)
{
	int ctidaux = (rand() % 100);
	ctid2 = ctid2 + ctidaux;
	denumireEveniment = "";
	tipEveniment = nullptr;
	locBilet = "";
	pret = 0;
	dataEveniment = "";
	oraEveniment = "";
	mentiuni = "";
}

Bilet::Bilet(int idBilet, string denumireEveniment, char* tipEveniment, string locBilet, float pret, string dataEveniment, string oraEveniment, string mentiuni):idBilet(idBilet)
{
	this->denumireEveniment = denumireEveniment;
	if (tipEveniment != nullptr)
	{
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy_s(this->tipEveniment, strlen(tipEveniment) + 1, tipEveniment);
	}
	else
	{
		this->tipEveniment = nullptr;
	}
	this->locBilet = locBilet;
	this->pret = pret;
	this->dataEveniment = dataEveniment;
	this->oraEveniment = oraEveniment;
	this->mentiuni = mentiuni;
}

Bilet::Bilet(const Bilet& t):idBilet(t.idBilet)
{
	denumireEveniment = t.denumireEveniment;
	if (t.tipEveniment != nullptr)
	{
		tipEveniment = new char[strlen(t.tipEveniment) + 1];
		strcpy_s(tipEveniment, strlen(t.tipEveniment) + 1, t.tipEveniment);
	}
	else
	{
		tipEveniment = nullptr;
	}
	locBilet = t.locBilet;
	pret = t.pret;
	dataEveniment = t.dataEveniment;
	oraEveniment = t.oraEveniment;
	mentiuni = t.mentiuni;
}

string Bilet::getData()
{
	return dataEveniment;
}

string Bilet::getOra()
{
	return oraEveniment;
}

static string getDataSiOra(Bilet t)
{
	return "Data: " + t.getData() + "    Ora: " + t.getOra();
}

float Bilet::getPret()
{
	return pret;
}

int Bilet::getId()
{
	return idBilet;
}

char* Bilet::getTipEveniment()
{
	return tipEveniment;
}

string Bilet::getTipStr()
{
	string s = tipEveniment;
	return s;
}

string Bilet::getDenumireEveniment()
{
	return denumireEveniment;
}

string Bilet::getAdresa()
{
	return adresa;
}

string Bilet::getLocBilet()
{
	return locBilet;
}

string Bilet::getMentiuni()
{
	return mentiuni;
}

void Bilet::setTipEvenimentStr(string auxs)
{
	if (tipEveniment != nullptr)
	{
		delete[] tipEveniment;
	}
	tipEveniment = new char[auxs.length() + 1];
	strcpy_s(tipEveniment, auxs.length() + 1, auxs.c_str());
}

void Bilet::setAdresa(string adresa)
{
	Bilet::adresa = adresa;
}

Bilet::~Bilet()
{
	if (tipEveniment != nullptr) 
	{
		delete[] tipEveniment;
		tipEveniment = nullptr;
	}
}

Bilet& Bilet::operator=(const Bilet& t)
{
	if (this != &t)
	{
		denumireEveniment = t.denumireEveniment;
		if (tipEveniment != nullptr)
		{
			delete[] tipEveniment;
			tipEveniment = nullptr;
		}
		if (t.tipEveniment != nullptr)
		{
			tipEveniment = new char[strlen(t.tipEveniment) + 1];
			strcpy_s(tipEveniment, strlen(t.tipEveniment) + 1, t.tipEveniment);
		}
		else
		{
			tipEveniment = nullptr;
		}
		locBilet = t.locBilet;
		pret = t.pret;
		dataEveniment = t.dataEveniment;
		oraEveniment = t.oraEveniment;
		mentiuni = t.mentiuni;
	}
	return *this;
}

Bilet Bilet::operator++()
{
	pret++;
	return *this;
}

Bilet Bilet::operator--()
{
	pret--;
	return *this;
}

Bilet Bilet::operator++(int)
{
	Bilet copie = *this;
	pret++;
	return copie;
}

Bilet Bilet::operator--(int)
{
	Bilet copie = *this;
	pret--;
	return copie;
}

ostream& operator<<(ostream& out, Bilet t)
{
	out << "ID: " << t.idBilet << endl;
	out << "Adresa evenimentului este: " << t.adresa << endl;
	out << "Denumirea evenimentului este: " << t.denumireEveniment<<endl;
	if (t.tipEveniment != nullptr)
	{
		char* copie = new char[strlen(t.tipEveniment) + 1];
		strcpy_s(copie, strlen(t.tipEveniment) + 1, t.tipEveniment);
		out << "Tipul evenimentului este: " << copie << endl;
	}
	else
	{
		out << "Tipul evenimentului nu este mentionat." << endl;
	}
	out << "Locul biletului este: " << t.locBilet<<endl;
	out << "Data evenimentului este: " << t.dataEveniment<<endl;
	out << "Ora evenimentului este: " << t.oraEveniment<<endl;
	out << "Mentiuni despre eveniment: " << t.mentiuni<<endl;
	out << "Pret bilet: " << t.pret<<endl;
	return out;
}

istream& operator>>(istream& in, Bilet& t)
{
	string auxs;
	cout << "Introduceti adresa evenimentului: ";
	in >> ws;
	getline(in, auxs);
	t.setAdresa(auxs);
	cout << "Introduceti denumirea evenimentului: ";
	in >> ws;
	getline(in, t.denumireEveniment);
	cout << "Introduceti tipul evenimentului: ";
	in >> ws;
	getline(in, auxs);
	t.setTipEvenimentStr(auxs);
	cout << "Locul biletului este: ";
	in >> ws;
	getline(in, t.locBilet);
	cout << "Data evenimentului este: ";
	in >> ws;
	getline(in, t.dataEveniment);
	cout << "Ora evenimentului este: ";
	in >> ws;
	getline(in, t.oraEveniment);
	cout << "Mentiuni despre eveniment: ";
	in >> ws;
	getline(in, t.mentiuni);
	cout << "Pretul biletului este: ";
	in >> t.pret;
	return in;
}