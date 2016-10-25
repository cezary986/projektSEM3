#ifndef ZWIERZE_H_INCLUDED
#define ZWIERZE_H_INCLUDED

#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Zwierze
{
protected:
	vector <int> chromosom;
	int chromSize = size(chromosom);//zeby nie wywolywac za czesto
	int breedFreq;//czestotliwosc rozmnazania sie w miesiacach
	float momsPart;//ile chromosomu bierze od matki

	bool checkSurvival(int w);
	bool checkBreeding(int r);
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
