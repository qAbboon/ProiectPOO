#pragma once
#include <iostream>
using namespace std;

class Zone
{
private:
	string denumireZona;
	int nrRanduri;
	int* nrScaunePeRand;
public:
	Zone();
	Zone(string, int, int*);
	Zone(const Zone&);
	void setDenumireZona(string);
	void setNrRanduri(int);
	void setNrScaunePeRand(int*);
	string getDenumireZona();
	int getNrRanduri();
	int getNrScaunePeRand(int);
	int* getNrScaunePeRandadr();
	int scauneZona();
	static float medieScaunePeRand(Zone);
	~Zone();
	Zone& operator=(const Zone&);
	friend ostream& operator<<(ostream&, Zone);
	friend istream& operator>>(istream&, Zone&);
	int& operator[](int);
	bool operator!();
};
ostream& operator<<(ostream&, Zone );
istream& operator>>(istream&, Zone&);