#pragma once
#include <iostream>
#include "User.h"
using namespace std;

class AngajatValidare:public User
{
private:
	string numeAngajat;
	bool angajatDrepturi;
public:
	AngajatValidare();
	AngajatValidare(string,bool,string,int,string);
	void functie();
	void setareFunctie();
	void setAngajatDrepturi(bool);
	void setNumeAngajat(string);
	string getNumeAngajat();
	bool getAngajatDrepturi();
};