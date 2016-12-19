#ifndef ZWIERZE_H_INCLUDED
#define ZWIERZE_H_INCLUDED

#include "declarations.h"
#include <vector>
#include <ctime>
#include <iostream>


using namespace std;

//enum na plec zwierzat
enum GENDER {MALE, FEMALE};

class Zwierze
{
protected:
	GENDER sex;
	vector <int> chromosome;
public:
	virtual Zwierze* breed(vector<int> dad, vector<int>mom) = 0;
	bool isFemale();
	bool isMale();
	GENDER getSex();
	virtual ~Zwierze() = 0;
	bool checkSurvival(float w);
	bool checkBreeding(float r);
	vector<int> getChrom();
	friend ostream& operator <<(ostream &output, Zwierze const& ex);
};

//stuktura sluzaca do przechowywania pary zwierzat przeznaczonej do rozmanazania
struct Pair
{
	Zwierze * male;
	Zwierze * female;
};



#endif // ZWIERZE_H_INCLUDED
