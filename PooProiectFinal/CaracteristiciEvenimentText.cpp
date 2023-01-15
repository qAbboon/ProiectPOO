#include <iostream>
#include <string>
using namespace std;
#include "CaracteristiciEvenimentText.h"
#pragma warning(disable:4996)

int  getNumberOfDaysT(int month, int year)
{
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			return 29;
		else
			return 28;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
		|| month == 10 || month == 12)
		return 31;
	else
		return 30;
}

bool isNumberT(const string& s)
{
	for (char const& ch : s)
	{
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}

CaracteristiciEvenimentText::CaracteristiciEvenimentText()
{
	zi = 0;
	luna = 0;
	an = 0;
	ora = "00";
	minut = "00";
	denumire = "";
	tip = nullptr;
	mentiuni = "";
}

CaracteristiciEvenimentText::CaracteristiciEvenimentText(int zi, int luna, int an, string ora, string minut, string denumire, char* tip, string mentiuni)
{
	this->zi = zi;
	this->luna = luna;
	this->an = an;
	this->ora = ora;
	this->minut = minut;
	this->denumire = denumire;
	this->mentiuni = mentiuni;
	if (tip != nullptr)
	{
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
	else
	{
		this->tip = nullptr;
	}
}

CaracteristiciEvenimentText::CaracteristiciEvenimentText(const CaracteristiciEvenimentText& t)
{
	zi = t.zi;
	luna = t.luna;
	an = t.an;
	ora = t.ora;
	minut = t.minut;
	denumire = t.denumire;
	mentiuni = t.mentiuni;
	if (t.tip != nullptr)
	{
		tip = new char[strlen(t.tip) + 1];
		strcpy_s(tip, strlen(t.tip) + 1, t.tip);
	}
	else
	{
		tip = nullptr;
	}
}

void CaracteristiciEvenimentText::setZiT(int zi)
{
	this->zi = zi;
}

void CaracteristiciEvenimentText::setLunaT(int luna)
{
	this->luna = luna;
}

void CaracteristiciEvenimentText::setAnT(int an)
{
	this->an = an;
}

void CaracteristiciEvenimentText::setOraT(string ora)
{
	this->ora = ora;
}

void CaracteristiciEvenimentText::setMinutT(string minut)
{
	this->minut = minut;
}

void CaracteristiciEvenimentText::setDenumireT(string denumire)
{
	this->denumire = denumire;
}

int CaracteristiciEvenimentText::ceasInIntT(string ceas)
{
	int aux = stoi(ceas);
	return aux;
}

string CaracteristiciEvenimentText::dataT(int zi, int luna, int an)
{
	string d = to_string(zi) + "." + to_string(luna) + "." + to_string(an);
	return d;
}

string CaracteristiciEvenimentText::oraStrT(string ora, string minut)
{
	return ora + ":" + minut;
}

int CaracteristiciEvenimentText::getZiT()
{
	return zi;
}
int CaracteristiciEvenimentText::getLunaT()
{
	return luna;
}
int CaracteristiciEvenimentText::getAnT()
{
	return an;
}
string CaracteristiciEvenimentText::getOraT()
{
	return ora;
}
string CaracteristiciEvenimentText::getMinutT()
{
	return minut;
}
string CaracteristiciEvenimentText::getDenumireT()
{
	return denumire;
}
char* CaracteristiciEvenimentText::getTipT()
{
	if (tip != nullptr)
	{
		char* copie = new char[strlen(tip) + 1];
		strcpy_s(copie, strlen(tip) + 1, tip);
		return copie;
	}
	return nullptr;
}
string CaracteristiciEvenimentText::getMentiuniT()
{
	return mentiuni;
}

void CaracteristiciEvenimentText::setTipT(char* tip)
{
	if (tip != nullptr)
	{
		if (this->tip != nullptr)
		{
			delete[] this->tip;
		}
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
}

void CaracteristiciEvenimentText::setMentiuniT(string mentiuni)
{
	this->mentiuni = mentiuni;
}

CaracteristiciEvenimentText::~CaracteristiciEvenimentText()
{
	if (tip != nullptr)
	{
		delete[] tip;
		tip = nullptr;
	}
}

CaracteristiciEvenimentText CaracteristiciEvenimentText::operator=(const CaracteristiciEvenimentText& t)
{
	if (this != &t)
	{
		zi = t.zi;
		luna = t.luna;
		an = t.an;
		ora = t.ora;
		minut = t.minut;
		denumire = t.denumire;
		mentiuni = t.mentiuni;
		if (t.tip != nullptr)
		{
			if (tip != nullptr)
			{
				delete[] tip;
			}
			tip = new char[strlen(t.tip) + 1];
			strcpy_s(tip, strlen(t.tip) + 1, t.tip);
		}
		else
		{
			tip = nullptr;
		}
	}
	return *this;
}

bool CaracteristiciEvenimentText::operator!()
{
	if (ceasInIntT(ora) < 18)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CaracteristiciEvenimentText::operator==(CaracteristiciEvenimentText t)
{
	if (this->ora != t.ora)
	{
		return false;
	}
	if (this->minut != t.minut)
	{
		return false;
	}
	if (this->an != t.an)
	{
		return false;
	}
	if (this->luna != t.luna)
	{
		return false;
	}
	if (this->zi != t.zi)
	{
		return false;
	}
	else
	{
		return true;
	}
}

ostream& operator<<(ostream& out, CaracteristiciEvenimentText t)
{
	out << "Data evenimentului este: " << t.dataT(t.zi, t.luna, t.an) << endl;
	out << "Ora evenimentului este: " << t.ora << ":" << t.minut << endl;
	if (t.tip != nullptr)
	{
		out << "Tipul evenimentului este: " << t.tip << endl;
	}
	else
	{
		out << "Tipul evenimentului nu este mentionat." << endl;
	}
	out << "Denumirea evenimentului este: " << t.denumire << endl;
	if (t.mentiuni != "")
	{
		cout << "Mentiuni legate de eveniment: " << endl;
		cout << t.mentiuni << endl;
	}
	return out;
}

istream& operator>>(istream& in, CaracteristiciEvenimentText& t)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int anpc = 1900 + ltm->tm_year;
	int lunapc = 1 + ltm->tm_mon;
	int zipc = ltm->tm_mday;
	int orapc = ltm->tm_hour;
	int minutpc = ltm->tm_min;
	int oraI = 0;
	int minutI = 0;
	string auxs;
	in >> ws;
	getline(in, auxs);
	while (isNumberT(auxs) == 0)
	{
		in >> ws;
		getline(in, auxs);
	}
	t.an = stoi(auxs);
	if (t.an < anpc)
	{
		while (t.an < anpc)
		{
			in >> ws;
			getline(in, auxs);
			while (isNumberT(auxs) == 0)
			{
				in >> ws;
				getline(in, auxs);
			}
			t.an = stoi(auxs);
		}
	}
	in >> ws;
	getline(in, auxs);
	while (isNumberT(auxs) == 0)
	{
		in >> ws;
		getline(in, auxs);
	}
	t.luna = stoi(auxs);
	if (t.an == anpc)
	{
		if (t.luna < lunapc || t.luna>12)
		{
			while (t.luna < lunapc || t.luna>12)
			{
				in >> ws;
				getline(in, auxs);
				while (isNumberT(auxs) == 0)
				{
					in >> ws;
					getline(in, auxs);
				}
				t.luna = stoi(auxs);
			}
		}
	}
	else
	{
		while (t.luna > 12)
		{
			in >> ws;
			getline(in, auxs);
			while (isNumberT(auxs) == 0)
			{
			
				in >> ws;
				getline(in, auxs);
			}
			t.luna = stoi(auxs);
		}
	}
	in >> ws;
	getline(in, auxs);
	while (isNumberT(auxs) == 0)
	{
		in >> ws;
		getline(in, auxs);
	}
	t.zi = stoi(auxs);
	if (t.an == anpc && t.luna == lunapc)
	{
		if (t.zi < zipc || t.zi>getNumberOfDaysT(t.luna, t.an))
		{
			while (t.zi < zipc || t.zi>getNumberOfDaysT(t.luna, t.an))
			{
				in >> ws;
				getline(in, auxs);
				while (isNumberT(auxs) == 0)
				{
					in >> ws;
					getline(in, auxs);
				}
				t.zi = stoi(auxs);
			}
		}
	}
	else
	{
		while (t.zi > getNumberOfDaysT(t.luna, t.an))
		{
			in >> ws;
			getline(in, auxs);
			while (isNumberT(auxs) == 0)
			{
				in >> ws;
				getline(in, auxs);
			}
			t.zi = stoi(auxs);
		}
	}
	in >> ws;
	getline(in, t.ora);
	while (isNumberT(t.ora) == 0)
	{
		in >> ws;
		getline(in, t.ora);
	}
	if (anpc == t.an && lunapc == t.luna && zipc == t.zi)
	{
		oraI = t.ceasInIntT(t.ora);
		if (oraI < orapc || oraI >= 24)
		{
			while (oraI < orapc || oraI >= 24)
			{
				in >> ws;
				getline(in, t.ora);
				while (isNumberT(t.ora) == 0)
				{
					in >> ws;
					getline(in, t.ora);
				}
				oraI = t.ceasInIntT(t.ora);
			}
		}
	}
	else
	{
		oraI = t.ceasInIntT(t.ora);
		while (oraI > 23 || oraI < 0)
		{
			in >> ws;
			getline(in, t.ora);
			while (isNumberT(t.ora) == 0)
			{
				in >> ws;
				getline(in, t.ora);
			}
			oraI = t.ceasInIntT(t.ora);
		}
	}
	in >> ws;
	getline(in, t.minut);
	while (isNumberT(t.minut) == 0)
	{
		in >> ws;
		getline(in, t.minut);
	}
	if (anpc == t.an && lunapc == t.luna && zipc == t.zi && oraI == orapc)
	{
		minutI = t.ceasInIntT(t.minut);
		if (minutI < minutpc || minutI>24)
		{
			while (minutI < minutpc || minutI>59)
			{
				in >> ws;
				getline(in, t.minut);
				while (isNumberT(t.minut) == 0)
				{
					in >> ws;
					getline(in, t.minut);
				}
				minutI = t.ceasInIntT(t.minut);
			}
		}
	}
	else
	{
		minutI = t.ceasInIntT(t.minut);
		while (minutI > 59)
		{
			in >> ws;
			getline(in, t.minut);
			while (isNumberT(t.minut) == 0)
			{
				in >> ws;
				getline(in, t.minut);
			}
			minutI = t.ceasInIntT(t.minut);
		}
	}
	string buffer;
	in >> ws;
	getline(in, buffer);
	t.tip = new char[buffer.length() + 1];
	strcpy_s(t.tip, buffer.length() + 1, buffer.c_str());
	in >> ws;
	getline(in, t.denumire);
	in >> ws;
	getline(in, t.mentiuni);
	return in;
}