#include <iostream>
#include <string>
#include "TestareBiletFULL.h"
#include "CaracteristiciEveniment.h"
#include "CaracteristiciLocatie.h"
#include "Zone.h"
#include "Bilet.h"
#include "TaxaReducere.h"
#include "PretTaxeReduceri.h"
#include "User.h"
#include "AngajatValidare.h"
#include "Admin.h"
#include <stdlib.h>
#include <time.h> 
#include <fstream>
#include <vector>
using namespace std;

bool isNumber3(const string& s)
{
	for (char const& ch : s)
	{
		if (std::isdigit(ch) == 0)
			return false;
	}
	return true;
}

int convertireInNumar(string auxConvertireInNumar)
{
	while (isNumber3(auxConvertireInNumar) == 0)
	{
		cout << "Valoarea introdusa nu este corespunzatoare, va rugam reintroduceti o valoare corecta: ";
		cin >> ws;
		getline(cin, auxConvertireInNumar);
	}
	int numarul = stoi(auxConvertireInNumar);
	return numarul;
}

void apelLocatie(CaracteristiciLocatie& locatie)
{
	cin >> locatie;
}

void apelEveniment(CaracteristiciEveniment& eveniment)
{
	cin >> eveniment;
}

int main()
{	
	int indx = 0;
	string auxs;
	AngajatValidare* angajati = nullptr;
	AngajatValidare angAux;
	Admin* admini = nullptr;
	Admin admAux;
	int numarAngajati = 0; int numarAdmini = 0;
	int swBD = 0;
	int contorValidare = 0;
	int reusita = 0;
	string username; string parola;
	cout << "Log in" << endl;
	cout << "Alegeti metoda de logare: " << endl;
	cout << "1)Angajat" << endl;
	cout << "2)Admin" << endl;
	cin >> ws;
	getline(cin, auxs);
	swBD = convertireInNumar(auxs);
	while (swBD != 1 && swBD != 2)
	{
		cout << "Ati introdus optiunea gresit. Va rugam sa reintroduceti." << endl;
		cout << "1)Angajat" << endl;
		cout << "2)Admin" << endl;
		cin >> ws;
		getline(cin, auxs);
		swBD = convertireInNumar(auxs);
	}
	if (swBD == 1)
	{
		ifstream f;
		f.open("angajati.txt");
		int citireInt; string citireString1; bool citireBool; string citireString2; string citireString3;
		while (!f.eof())
		{
			f >> ws;
			getline(f, citireString1);
			f >> citireInt;
			f >> ws;
			getline(f, citireString2);
			f >> ws;
			getline(f, citireString3);
			f >> citireBool;
			numarAngajati++;
		}
		f.close();
		numarAngajati = numarAngajati;
		angajati = new AngajatValidare[numarAngajati];
		f.open("angajati.txt");
		for (int i = 0; i < numarAngajati; i++)
		{
			f >> ws;
			getline(f, citireString1);
			f >> citireInt;
			f >> ws;
			getline(f, citireString2);
			f >> ws;
			getline(f, citireString3);
			f >> citireBool;
			angajati[i].setUsernick(citireString1);
			angajati[i].setParola(citireString2);
			angajati[i].setIdFunctie(citireInt);
			angajati[i].setNumeAngajat(citireString3);
			angajati[i].setAngajatDrepturi(citireBool);
		}
		f.close();
		contorValidare = 0;
		int index;
		while (contorValidare < 5 && reusita == 0)
		{
			cout << "Introduceti username-ul: ";
			cin >> ws;
			getline(cin, username);
			for (int i = 0; i < numarAngajati; i++)
			{
				const char* charUser = username.c_str();
				string angS = angajati[i].getUsernick();
				const char* charNick = angS.c_str();
				if (strcmp(charUser, charNick) == 0)
				{
					reusita = 1;
					index = i;
					indx = index;
				}
			}
			if (reusita == 0)
			{
				cout << "Mai aveti " << 5 - contorValidare - 1 << " incercari ramase." << endl;
			}
			contorValidare++;
		}
		if (contorValidare < 5 && reusita != 0)
		{
			angajati[index].functie();
		}
	}
	if (swBD == 2)
	{
		ifstream f;
		f.open("admini.txt");
		int citireInt; string citireString1; bool citireBool1; string citireString2; string citireString3; bool citireBool2;
		while (!f.eof())
		{
			f >> ws;
			getline(f, citireString1);
			f >> citireInt;
			f >> ws;
			getline(f, citireString2);
			f >> ws;
			getline(f, citireString3);
			f >> citireBool1;
			f >> citireBool2;
			numarAdmini++;
		}
		f.close();
		numarAdmini = numarAdmini;
		admini = new Admin[numarAdmini];
		f.open("admini.txt");
		for (int i = 0; i < numarAdmini; i++)
		{
			f >> ws;
			getline(f, citireString1);
			f >> citireInt;
			f >> ws;
			getline(f, citireString2);
			f >> ws;
			getline(f, citireString3);
			f >> citireBool1;
			f >> citireBool2;
			admini[i].setUsernick(citireString1);
			admini[i].setParola(citireString2);
			admini[i].setIdFunctie(citireInt);
			admini[i].setNumeAngajat(citireString3);
			admini[i].setAngajatDrepturi(citireBool1);
			admini[i].setAdminDrepturi(citireBool2);
		}
		f.close();
		contorValidare = 0;
		while (contorValidare < 5 && reusita < 2)
		{
			reusita = 0;
			int index = 0;
			cout << "Introduceti username-ul: ";
			cin >> ws;
			getline(cin, username);
			for (int i = 0; i < numarAdmini; i++)
			{
				const char* charUser = username.c_str();
				string angS = admini[i].getUsernick();
				const char* charNick = angS.c_str();
				if (strcmp(charUser, charNick) == 0)
				{
					reusita = 1;
					index = i;
					indx = i;
				}
			}
			int contorValidare2 = 0;
			if (reusita == 1)
			{
				while (contorValidare2 < 4 && reusita != 2)
				{
					cout << "Introduceti parola: ";
					cin >> ws;
					getline(cin, parola);
					const char* charPas = parola.c_str();
					string admS = admini[index].getParola();
					const char* charNickA = admS.c_str();
					if (strcmp(charPas, charNickA) == 0)
					{
						reusita = 2;
					}
					else
					{
						contorValidare2++;
					}
				}
			}
			if (reusita != 2)
			{
				cout << "Username-ul sau parola au fost introduse gresit. Va rugam sa reincercati. Mai aveti " << 5 - contorValidare - 1 << " incercari." << endl;
				contorValidare++;
			}
		}
		if (reusita == 2 && contorValidare < 5)
		{
			int index;
			for (int i = 0; i < numarAdmini; i++)
			{
				const char* charUser = username.c_str();
				string adminiS = admini[i].getUsernick();
				const char* charNick = adminiS.c_str();
				if (strcmp(charNick, charUser) == 0)
				{
					index = i;
					indx = i;
				}
			}
			admini[index].functie();
			int swBD2 = 0;
			cout << "Doriti sa adaugati angajati/admini noi?\nPentru angajati tastati 1.\nPentru admini tastati 2.\nDaca doriti sa mergeti mai departe apasati orice alt numar.\nDaca doriti sa afisati lista cu angajatii tastati 3.";
			cin >> ws;
			getline(cin, auxs);
			swBD2 = convertireInNumar(auxs);
			string userUU;
			int functieFF;
			string parolaPP = "N / A";
			string numeSS;
			bool idII1 = 1;
			bool idII2 = 1;
			if (swBD2 == 1)
			{
				int nrAng;
				cout << "Introduceti numarul de angajati pe care doriti sa il adaugati: ";
				cin >> ws;
				getline(cin, auxs);
				nrAng = convertireInNumar(auxs);
				fstream f;
				f.open("angajati.txt", ios::app);
				for (int i = 0; i < nrAng; i++)
				{
					functieFF = 1;
					cout << "User: ";
					cin >> ws;
					getline(cin, userUU);
					cout << "Nume: ";
					cin >> ws;
					getline(cin, numeSS);
					cout << "Pentru drepturi de angajat tastati orice cifra, pentru a dezactiva drepturile tastati 0." << endl;
					cout << "Drepturi: ";
					cin >> ws;
					getline(cin, auxs);
					idII1 = convertireInNumar(auxs);
					f << userUU << endl;
					f << functieFF << endl;
					f << parolaPP << endl;
					f << numeSS << endl;
					f << idII1 << endl;
				}
			}
			if (swBD2 == 2)
			{
				int nrAdm;
				cout << "Introduceti numarul de admini pe care doriti sa il adaugati: ";
				cin >> ws;
				getline(cin, auxs);
				nrAdm = convertireInNumar(auxs);
				fstream f;
				f.open("admini.txt", ios::app);
				for (int i = 0; i < nrAdm; i++)
				{
					functieFF = 2;
					cout << "User: ";
					cin >> ws;
					getline(cin, userUU);
					cout << "Nume: ";
					cin >> ws;
					getline(cin, numeSS);
					cout << "Parola: ";
					cin >> ws;
					getline(cin, parolaPP);
					cout << "Pentru drepturi de angajat tastati orice cifra, pentru a dezactiva drepturile tastati 0." << endl;
					cout << "Drepturi: ";
					cin >> ws;
					getline(cin, auxs);
					idII1 = convertireInNumar(auxs);
					cout << "Pentru drepturi de user tastati orice cifra, pentru a dezactiva drepturile tastati 0." << endl;
					cout << "Drepturi: ";
					cin >> ws;
					getline(cin, auxs);
					idII1 = convertireInNumar(auxs);
					f << userUU << endl;
					f << functieFF << endl;
					f << parolaPP << endl;
					f << numeSS << endl;
					f << idII1 << endl;
					f << idII2 << endl;
				}
			}
			if (swBD2 == 3)
			{
				Admin c;
				c.afisareUseri();
			}
			
		}
		else
		{
			reusita = 0;
		}
	}
	int drepturi = 0;
	if (reusita == 1)
	{
		if (angajati[indx].getAngajatDrepturi() == true)
		{
			drepturi = 1;
		}
	}
	if (reusita == 2)
	{
		if (admini[indx].getAdminDrepturi() == true)
		{
			drepturi = 2;
		}
		else
		{
			if (admini[indx].getAngajatDrepturi() == true)
			{
				drepturi = 1;
			}
		}
	}
	if (drepturi > 0 && reusita >= 1)
	{
		srand(time(0));
		int timpInit = (rand() % 100) * 1000000 + (rand() % 100) * 10000 + (rand() % 100) * 100 + (rand() % 100);
		int alegereConsola = 0;
		string alegereConsolaStr;
		cout << endl << "Alegeti modalitatea de utilizare. " << endl;
		cout << "1) Meniu in consola" << endl;
		cout << "2) Fisier txt" << endl;
		cin >> ws;
		getline(cin, alegereConsolaStr);
		alegereConsola = convertireInNumar(alegereConsolaStr);
		if(alegereConsola!=1 && alegereConsola!=2)
		{
			cout << endl << "Optiunea nu a fost aleasa corect. Va rugam reincercati.";
			cout << endl << "Alegeti modalitatea de utilizare. " << endl;
			cout << "1) Meniu in consola" << endl;
			cout << "2) Fisier txt" << endl;
			cin >> ws;
			getline(cin, alegereConsolaStr);
			alegereConsola = convertireInNumar(alegereConsolaStr);
		}
		if (alegereConsola == 1)
		{
			Bilet* bilR = nullptr;
			vector<int> vCuIduri;
			int nrBileteFis = 0;
			cout << "Meniu" << endl;
			int x = 99;
			int sw = 0;
			string auxmen;
			float* pret = nullptr;
			Bilet* bil = nullptr;
			CaracteristiciLocatie locatie;
			CaracteristiciEveniment eveniment;
			bil->setCtid2(timpInit);
			TestareBiletFULL* bilete = nullptr;
			if (drepturi > 0)
			{
				int contorLocatie = 0;
				int contorEveniment = 0;
				while (x != 0)
				{
					cout << "\nAlegeti o optiune prin tastarea cifrei corespunzatoare." << endl;
					if (drepturi > 0)
					{
						cout << "1) Validare bilet. " << endl;
						cout << "2) Citire din fisier. " << endl;
						if (drepturi > 1 && reusita == 2)
						{
							cout << "3) Introducere caracteristici eveniment. " << endl;
							cout << "4) Generare bilete." << endl;
							cout << "5) Introducere caracteristici locatie." << endl;
						}
						cin >> ws;
						getline(cin, auxmen);
						sw = convertireInNumar(auxmen);
						if (drepturi > 1 && reusita == 2)
						{
							if (sw == 5)
							{
								contorLocatie++;
								apelLocatie(locatie);
							}
							if (sw == 3)
							{
								contorEveniment++;
								apelEveniment(eveniment);
							}
							pret = new float[locatie.getNrZone()];
							if (sw == 4)
							{
								if (contorEveniment == 0)
								{
									cout <<endl<< "Nu ati introdus date despre eveniment. Va rugam sa le introduceti." << endl;
									apelEveniment(eveniment);
								}
								if (contorLocatie == 0)
								{
									cout << endl << "Nu ati introdus date despre locatie. Va rugam sa le introduceti." << endl;
									apelLocatie(locatie);
								}

								string auxs;
								int auxi;
								bil = new Bilet[locatie.getMaxLocuri()];
								bil->setCtid2(timpInit);
								bil->setAdresa(locatie.getAdresa());
								for (int i = 0; i < locatie.getNrZone(); i++)
								{
									cout << "Pretul pentru zona " << locatie.getZoind(i).getDenumireZona() << " este: ";
									cin >> ws;
									getline(cin, auxs);
									pret[i] = convertireInNumar(auxs);
									cout << "Exista taxe sau reduceri pentru acest pret?\nTastati 1 pentru taxe.\nTastati 2 pentru reduceri.\nDaca nu tastati orice alta tasta." << endl;
									cin >> ws;
									getline(cin, auxs);
									auxi = convertireInNumar(auxs);
									if (auxi == 1 || auxi == 2)
									{
										int auxii = 0;
										if (auxi == 1)
										{
											cout << "Introduceti valoare taxei: ";
											cin >> ws;
											getline(cin, auxs);
											auxii = convertireInNumar(auxs);
										}
										if (auxi == 2)
										{
											cout << "Introduceti valoare reducerii: ";
											cin >> ws;
											getline(cin, auxs);
											auxii = convertireInNumar(auxs);
										}
										PretTaxeReduceri auxPret(pret[i], 1);
										auxPret.setValoare(auxii);
										auxPret.setTip(auxi - 1);
										pret[i] = auxPret.pretSchimbat();
										if (pret[i] < 0)
										{
											pret[i] = 0;
										}
									}

								}
								int bilAux = 0;
								for (int i = 0; i < locatie.getNrZone(); i++)
								{
									for (int j = 0; j < locatie.getZoind(i).getNrRanduri(); j++)
									{
										for (int q = 0; q < locatie.getZoind(i).getNrScaunePeRand(j); q++)
										{
											Bilet biletAux(0, eveniment.getDenumire(), eveniment.getTip(), locatie.locFinal(i, j + 1, q + 1), pret[i], eveniment.data(eveniment.getZi(), eveniment.getLuna(), eveniment.getAn()), eveniment.oraStr(eveniment.getOra(), eveniment.getMinut()), eveniment.getMentiuni());
											bil[bilAux++] = biletAux;
										}
									}
								}
								//for (int i = 0; i < locatie.getMaxLocuri(); i++)
								//{
								//	cout << bil[i] << endl;
								//}
								string numeFisSv;
								cout << "Numele fisierului in care bilete vor fi salvate este: ";
								cin >> numeFisSv;
								ofstream f(numeFisSv, ios::out | ios::binary);
								for (int i = 0; i < locatie.getMaxLocuri(); i++)
								{
									int auxX = bil[i].getId();
									int length;
									
									float auxX2 = bil[i].getPret();
									string auxS;

									f.write((char*)&auxX,sizeof(auxX));
									f.write((char*)&auxX2, sizeof(bil[i].getPret()));


									auxS = bil[i].getAdresa();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);

									auxS = bil[i].getDenumireEveniment();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);
									
									auxS = bil[i].getTipStr();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);
									
									auxS = bil[i].getLocBilet();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);
									
									auxS = bil[i].getData();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);
									
									auxS = bil[i].getOra();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);
									
									auxS = bil[i].getMentiuni();
									length = auxS.length();
									f.write((char*)&length, sizeof(length));
									f.write(auxS.c_str(), length + 1);
									
								}
								f.close();
								contorLocatie = 0;
								contorEveniment = 0;
							}
						}
						if (sw == 1)
						{
							if (bil != nullptr)
							{
								int idValidare;
								string auxs;
								cout << "Introduceti ID-ul biletului: ";
								cin >> ws;
								getline(cin, auxs);
								idValidare = convertireInNumar(auxs);
								bool valid=0;
								for (int i = 0; i < locatie.getTotalLocuri(); i++)
								{
									if (idValidare == bil[i].getId())
									{
										valid = true;
									}
									else
									{
										valid = false;
									}
								}
								if (valid == true)
								{
									cout << endl << "Biletul este valid." << endl;
								}
								else
								{
									cout << endl << "Biletul este invalid." << endl;
								}
							}
							else
							{
								if (bilR != nullptr)
								{
									int idValidare;
									string auxs;
									bool valid = 0;
									//for (int i = 0; i < vCuIduri.size(); i++)
									//{
									//	cout << vCuIduri[i] << endl;
									//}
									cout << "Introduceti ID-ul biletului: ";
									cin >> ws;
									getline(cin, auxs);
									idValidare = convertireInNumar(auxs);
									for (int i = 0; i <vCuIduri.size(); i++)
									{
										if (idValidare == vCuIduri[i])
										{
											valid = true;
										}
										else
										{
											valid = false;
										}
									}
									if (valid == true)
									{
										cout << endl << "Biletul este valid." << endl;
									}
									else
									{
										cout << endl << "Biletul este invalid." << endl;
									}
								}
								else
								{
									cout << "Nu exista bilete disponibile." << endl;
								}
							}
						}
						if (sw == 2)
						{
							int contor = vCuIduri.size();
							for (int i = 0; i < contor; i++)
							{
								vCuIduri.pop_back();
							}
							for (int i = 0; i < vCuIduri.size(); i++)
							{
								cout << vCuIduri[i] << endl;
							}
							nrBileteFis = 0;
							string creareFis;
							int creareFisInt = 9;
								string numeFis;
								int ki = 9;
								cout << "Introduceti numele fisierului: ";
								cin >> numeFis;
								ifstream g(numeFis, ios::in | ios::binary);
								if (g)
								{
									ki = 0;
								}
								while (ki != 0)
								{
									cout << "Fisierul nu exista. Introduceti din nou: ";
									cin >> numeFis;
									g.open(numeFis);
									if (g)
									{
										ki = 0;
									}
								}
								while (!g.eof())
								{
									nrBileteFis++;
									int x;
									float y;
									string a, b, c, d, e, f, h;
									string zona;
									int rand;
									int loc;
									g.read((char*)&x, sizeof(x));
									g.read((char*)&y, sizeof(y));
									int length1 = 0;
									g.read((char*)&length1, sizeof(length1));
									char* sir1 = new char[length1 + 1];
									g.read(sir1, length1 + 1);
									a = sir1;
									int length2 = 0;
									g.read((char*)&length2, sizeof(length2));
									char* sir2 = new char[length2 + 1];
									g.read(sir2, length2 + 1);
									b = sir2;
									int length3 = 0;
									g.read((char*)&length3, sizeof(length3));
									char* sir3 = new char[length3 + 1];
									g.read(sir3, length3 + 1);
									c = sir3;
									int length4 = 0;
									g.read((char*)&length4, sizeof(length4));
									char* sir4 = new char[length4 + 1];
									g.read(sir4, length4 + 1);
									d = sir4;
									int length5 = 0;
									g.read((char*)&length5, sizeof(length5));
									char* sir5 = new char[length5 + 1];
									g.read(sir5, length5 + 1);
									e = sir5;
									int length6 = 0;
									g.read((char*)&length6, sizeof(length6));
									char* sir6 = new char[length6 + 1];
									g.read(sir6, length6 + 1);
									f = sir6;
									int length7 = 0;
									g.read((char*)&length7, sizeof(length7));
									char* sir7 = new char[length7 + 1];
									g.read(sir7, length7 + 1);
									h = sir7;
								}
								g.close();
								bilR = new Bilet[nrBileteFis - 1];
								CaracteristiciLocatie locatie;
								CaracteristiciEveniment eveniment;
								ifstream pr(numeFis, ios::in | ios::binary);
								for (int q = 0; q < nrBileteFis - 1; q++)
								{

									int x;
									float y;
									string a, b, c, d, e, f, h;
									string zona;
									int rand;
									int loc;
									pr.read((char*)&x, sizeof(x));
									pr.read((char*)&y, sizeof(y));
									int length1 = 0;
									pr.read((char*)&length1, sizeof(length1));
									char* sir1 = new char[length1 + 1];
									pr.read(sir1, length1 + 1);
									a = sir1;
									int length2 = 0;
									pr.read((char*)&length2, sizeof(length2));
									char* sir2 = new char[length2 + 1];
									pr.read(sir2, length2 + 1);
									b = sir2;
									int length3 = 0;
									pr.read((char*)&length3, sizeof(length3));
									char* sir3 = new char[length3 + 1];
									pr.read(sir3, length3 + 1);
									c = sir3;
									int length4 = 0;
									pr.read((char*)&length4, sizeof(length4));
									char* sir4 = new char[length4 + 1];
									pr.read(sir4, length4 + 1);
									d = sir4;
									string randCuv = " ";
									int iR = 0; int iR2 = 0;
									while (randCuv != "Randul:")
									{
										char lit1, lit2, lit3, lit4, lit5, lit6, lit7;
										lit1 = d.at(iR); lit2 = d.at(iR + 1); lit3 = d.at(iR + 2); lit4 = d.at(iR + 3); lit5 = d.at(iR + 4);
										lit6 = d.at(iR + 5); lit7 = d.at(iR + 6);
										string al(1, lit1), bl(1, lit2), cl(1, lit3), dl(1, lit4), el(1, lit5), fl(1, lit6), gl(1, lit7);
										randCuv = al + bl + cl + dl + el + fl + gl;
										iR++;
									}
									char* zonaAux = new char[iR - 7];
									zonaAux[iR - 8] = '\0';
									for (int i = 6; i < iR - 2; i++)
									{
										zonaAux[i - 6] = d.at(i);
									}
									while (randCuv != "Locul:")
									{
										char lit1, lit2, lit3, lit4, lit5, lit6;
										lit1 = d.at(iR2); lit2 = d.at(iR2 + 1); lit3 = d.at(iR2 + 2); lit4 = d.at(iR2 + 3); lit5 = d.at(iR2 + 4);
										lit6 = d.at(iR2 + 5);
										string al(1, lit1), bl(1, lit2), cl(1, lit3), dl(1, lit4), el(1, lit5), fl(1, lit6);
										randCuv = al + bl + cl + dl + el + fl;
										iR2++;
									}
									char* randAux = new char[(iR2 - 3) - (iR + 6) + 1];
									randAux[(iR2 - 3) - (iR + 6)] = '\0';
									for (int i = iR + 7; i < iR2 - 2; i++)
									{
										randAux[i - iR - 7] = d.at(i);
									}
									char* locAux = new char[d.length() - (iR2 + 5)];
									locAux[d.length() - (iR2 + 5) - 1] = '\0';
									for (int i = iR2 + 6; i < d.length(); i++)
									{
										locAux[i - iR2 - 6] = d.at(i);
									}
									int length5 = 0;
									pr.read((char*)&length5, sizeof(length5));
									char* sir5 = new char[length5 + 1];
									pr.read(sir5, length5 + 1);
									e = sir5;
									int length6 = 0;
									pr.read((char*)&length6, sizeof(length6));
									char* sir6 = new char[length6 + 1];
									pr.read(sir6, length6 + 1);
									f = sir6;
									int length7 = 0;
									pr.read((char*)&length7, sizeof(length7));
									char* sir7 = new char[length7 + 1];
									pr.read(sir7, length7 + 1);
									h = sir7;
									zona = zonaAux;
									rand = convertireInNumar(randAux);
									loc = convertireInNumar(locAux);
									vCuIduri.push_back(x);
									bilR[q].setAdresa(a);
									Bilet auxB(x, b, sir2, d, y, e, f, h);
									bilR[q] = auxB;
								}
								pr.close();
						}
						cout << "Daca doriti sa iesiti din meniu apasati 0." << endl;
						cin >> ws;
						getline(cin, auxmen);
						x = convertireInNumar(auxmen);
					}
				}
			}
		}
		if (alegereConsola == 2)
		{

		}
	}
}
