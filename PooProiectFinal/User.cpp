#pragma once
#include <iostream>
#include "User.h"
using namespace std;

User::User()
{
	usernick = "";
	idFunctie = 0;
	parola = "";
}

User::User(string usernick, int idFunctie,string parola)
{
	this->usernick = usernick;
	this->idFunctie = idFunctie;
	this->parola = parola;
}

void User::setUsernick(string usernick)
{
	this->usernick = usernick;
}

void User::setParola(string parola)
{
	this->parola = parola;
}

void User::setIdFunctie(int x)
{
	idFunctie = x;
}

void User::functie()
{
	cout << "Sunteti in faza de utilizator."<<endl;
}

void User::setareFunctie()
{
	idFunctie = 0;
}

string User::getUsernick()
{
	return usernick;
}
string User::getParola()
{
	return parola;
}
int User::getIdFunctie()
{
	return idFunctie;
}

User User::operator=(const User& t)
{
	if (this != &t)
	{
		usernick = t.usernick;
		idFunctie = t.idFunctie;
		parola = t.parola;
	}
	return *this;
}

ostream& operator<<(ostream& out, User t)
{
	out << "Nickname: " << t.usernick<<endl;
	out << "Parola: " << t.parola<<endl;
	out << "ID functie: " << t.idFunctie << endl;
	return out;
}