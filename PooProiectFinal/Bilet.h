#pragma once
#include <iostream>
using namespace std;

class Bilet
{
private:
	const int idBilet;
	static string adresa;
	string denumireEveniment;
	char* tipEveniment;
	string locBilet;
	float pret;
	string dataEveniment;
	string oraEveniment;
	string mentiuni;
public:
	void setCtid2(int);
	Bilet();
	Bilet(int, string, char*, string, float, string, string, string);
	Bilet(const Bilet&);
	static string getDataSiOra();
	int getId();
	float getPret();
	string getDenumireEveniment();
	string getMentiuni();
	string getLocBilet();
	string getData();
	string getOra();
	string getAdresa();
	string getTipStr();
	char* getTipEveniment();
	static void setAdresa(string);
	void setTipEvenimentStr(string auxs);
	~Bilet();
	Bilet& operator=(const Bilet&);
	Bilet operator--();
	Bilet operator++();
	Bilet operator--(int);
	Bilet operator++(int);
	bool operator!();
	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};

ostream& operator<<(ostream&, Bilet);
istream& operator>>(istream&, Bilet&);