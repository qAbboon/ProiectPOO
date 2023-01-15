#pragma once
#include <iostream>
#include "TaxaReducere.h"
using namespace std;

class PretTaxeReduceri :public TaxaReducere
{
private:
	float pret;
	bool existaSchimbare;
public:
	PretTaxeReduceri();
	PretTaxeReduceri(float,bool);
	float pretSchimbat();
	void setPret(float);
	float getPret();
	void setExistaSchimbare(bool);
	bool getExistaSchimbare();
};