#ifndef GATUNKI_H_INCLUDED
#define GATUNKI_H_INCLUDED

#include "Zwierze.h"

using namespace std;

class Kon : public Zwierze
{
	friend class Osiol;
public:
	Kon *breed(vector<int> dad, vector<int>mom);
	Kon(vector<int> chrom);
	Kon(vector<int> dad, vector<int> mom);
	~Kon();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	//friend ostream& operator<< (ostream &wyjscie, Kon const& ex);
};

class Osiol : public Zwierze
{
	friend class Kon;
public:
	Osiol* breed(vector<int> dad, vector<int>mom);
	Osiol(vector<int> chrom);
	Osiol(vector<int> dad, vector<int> mom);
	~Osiol();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	//Mul* operator +(const Kon*);
};

class Mul : public Zwierze
{
	friend class Osiol;
	friend class Kon;
public:
	Mul* breed(vector<int> dad, vector<int>mom);
	Mul(vector<int> chrom);
	Mul(vector<int> dad, vector<int> mom);
	~Mul();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
};

class Jastrzab : public Zwierze
{
public:
	Jastrzab* breed(vector<int> dad, vector<int>mom);
	Jastrzab(vector<int> chrom);
	Jastrzab(vector<int> dad, vector<int> mom);
	~Jastrzab();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	int howMuchEat = JASTRZAB_FOOD;
};

class Myszolow : public  Zwierze
{
public:
	Myszolow* breed(vector<int> dad, vector<int>mom);
	Myszolow(vector<int> chrom);
	Myszolow(vector<int> dad, vector<int> mom);
	~Myszolow();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
	int howMuchEat = MYSZOLOW_FOOD;
	//void eat();
};

class Zajac : public Zwierze
{
public:
	Zajac* breed(vector<int> dad, vector<int>mom);
	Zajac(vector<int> chrom);
	Zajac(vector<int> dad, vector<int> mom);
	~Zajac();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;};

class Mysz : public Zwierze
{
public:
	Mysz* breed(vector<int> dad, vector<int>mom);
	Mysz(vector<int> chrom);
	Mysz(vector<int> dad, vector<int> mom);
	~Mysz();
	static double momsPart;//ile chromosomu bierze od matki
	static double dadsPart;
};

#endif // GATUNKI_H_INCLUDED