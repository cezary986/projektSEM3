#ifndef GATUNKI_H_INCLUDED
#define GATUNKI_H_INCLUDED

#include "Zwierze.h"

using namespace std;

class Kon : public Zwierze
{
	friend class Osiol;
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
	//friend ostream& operator<< (ostream &wyjscie, Kon const& ex);
};

class Osiol : public Zwierze
{
	friend class Kon;
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
	//Mul* operator +(const Kon*);
};

class Mul : public Zwierze
{
	friend class Osiol;
	friend class Kon;
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Jastrzab : public Zwierze
{
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	int howMuchEat = JASTRZAB_FOOD;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Myszolow : public  Zwierze
{
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	int howMuchEat = MYSZOLOW_FOOD;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
	//void eat();
};

class Zajac : public Zwierze
{
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Mysz : public Zwierze
{
public:
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

#endif // GATUNKI_H_INCLUDED