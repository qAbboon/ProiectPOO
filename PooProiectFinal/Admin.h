#pragma once
#include <iostream>
#include "AngajatValidare.h"
using namespace std;

class Admin:public AngajatValidare
{
private:
	bool adminDrepturi;
public:
	Admin();
	Admin( bool,string,bool,string,int,string);
	void setAdminDrepturi(bool);
	bool getAdminDrepturi();
	void functie();
	void setareFunctie();
	void afisareUseri();
};