#include "Populacja.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

#include <iostream>

Populacja::Populacja(string ID) : spieceID(ID)
{
}

Populacja::~Populacja()
{
	//for (auto i = males.begin(); i != males.end(); ++i)
	//{
	//	delete *i;
	//}

	//for (auto i = femalesToBreed.begin(); i != femalesToBreed.end(); ++i)
	//{
	//	delete *i;
	//}
	//for (auto i = females.begin(); i != females.end(); ++i)
	//{
	//	if (*i != nullptr)
	//	{
	//		delete *i;
	//		*i = nullptr;
	//	}

	

	/*for (auto i = pairs.begin(); i != pairs.end(); ++i)
	{
		delete *i;
	}
*/
	males.clear();
	females.clear();
	malesToBreed.clear();
	femalesToBreed.clear();
	pairs.clear();
	//delete_vector_el(males);
	//delete_vector_el(females);
	//delete_vector_el(malesToBreed);
	//delete_vector_el(femalesToBreed);
	//delete_vector_el(pairs);
}

//Funkcja obslugujaca pojedyncze rozmnazanie w populacji
void Populacja::breed(int k,float r)
{
	this->femalesToBreed.assign(this->females.begin(), this->females.end());
	this->malesToBreed.assign(this->males.begin(), this->males.end());

	//cout << "Tyle samic do rozmanzania: "<< this->femalesToBreed.size() << " \n";
	//cout << "Tyle samcow do rozmanzania: "<< this->malesToBreed.size() << " \n";

	//copy(original.begin(), original.end(), back_inserter(newVec));
	//this->femalesToBreed = this->females;
	//->malesToBreed = this->males;

	this->randomPairs(k,r);

	GENDER gender;

	if (this->breedable = 1)
	{
		if (this->pairs.size() != 0)
		{
			//ROZMNAZANIE
			Zwierze * cub;//wskaznik na nowo narodzone zwierze
			
			//vector <Pair*>::iterator i = this->pairs.begin();
			for (auto i = this->pairs.begin(); i != this->pairs.end(); ++i) //for (auto i : this->pairs)//pelta dla kazdego elementu vectora
			{
				gender = GENDER(rand() % 2);
				cub = (*i)->female->born((*i)->female->chromosome, (*i)->male->chromosome);//tworze nowe zwierze na podstawie chromosomow rodzicow

				if (gender == MALE)
				{
					//#############
					//cout << "Nowe zwierze samiec!\n";
					//#########
					this->males.push_back(cub);
				}
				if (gender == FEMALE)
				{
					//#############
					//cout << "Nowe zwierze samica!\n";
					//#########
					this->females.push_back(cub);
				}
			}
		}
		//NIE MA KOGO ROZMNAZAC
		else
		{//nie ma osobnikow
			this->malesToBreed.clear();
			this->femalesToBreed.clear();
			return;
		}
		//CZYSZCZE WEKTORY
		this->malesToBreed.clear();
		this->femalesToBreed.clear();
		this->pairs.clear();
	}
	else//gatunek nie rozmnaza sie np muly
	{
		return;
	}
}


//Sprawdzenie ktorzy z czlownkow populacji przezyja i ewentualne usuniecie ich
void Populacja::survive(float w)
{	
	//sprawdzam dla samic
	for(int i = 0; i < signed(this->females.size()); i++)
	{
		if (this->females[i]->checkSurvival(w) == false)
		{
			//zwierze zdycha
			delete this->females[i];
			this->females.erase(this->females.begin() + i);
		}
	}
	//sprawdzam dla samcow
	for (int i = 0; i < this->males.size(); i++)
	{
		if (this->males[i]->checkSurvival(w) == false)
		{
			//zwierze zdycha
			delete this->males[i];
			this->males.erase(this->males.begin() + i);
		}
	}
}

//Wylosowanie par do rozmnazania  i dodanie ich do vectora pairs
void Populacja::randomPairs(int k,float r)
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
		while(this->femalesToBreed[index]->checkBreeding(r) == false)
		{
			index = rand() % this->femalesToBreed.size();
		}
		temp->female = this->femalesToBreed[index];
		this->femalesToBreed.erase(this->femalesToBreed.begin() + index);//usuwam z vectora samic do rozmnazania
		//losuje samca
		index = rand() % this->malesToBreed.size();
		while (this->malesToBreed[index]->checkBreeding(r) == false)
		{
			index = rand() % this->malesToBreed.size();
		}
				temp->male = this->malesToBreed[index];
		this->malesToBreed.erase(this->malesToBreed.begin() + index);//usuwam z vectora dostepnych samcow
		this->pairs.push_back(temp);
	}
}

ostream& operator<< (ostream &output, Populacja const& ex)
{
	for (auto i = ex.males.begin(); i != ex.males.end(); ++i)
	{
		output << ex.spieceID<< " ";
		output <<*(*i) << "\n";
	}
	for (auto i = ex.females.begin(); i != ex.females.end(); ++i)
	{
		output << ex.spieceID << " ";
		output << *(*i) <<"\n";
	}
	return output;
}

