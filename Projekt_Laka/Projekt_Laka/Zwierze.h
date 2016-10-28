#ifndef ZWIERZE_H_INCLUDED
#define ZWIERZE_H_INCLUDED

#include "declarations.h"
#include <vector>
#include <ctime>
#include <cstdlib>

//enum na plec zwierzat
enum GENDER {MALE, FEMALE};

class Zwierze
{
	friend class Populacja;
protected:
	int chromSize = size(chromosome);//zeby nie wywolywac za czesto
	int breedFreq;//czestotliwosc rozmnazania sie w miesiacach
	float momsPart;//ile chromosomu bierze od matki
	float dadsPart;
	GENDER sex;
public:
	vector <int> chromosome;
	bool checkSurvival(int w);
	bool checkBreeding(int r);
	Zwierze* operator + (Zwierze const&);//NIEEEEEEE!! musi byc wirtualny
};

//stuktura sluzaca do przechowywania pary zwierzat przeznaczonej do rozmanazania
struct Pair
{
	Zwierze * male;
	Zwierze * female;
};



#endif // ZWIERZE_H_INCLUDED
