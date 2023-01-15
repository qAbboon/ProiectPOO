#include <iostream>
#include <string>
using namespace std;
#include "CaracteristiciEveniment.h"
#pragma warning(disable:4996)

int  getNumberOfDays(int month, int year)
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

bool isNumber(const string& s)
{
	for (char const& ch : s)
	{
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}

CaracteristiciEveniment::CaracteristiciEveniment()
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

CaracteristiciEveniment::CaracteristiciEveniment(int zi,int luna,int an,string ora,string minut,string denumire,char* tip,string mentiuni)
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

CaracteristiciEveniment::CaracteristiciEveniment(const CaracteristiciEveniment& t)
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

void CaracteristiciEveniment::setZi(int zi)
{
	this->zi = zi;
}

void CaracteristiciEveniment::setLuna(int luna)
{
	this->luna = luna;
}

void CaracteristiciEveniment::setAn(int an)
{
	this->an = an;
}

void CaracteristiciEveniment::setOra(string ora)
{
	this->ora = ora;
}

void CaracteristiciEveniment::setMinut(string minut)
{
	this->minut = minut;
}

void CaracteristiciEveniment::setDenumire(string denumire)
{
	this->denumire = denumire;
}

int CaracteristiciEveniment::ceasInInt(string ceas)
{
	int aux = stoi(ceas);
	return aux;
}

string CaracteristiciEveniment::data(int zi, int luna, int an)
{
	string d = to_string(zi) + "." + to_string(luna) + "." + to_string(an);
	return d;
}

string CaracteristiciEveniment::oraStr(string ora, string minut)
{
	return ora + ":" + minut;
}

int CaracteristiciEveniment::getZi()
{
	return zi;
}
int CaracteristiciEveniment::getLuna()
{
	return luna;
}
int CaracteristiciEveniment::getAn()
{
	return an;
}
string CaracteristiciEveniment::getOra()
{
	return ora;
}
string CaracteristiciEveniment::getMinut()
{
	return minut;
}
string CaracteristiciEveniment::getDenumire()
{
	return denumire;
}
char* CaracteristiciEveniment::getTip()
{
	if (tip != nullptr)
	{
		char* copie = new char[strlen(tip) + 1];
		strcpy_s(copie, strlen(tip) + 1, tip);
		return copie;
	}
	return nullptr;
}
string CaracteristiciEveniment::getMentiuni()
{
	return mentiuni;
}

void CaracteristiciEveniment::setTip(char* tip)
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

void CaracteristiciEveniment::setMentiuni(string mentiuni)
{
	this->mentiuni = mentiuni;
}

CaracteristiciEveniment::~CaracteristiciEveniment()
{
	if (tip != nullptr)
	{
		delete[] tip;
		tip = nullptr;
	}
}

CaracteristiciEveniment CaracteristiciEveniment::operator=(const CaracteristiciEveniment& t)
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

bool CaracteristiciEveniment::operator!()
{
	if (ceasInInt(ora) < 18)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CaracteristiciEveniment::operator==(CaracteristiciEveniment t)
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

ostream& operator<<(ostream& out, CaracteristiciEveniment t)
{
	out << "Data evenimentului este: " << t.data(t.zi, t.luna, t.an)<<endl;
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

istream& operator>>(istream& in, CaracteristiciEveniment& t)
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
	cout << "Introduceti anul evenimentului: ";
	in >> ws;
	getline(in, auxs);
	while (isNumber(auxs) == 0)
	{
		cout << "Formatul anului este gresit. Introduceti doar cifre: ";
		in >> ws;
		getline(in, auxs);
	}
	t.an = stoi(auxs);
	if (t.an < anpc)
	{
		while (t.an < anpc)
		{
			cout << "Ati introdus un an gresit. Va rugam sa introduceti anul corect: ";
			in >> ws;
			getline(in, auxs);
			while (isNumber(auxs) == 0)
			{
				cout << "Formatul anului este gresit. Introduceti doar cifre: ";
				in >> ws;
				getline(in, auxs);
			}
			t.an = stoi(auxs);
		}
	}
	cout << "Introduceti luna evenimentului: ";
	in >> ws;
	getline(in, auxs);
	while (isNumber(auxs) == 0)
	{
		cout << "Formatul lunii este gresit. Introduceti doar cifre: ";
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
				cout << "Ati introdus o luna gresita. Va rugam sa introduceti luna corect: ";
				in >> ws;
				getline(in, auxs);
				while (isNumber(auxs) == 0)
				{
					cout << "Formatul lunii este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, auxs);
				}
				t.luna = stoi(auxs);
			}
		}
	}
	else
	{
		while (t.luna>12)
		{
			cout << "Ati introdus o luna gresita. Va rugam sa introduceti luna corect: ";
			in >> ws;
			getline(in, auxs);
			while (isNumber(auxs) == 0)
			{
				cout << "Formatul lunii este gresit. Introduceti doar cifre: ";
				in >> ws;
				getline(in, auxs);
			}
			t.luna = stoi(auxs);
		}
	}
	cout << "Introduceti ziua evenimentului: ";
	in >> ws;
	getline(in, auxs);
	while (isNumber(auxs) == 0)
	{
		cout << "Formatul zilei este gresit. Introduceti doar cifre: ";
		in >> ws;
		getline(in, auxs);
	}
	t.zi = stoi(auxs);
	if (t.an == anpc && t.luna == lunapc)
	{
		if (t.zi < zipc || t.zi>getNumberOfDays(t.luna, t.an))
		{
			while (t.zi < zipc || t.zi>getNumberOfDays(t.luna, t.an))
			{
				cout << "Ati introdus ziua gresit. Va rugam sa introduceti ziua corect: ";
				in >> ws;
				getline(in, auxs);
				while (isNumber(auxs) == 0)
				{
					cout << "Formatul zilei este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, auxs);
				}
				t.zi = stoi(auxs);
			}
		}
	}
	else
	{
		while (t.zi>getNumberOfDays(t.luna, t.an))
		{
			cout << "Ati introdus ziua gresit. Va rugam sa introduceti ziua corect: ";
			in >> ws;
			getline(in, auxs);
			while (isNumber(auxs) == 0)
			{
				cout << "Formatul zilei este gresit. Introduceti doar cifre: ";
				in >> ws;
				getline(in, auxs);
			}
			t.zi = stoi(auxs);
		}
	}
	cout << "Introduceti ora evenimentului: ";
	in >> ws;
	getline(in, t.ora);
	while (isNumber(t.ora) == 0)
	{
		cout << "Formatul orei este gresit. Introduceti doar cifre: ";
		in >> ws;
		getline(in, t.ora);
	}
	if (anpc == t.an && lunapc == t.luna && zipc == t.zi)
	{
		oraI = t.ceasInInt(t.ora);
		if (oraI < orapc || oraI>=24)
		{
			while (oraI < orapc || oraI>=24)
			{
				cout << "Ati introdus ora gresit. Va rugam sa introduceti ora corect: ";
				in >> ws;
				getline(in, t.ora);
				while (isNumber(t.ora) == 0)
				{
					cout << "Formatul orei este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, t.ora);
				}
				oraI = t.ceasInInt(t.ora);
			}
		}
	}
	else
	{
		oraI = t.ceasInInt(t.ora);
		while (oraI > 23 || oraI<0)
		{
			cout << "Ati introdus ora gresit. Va rugam sa introduceti ora corect: ";
			in >> ws;
			getline(in, t.ora);
			while (isNumber(t.ora) == 0)
			{
				cout << "Formatul orei este gresit. Introduceti doar cifre: ";
				in >> ws;
				getline(in, t.ora);
			}
			oraI = t.ceasInInt(t.ora);
		}
	}
	cout << "Introduceti minutul evenimentului: ";
	in >> ws;
	getline(in, t.minut);
	while (isNumber(t.minut) == 0)
	{
		cout << "Formatul minutului este gresit. Introduceti doar cifre: ";
		in >> ws;
		getline(in, t.minut);
	}
	if (anpc == t.an && lunapc == t.luna && zipc == t.zi && oraI == orapc)
	{
		minutI = t.ceasInInt(t.minut);
		if (minutI < minutpc || minutI>24)
		{
			while (minutI < minutpc || minutI>59)
			{
				cout << "Ati introdus minutul gresit. Va rugam sa introduceti minutul corect: ";
				in >> ws;
				getline(in, t.minut);
				while (isNumber(t.minut) == 0)
				{
					cout << "Formatul minutului este gresit. Introduceti doar cifre: ";
					in >> ws;
					getline(in, t.minut);
				}
				minutI = t.ceasInInt(t.minut);
			}
		}
	}
	else
	{
		minutI = t.ceasInInt(t.minut);
		while (minutI>59)
		{
			cout << "Ati introdus minutul gresit. Va rugam sa introduceti minutul corect: ";
			in >> ws;
			getline(in, t.minut);
			while (isNumber(t.minut) == 0)
			{
				cout << "Formatul minutului este gresit. Introduceti doar cifre: ";
				in >> ws;
				getline(in, t.minut);
			}
			minutI = t.ceasInInt(t.minut);
		}
	}
	string buffer;
	cout << "Introduceti tipul evenimentului: ";
	in >> ws;
	getline(in, buffer);
	t.tip= new char[buffer.length()+1];
	strcpy_s(t.tip, buffer.length() + 1, buffer.c_str());
	cout << "Introduceti denumirea evenimentului: ";
	in >> ws;
	getline(in, t.denumire);
	cout << "Introduceti mentiuni legate de eveniment: " ;
	in >> ws;
	getline(in, t.mentiuni);
	return in;
}