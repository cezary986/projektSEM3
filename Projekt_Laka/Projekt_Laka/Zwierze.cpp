#include "Zwierze.h"

#define randmax 10
//TODO getter do plci dla zwierze

//TODO konstruktor zwierze powinien przyjmowac sam chromosomy i je robic
//TODO metoda IsFemale() isMale()
Zwierze::~Zwierze()
{
	//chromosome.clear();
}


bool Zwierze::checkSurvival(float w)
{
	float f = float(rand() % randmax)/10;//dzielenie zeby uzyskac liczbe [0,1]
	//Cialo funkcji dopadowania przyjmijmy ze to rand()
	if (f < w)
	{
		return 0;//ginie
	}
	else
	{
		return 1;//przezywa
	}
}

bool Zwierze::checkBreeding(float r) 
{
	float f = float(rand() % randmax) / 10;//dzielenie zeby uzyskac liczbe [0,1]
	//Cialo funkcji dopadowania przyjmijmy ze to rand()
	if (f > r)
	{
		return false;//nie rozmnaza sie
	}
	else
	{
		return true;//rozmanaza sie
	}
}

ostream& operator<< (ostream & output, Zwierze const& ex)
{
	for (auto i = ex.chromosome.begin(); i != ex.chromosome.end(); ++i)
	{
		output << *i << " ";
	}
	return output;
}

bool Zwierze::isFemale()
{
	if (this->sex == FEMALE)
		return true;
	else
		return false;
}
bool Zwierze::isMale()
{
	if (this->sex == MALE)
		return true;
	else
		return false;

}
GENDER Zwierze::getSex()
{
	return this->sex;
}

