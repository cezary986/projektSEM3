#ifndef ZWIERZE_H_INCLUDED
#define ZWIERZE_H_INCLUDED

#include "declarations.h"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

//enum na plec zwierzat
enum GENDER { MALE, FEMALE };

class Zwierze
{
protected:
	vector <int> chromosome;
	int chromSize = size(chromosome);//zeby nie wywolywac za czesto
	int breedFreq;//czestotliwosc rozmnazania sie w miesiacach
	float momsPart;//ile chromosomu bierze od matki
	float dadsPart;
	GENDER sex;
public:
	bool checkSurvival(int w);
	bool checkBreeding(int r);
	Zwierze* operator + (Zwierze const&);
};

//stuktura sluzaca do przechowywania pary zwierzat przeznaczonej do rozmanazania
struct Pair
{
	Zwierze * male;
	Zwierze * female;
};

class Kon: protected Zwierze
{
	//Kon();
};
class Osiol: protected Zwierze
{
	//Osiol();
};
class Mul: protected Zwierze
{
	//Mul();
};
class Jastrzab: protected Zwierze
{
	//Jastrzab();
}; class Myszolow: protected Zwierze
{
	//Myszolow();
};
class Zajac: protected Zwierze
{
	//Zajac();
};


#endif // ZWIERZE_H_INCLUDED
