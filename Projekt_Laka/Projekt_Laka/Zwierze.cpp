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

Zwierze * Zwierze::operator +(Zwierze const & ex)
{
	Zwierze * cub = new Zwierze;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}
