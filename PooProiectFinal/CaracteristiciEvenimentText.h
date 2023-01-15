#pragma once
#include <iostream>
using namespace std;

class CaracteristiciEvenimentText
{
private:
	int zi;
	int luna;
	int an;
	string ora;
	string minut;
	string denumire;
	char* tip;
	string mentiuni;
public:
	CaracteristiciEvenimentText();
	CaracteristiciEvenimentText(int, int, int, string, string, string, char*, string);
	CaracteristiciEvenimentText(const CaracteristiciEvenimentText&);
	void setZiT(int);
	void setLunaT(int);
	void setAnT(int);
	void setOraT(string);
	void setMinutT(string);
	void setDenumireT(string);
	void setTipT(char*);
	void setMentiuniT(string);
	int ceasInIntT(string);
	string dataT(int, int, int);
	int getZiT();
	int getLunaT();
	int getAnT();
	string getOraT();
	string getMinutT();
	string getDenumireT();
	char* getTipT();
	string getMentiuniT();
	string oraStrT(string ora, string minut);
	~CaracteristiciEvenimentText();
	CaracteristiciEvenimentText operator=(const CaracteristiciEvenimentText&);
	bool operator!();
	bool operator==(CaracteristiciEvenimentText);
	friend ostream& operator<<(ostream&, CaracteristiciEvenimentText);
	friend istream& operator>>(istream&, CaracteristiciEvenimentText&);
};
ostream& operator<<(ostream&, CaracteristiciEvenimentText);
istream& operator>>(istream&, CaracteristiciEvenimentText&);