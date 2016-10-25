#include "Zwierze.h"

#define randmax 10

bool Zwierze::checkSurvival(int w)
{
	float f = (rand() % randmax)/10;//dzielenie zeby uzyskac liczbe [0,1]
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

bool Zwierze::checkBreeding(int r) 
{
	float f = (rand() % randmax) / 10;//dzielenie zeby uzyskac liczbe [0,1]
	//Cialo funkcji dopadowania przyjmijmy ze to rand()
	if (f < r)
	{
		return 0;//nie rozmnaza sie
	}
	else
	{
		return 1;//rozmanaza sie
	}
}