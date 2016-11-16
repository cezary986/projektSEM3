#include "Zwierze.h"

#define randmax 10

Zwierze::~Zwierze()
{
	chromosome.clear();
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



