#include "Populacja.h"
#include "declarations.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

void Populacja::breed(vector <Pair*> pairs, int k)
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
//LOSOWANIE K PAR NA NASTEPNE ROZMNAZANIE
	int index;
	for (int i = 0; i < k; i++)
	{
		//index = rand()% this->
	}
	//this->pairs.clear();  usuwa caly wektor niszczy wszystkie obiektyr!!!
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

void Populacja::randomPairs(int k)
{
	int index;
		for (int i = 0; i < k; i++)
		{	//brakuje samic badz samcow
			if (this->femalesToBreed.size() == 0 || this->malesToBreed.size() == 0)
			{
				return;
			}
			struct Pair * pair = new Pair();
			//losowanie samicy
			index = rand() % this->femalesToBreed.size();
			pair->female = this->femalesToBreed[index];
			//losowanie samca
			index = rand() % this->malesToBreed.size();
			pair->male = this->malesToBreed[index];
			//zapisanie wylosowanych par
			this->pairs.push_back(pair);
		}
}