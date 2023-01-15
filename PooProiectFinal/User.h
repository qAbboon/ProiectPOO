#pragma once
#include <iostream>
using namespace std;

class User
{
private:
	string usernick;
	string parola;
	int idFunctie;
protected:
public:
	User();
	User(string, int,string);
	string getUsernick();
	string getParola();
	int getIdFunctie();
	void setUsernick(string);
	void setParola(string);
	void setIdFunctie(int);
	virtual void functie();
	virtual void setareFunctie();
	User operator=(const User&);
	friend ostream& operator<<(ostream&, User);
};
ostream& operator<<(ostream&, User);