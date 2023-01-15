#pragma once
#include <iostream>
#include "PretTaxeReduceri.h" 
using namespace std;

PretTaxeReduceri::PretTaxeReduceri()
{
	pret = 0;
	existaSchimbare = 0;
}

PretTaxeReduceri::PretTaxeReduceri(float pret,bool existaSchimbare)
{
	this->pret = pret;
	this->existaSchimbare = existaSchimbare;
}

float PretTaxeReduceri::pretSchimbat()
{
	float copie = pret;
	if (existaSchimbare != 0)
	{
		if (getTip() == 0)
		{
			copie = pret + getValoare();
		}
		else
		{
			copie = pret - getValoare();
		}
	}
	return copie;
}

void PretTaxeReduceri::setExistaSchimbare(bool existaSchimbare)
{
	this->existaSchimbare = existaSchimbare;
}

bool PretTaxeReduceri::getExistaSchimbare()
{
	return existaSchimbare;
}

void PretTaxeReduceri::setPret(float pret)
{
	this->pret = pret;
}

float PretTaxeReduceri::getPret()
{
	return pret;
}