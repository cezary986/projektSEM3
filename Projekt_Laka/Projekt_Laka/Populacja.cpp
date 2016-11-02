#include "Populacja.h"
#include "declarations.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>

//using namespace std;


//Funkcja obslugujaca pojedyncze rozmnazanie w populacji
void Populacja::breed(vector <Pair*> pairs,int k,float r)
{
	this->femalesToBreed = this->females;
	this->malesToBreed = this->males;

	this->randomPairs(k,r);

	if (this->breedable = 1)
	{
		if (this->pairs.size() != 0)
		{
			//ROZMNAZANIE
			Zwierze * cub;//wskaznik na nowo narodzone zwierze
			for (auto i : this->pairs)//pelta dla kazdego elementu vectora
			{
				cub = i->female->born(i->female->chromosome,i->male->chromosome);//tworze nowe zwierze na podstawie chromosomow rodzicow
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
		{//nie ma osobnikow
			return;
		}
		//CZYSZCZE WEKTORY
		this->malesToBreed.clear();
		this->femalesToBreed.clear();	
	}
	else//gatunek nie rozmnaza sie np muly
	{
		return;
	}
}


//Sprawdzenie ktorzy z czlownkow populacji przezyja i ewentualne usuniecie ich
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

//Wylosowanie par do rozmnazania  i dodanie ich do vectora pairs
void Populacja::randomPairs(int k,int r)
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
		while(this->femalesToBreed[index]->checkBreeding > r)
		{
			index = rand() % this->femalesToBreed.size();
		}
		this->femalesToBreed.erase(this->femalesToBreed.begin() + index);//usuwam z vectora samic do rozmnazania
		temp->female = this->femalesToBreed[index];
		//losuje samca
		index = rand() % this->malesToBreed.size();
		while (this->malesToBreed[index]->checkBreeding > r)
		{
			index = rand() % this->malesToBreed.size();
		}
		this->femalesToBreed.erase(this->femalesToBreed.begin() + index);//usuwam z vectora dostepnych samcow
		temp->male = this->malesToBreed[index];
		this->pairs.push_back(temp);
	}
}



