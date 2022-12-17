#include "TestareBiletFULL.h"
#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h> 
#include <time.h>;

int ctid = (rand() % 100) * 1000000 + (rand() % 100)*10000+(rand()%100)* 100 +(rand()%100)+(rand()%100);

TestareBiletFULL::TestareBiletFULL():id(ctid)
{
	int ctidaux = (rand() % 100);
	ctid = ctid+ctidaux;
	pret = 0;
	locatie.setMaxLocuri(0);
	locatie.setAdresa("");
	locatie.setNrZone(0);
	locatie.setZone(nullptr);
	eveniment.setZi(0);
	eveniment.setLuna(0);
	eveniment.setAn(0);	eveniment.setOra("00");
	eveniment.setMinut("00");
	eveniment.setTip(nullptr);
	eveniment.setMentiuni("");
	eveniment.setDenumire("");
}

TestareBiletFULL::TestareBiletFULL(int id,float pret, CaracteristiciLocatie locatie, CaracteristiciEveniment eveniment):id(ctid)
{
	this->pret = pret;
	this->locatie = locatie;
	this->eveniment = eveniment;
}

int TestareBiletFULL::getId()
{
	return id;
}

int TestareBiletFULL::getPretRedus(int reducere)
{
	return pret - reducere;
}

int TestareBiletFULL::getTotalPret(int nrBilete)
{
	return nrBilete * pret;
}

CaracteristiciEveniment TestareBiletFULL::getEveniment()
{
	return eveniment;
}

CaracteristiciLocatie TestareBiletFULL::getLocatie()
{
	return locatie;
}

TestareBiletFULL TestareBiletFULL::operator=(const TestareBiletFULL& t)
{
	pret = t.pret;
	locatie = t.locatie;
	eveniment = t.eveniment;
	return *this;
}

TestareBiletFULL TestareBiletFULL::operator+(int x)
{
	pret = pret + x;
	return *this;
}

TestareBiletFULL TestareBiletFULL::operator-(int x)
{
	pret = pret - x;
	return *this;
}

ostream& operator<<(ostream& out, TestareBiletFULL t)
{
	out << "ID bilet este: " << t.id<<endl;
	out << "Numar maxim de locuri: " << t.locatie.getMaxLocuri() << endl;
	out << "Adresa: " << t.locatie.getAdresa()<<endl;
	out << "Numar de zone: " << t.locatie.getNrZone() << endl;
	if (t.locatie.getNrZone() > 0 && t.locatie.getZo() != nullptr)
	{
		for (int i = 0; i < t.locatie.getNrZone(); i++)
		{
			out << "Denumirea zonei " << i + 1 << " este: " << t.locatie.getZoind(i).getDenumireZona()<<endl;
			out << "Numarul de randuri pentru zona " << t.locatie.getZoind(i).getDenumireZona() << " este: " << t.locatie.getZoind(i).getNrRanduri()<<endl;
			if (t.locatie.getZoind(i).getNrRanduri() > 0 && t.locatie.getZoind(i).getNrScaunePeRandadr()!=nullptr)
			{
				for (int j = 0; j < t.locatie.getZoind(i).getNrRanduri(); j++)
				{
					out << "Numarul de scaune pe randul " << j + 1 << " este: "<<t.locatie.getZoind(i).getNrScaunePeRand(j) << endl;
				}
			}
			else
			{
				out << "Nu exista randuri disponibile pentru zona " << t.locatie.getZoind(i).getDenumireZona() << "."<<endl;
			}
		}
	}
	out << "Denumirea evenimentului este: " << t.eveniment.getDenumire() << endl;
	out << "Data evenimentului este: " << t.eveniment.getZi() << "." << t.eveniment.getLuna() << "." << t.eveniment.getAn()<<endl;
	out << "Ora evenimentului este: " << t.eveniment.getOra() << ":" << t.eveniment.getMinut()<<endl;
	if (t.eveniment.getTip() != nullptr)
	{
		out << "Tipul evenimentului este: " << t.eveniment.getTip() << endl;
	}
	out << "Mentiuni legate de eveniment: " << t.eveniment.getMentiuni() << endl;
	out << "Pret bilet: " << t.pret<<endl;
	return out;
}
istream& operator>>(istream& in, TestareBiletFULL& t)
{
	int auxi;
	string auxs;
	Zone* auxzo;
	cout << "Pret: ";
	in >> t.pret;
	cout << "Numar maxim de locuri: ";
	in >> auxi;
	t.locatie.setMaxLocuri(auxi);
	cout << "Adresa: ";
	in >> ws;
	getline(in, auxs);
	t.locatie.setAdresa(auxs);
	cout << "Numar zone: ";
	in >> auxi;
	t.locatie.setNrZone(auxi);
	if (t.locatie.getNrZone() > 0)
	{
		auxzo = new Zone[t.locatie.getNrZone()];
		for (int i = 0; i < t.locatie.getNrZone(); i++)
		{
			string denumireZonaGB;
			int nrRanduriGB;
			cout << "Denumire zona " << i + 1 << " : ";
			in >> denumireZonaGB;
			auxzo[i].setDenumireZona(denumireZonaGB);
			cout << "Numar de randuri pentru zona " << auxzo[i].getDenumireZona()<<" : ";
			in >> nrRanduriGB;
			auxzo[i].setNrRanduri(nrRanduriGB);
			int* scpr = new int[auxzo[i].getNrRanduri()];
			for (int j = 0; j < auxzo[i].getNrRanduri(); j++)
			{
				int aux3;
				cout << "Numarul de scaune pe randul " << j + 1 << " : ";
				in >> aux3;
				scpr[j] = aux3;
			}
			auxzo[i].setNrScaunePeRand(scpr);
		}
		t.locatie.setZone(auxzo);
	}
	cout << "Zi eveniment: ";
	in >> auxi;
	t.eveniment.setZi(auxi);
	cout << "Luna eveniment: ";
	in >> auxi;
	t.eveniment.setLuna(auxi);
	cout << "An eveniment: ";
	in >> auxi;
	t.eveniment.setAn(auxi);
	cout << "Ora eveniment: ";
	in >> ws;
	getline(in, auxs);
	t.eveniment.setOra(auxs);
	cout << "Minut eveniment: ";
	in >> ws;
	getline(in, auxs);
	t.eveniment.setMinut(auxs);
	cout << "Denumire eveniment: ";
	in >> ws;
	getline(in, auxs);
	t.eveniment.setDenumire(auxs);
	cout << "Tip eveniment: ";
	in >> ws;
	getline(in, auxs);
	char* buffer=new char[auxs.length()+1];
	strcpy_s(buffer, auxs.length() + 1, auxs.c_str());
	t.eveniment.setTip(buffer);
	cout << "Mentiuni legate de eveniment: ";
	in >> ws;
	getline(in, auxs);
	t.eveniment.setMentiuni(auxs);
	return in;
}