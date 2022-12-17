#pragma once
#include <iostream>
using namespace std;
#include "Zone.h"

class CaracteristiciLocatie
{
private:
	int maxLocuri;
	string adresa;
	int nrZone;
	Zone* zo;
public:
	CaracteristiciLocatie();
	CaracteristiciLocatie( int, string, int,Zone*);
	CaracteristiciLocatie(const CaracteristiciLocatie&);
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
	string locFinal(int,int,int);
	~CaracteristiciLocatie();
	CaracteristiciLocatie operator=(const CaracteristiciLocatie&);
	int operator+(CaracteristiciLocatie);
	bool operator>=(CaracteristiciLocatie);
	friend ostream& operator<<(ostream&, CaracteristiciLocatie);
	friend istream& operator>>(istream&, CaracteristiciLocatie&);
};
ostream& operator<<(ostream&, CaracteristiciLocatie);
istream& operator>>(istream&, CaracteristiciLocatie&);