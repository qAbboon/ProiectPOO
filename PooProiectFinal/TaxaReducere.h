#pragma once
#include <iostream>
using namespace std;

class TaxaReducere
{
private:
	bool tip;
	float valoare;
public:
	TaxaReducere();
	virtual float pretSchimbat() = 0;
	bool getTip();
	float getValoare();
	void setTip(bool);
	void setValoare(float);
};