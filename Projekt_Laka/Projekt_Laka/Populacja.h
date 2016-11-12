#ifndef POPULACJA_H_INCLUDED
#define POPULACJA_H_INCLUDED

#include <vector>
#include "Gatunki.h"



class Populacja
{
	friend class Laka;
protected:
	vector <Zwierze*> males;
	vector <Zwierze*> females;

	//Wektory z ktorych bede losowal pary do rozmnazania 
	vector <Zwierze*> malesToBreed;
	vector <Zwierze*> femalesToBreed;

	vector <Pair*> pairs;//vector na wylosowane do rozmnazania sie pary
public:
	bool breedable;
	void breed(int, float);
	void survive(float);
	void randomPairs(int, float);
	//void loadAnimal (vector <int>);
	//void addAnimals(struct Pair*);
};

#endif // POPULACJA_H_INCLUDED
