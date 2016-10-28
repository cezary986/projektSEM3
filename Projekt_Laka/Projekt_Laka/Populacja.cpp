#include "Populacja.h"
#include "declarations.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;


//G
void Populacja::breed(vector <Pair*> pairs, int k)
{
	if (this->femalesToBreed.size() != 0 && this->malesToBreed.size() != 0)
	{
//ROZMNAZANIE
		Zwierze * cub;//wskaznik na nowo narodzone zwierze
		for (auto i : this->pairs)//pelta dla kazdego elementu vectora
		{
			cub = (*i->female) + (*i->male);//tworze nowe zwierze na podstawie chromosomow rodzicow
			if (cub->sex == MALE)
			{
				this->males.push_back(cub);
			}
			else
			{
				this->females.push_back(cub);
			}
		}
	}
//NIE MA KOGO ROZMNAZAC
	else
	{//LOSUJE
		this->randomPairs(k);
		this->breed(this->pairs, k);//jeszcze raz wywoluje funkcje tym razem ma juz na czym pracowac
	}
//LOSOWANIE K PAR NA NASTEPNE ROZMNAZANIE
		//Stworzenie vectorow maleToBreed i femalesToBreed i przeniesienie tam zwierzat
		//Wektory z ktorych bede losowal pary do rozmnazania 
	this->randomPairs(k);
//CZYSZCZE WEKTORY
	this->malesToBreed.clear();
	this->femalesToBreed.clear();
}


//G
void Populacja::survive(int w)
{	
	//sprawdzam dla samic
	for(int i = 0; i < this->females.size(); i++)
	{
		if (this->females[i]->checkSurvival == 0)
		{
			//zwierze zdycha
			delete this->females[i];
			this->females.erase(this->females.begin() + i);
		}
	}
	//sprawdzam dla samcow
	for (int i = 0; i < this->males.size(); i++)
	{
		if (this->males[i]->checkSurvival == 0)
		{
			//zwierze zdycha
			delete this->males[i];
			this->males.erase(this->males.begin() + i);
		}
	}
}

//G
void Populacja::randomPairs(int k)
{
	int index;
	for (int i = 0; i < k; i++)
	{
		//Zabraklo samcow lub samic do losowania
		if (this->femalesToBreed.size() == 0 || this->malesToBreed.size() == 0)
		{
			return;//koncze losowanie
		}
		Pair * temp = new Pair;
		index = rand() % this->femalesToBreed.size();
		//losje i sprawdzam zdolnosc do rozmanzania sie
		while(this->femalesToBreed[index]->checkBreeding != 0)
		{
			index = rand() % this->femalesToBreed.size();
		}
		this->femalesToBreed.erase(this->femalesToBreed.begin() + index);//usuwam z vectora samic do rozmnazania
		temp->female = this->femalesToBreed[index];
		//losuje samca
		index = rand() % this->malesToBreed.size();
		while (this->malesToBreed[index]->checkBreeding != 0)
		{
			index = rand() % this->malesToBreed.size();
		}
		this->femalesToBreed.erase(this->femalesToBreed.begin() + index);//usuwam z vectora dostepnych samcow
		temp->male = this->malesToBreed[index];
		this->pairs.push_back(temp);
	}
}


void Populacja::loadAnimal (vector <int> chromosome)
{
	
}