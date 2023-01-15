#pragma once
#include <iostream>
#include "AngajatValidare.h"
using namespace std;

AngajatValidare::AngajatValidare()
{
	numeAngajat = "";
	angajatDrepturi = false;
}

AngajatValidare::AngajatValidare(string numeAngajat,bool angajatDrepturi,string userNick,int idFunctie,string parola):User(userNick,idFunctie,parola)
{
	this->numeAngajat = numeAngajat;
	this->angajatDrepturi = angajatDrepturi;
}

void AngajatValidare::functie()
{
	if(angajatDrepturi ==false)
	{ 
		cout << "Sunt in faza de angajat, insa nu puteti modifica nimic." << endl;
	}
	if (angajatDrepturi == true)
	{
		cout << "Sunteti in faza de angajat.Nu puteti folosi aplicatia, decat pentru a valida bilete." << endl;
	}
}

void AngajatValidare::setareFunctie()
{
	setIdFunctie(1);
	angajatDrepturi = true;
}

void AngajatValidare::setNumeAngajat(string numeAngajat)
{
	this->numeAngajat = numeAngajat;
}

void AngajatValidare::setAngajatDrepturi(bool angajatDrepturi)
{
	this->angajatDrepturi = angajatDrepturi;
}

string AngajatValidare::getNumeAngajat()
{
	return numeAngajat;
}
bool AngajatValidare::getAngajatDrepturi()
{
	return angajatDrepturi;
}