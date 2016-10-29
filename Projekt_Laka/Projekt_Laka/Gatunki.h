#ifndef GATUNKI_H_INCLUDED
#define GATUNKI_H_INCLUDED

#include "Zwierze.h"

using namespace std;

class Kon : public Zwierze
{
	friend class Osiol;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Osiol : public Zwierze
{
	friend class Kon;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
	//Mul* operator +(const Kon*);
};

class Mul : public Zwierze
{
	friend class Osiol;
	friend class Kon;
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Jastrzab : public Zwierze
{
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Myszolow : public  Zwierze
{
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Zajac : public Zwierze
{
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

class Mysz : public Zwierze
{
	Zwierze* born(vector<int> mamsPart, vector <int> dadsPart);
};

#endif // GATUNKI_H_INCLUDED