#pragma once
#include <iostream>
using namespace std;

class CaracteristiciEveniment
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
	CaracteristiciEveniment();
	CaracteristiciEveniment(int, int, int, string, string, string, char*,string);
	CaracteristiciEveniment(const CaracteristiciEveniment&);
	void setZi(int);
	void setLuna(int);
	void setAn(int);
	void setOra(string);
	void setMinut(string);
	void setDenumire(string);
	void setTip(char*);
	void setMentiuni(string);
	int ceasInInt(string);
	string data(int, int, int);
	int getZi();
	int getLuna();
	int getAn();
	string getOra();
	string getMinut();
	string getDenumire();
	char* getTip();
	string getMentiuni();
	string oraStr(string ora, string minut);
	~CaracteristiciEveniment();
	CaracteristiciEveniment operator=(const CaracteristiciEveniment&);
	bool operator!();
	bool operator==(CaracteristiciEveniment);
	friend ostream& operator<<(ostream&, CaracteristiciEveniment);
	friend istream& operator>>(istream&, CaracteristiciEveniment&);
};
ostream& operator<<(ostream&, CaracteristiciEveniment);
istream& operator>>(istream&, CaracteristiciEveniment&);