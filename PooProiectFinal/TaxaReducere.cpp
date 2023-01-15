#include <iostream>
using namespace std;
#include "TaxaReducere.h"

TaxaReducere::TaxaReducere()
{
	tip = 0;
	valoare = 0;
}

bool TaxaReducere::getTip()
{
	return tip;
}
float TaxaReducere::getValoare()
{
	return valoare;
}

void TaxaReducere::setTip(bool tip)
{
	this->tip = tip;
}
void TaxaReducere::setValoare(float valoare)
{
	this->valoare = valoare;
}