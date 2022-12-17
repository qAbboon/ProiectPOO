#pragma once
#include <iostream>
#include "CaracteristiciEveniment.h"
#include "CaracteristiciLocatie.h"
using namespace std;

class TestareBiletFULL
{
private:
	const int id;
	float pret;
	CaracteristiciLocatie locatie;
	CaracteristiciEveniment eveniment;
public:
	TestareBiletFULL();
	TestareBiletFULL(int id, float, CaracteristiciLocatie, CaracteristiciEveniment);
	int getPretRedus(int);
	int getTotalPret(int);
	int getId();
	CaracteristiciEveniment getEveniment();
	CaracteristiciLocatie getLocatie();
	TestareBiletFULL operator=(const TestareBiletFULL&);
	TestareBiletFULL operator+(int);
	TestareBiletFULL operator-(int);
	friend ostream& operator<<(ostream&, TestareBiletFULL);
	friend istream& operator>>(istream&, TestareBiletFULL&);
};

ostream& operator<<(ostream&, TestareBiletFULL);
istream& operator>>(istream&, TestareBiletFULL&);