#pragma once
#include <iostream>
using namespace std;
#include "Zone.h"

class CaracteristiciLocatieText
{
private:
	int maxLocuri;
	string adresa;
	int nrZone;
	Zone* zo;
public:
	CaracteristiciLocatieText();
	CaracteristiciLocatieText(int, string, int, Zone*);
	CaracteristiciLocatieText(const CaracteristiciLocatieText&);
	int getMaxLocuri();
	int getNrZone();
	string getAdresa();
	Zone* getZo();
	Zone getZoind(int);
	int* vectorContor();
	int getTotalLocuri();
	void setMaxLocuri(int);
	void setAdresa(string);
	void setNrZone(int);
	void setZone(Zone*);
	string locFinal(int, int, int);
	~CaracteristiciLocatieText();
	CaracteristiciLocatieText operator=(const CaracteristiciLocatieText&);
	int operator+(CaracteristiciLocatieText);
	bool operator>=(CaracteristiciLocatieText);
	friend ostream& operator<<(ostream&, CaracteristiciLocatieText);
	friend istream& operator>>(istream&, CaracteristiciLocatieText&);
};
ostream& operator<<(ostream&, CaracteristiciLocatieText);
istream& operator>>(istream&, CaracteristiciLocatieText&);