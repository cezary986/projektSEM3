#ifndef POPULACJA_H_INCLUDED
#define POPULACJA_H_INCLUDED

#include "declarations.h"
#include "Zwierze.h"
#include <vector>

class Populacja
{
protected:
	vector <Zwierze*> males;
	vector <Zwierze*> females;

	//Wektory z ktorych bede losowal pary do rozmnazania 
	vector <Zwierze*> malesToBreed;
	vector <Zwierze*> femalesToBreed;

	vector <Pair*> pairs;//vector na wylosowane do rozmnazania sie pary
public:
	void breed(vector <Pair*>);
	void survive(int);
	void randomPairs(int);
};

#endif // POPULACJA_H_INCLUDED
