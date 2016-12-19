#include "Populacja.h"

Populacja::Populacja(string ID) : spieceID(ID) {}

Populacja::~Populacja()
{
	for (auto i = males.begin(); i != males.end(); i++)
	{
		delete *i;
	}
	for (auto i = females.begin(); i != females.end(); i++)
	{
		delete *i;
	}
	for (auto i = pairs.begin(); i != pairs.end(); i++)
	{
		delete *i;
	}

	males.clear();
	females.clear();
	pairs.clear();
	malesToBreed.clear();
	femalesToBreed.clear();
}

void Populacja::clearPairs()
{
	for (auto i = this->pairs.begin(); i != this->pairs.end(); i++)
	{
		delete *i;
	}
	this->pairs.clear();
}

//Funkcja obslugujaca pojedyncze rozmnazanie w populacji
void Populacja::breed(int k,float r)
{
	if (this->sizeOfPopulation() == 0)
	{
		return;
	}
	if (this->breedable = true)
	{
		this->femalesToBreed = this->females;
		this->malesToBreed = this->males;

		this->randomPairs(k, r);

		GENDER gender;
		if (this->pairs.size() != 0)
		{
			//ROZMNAZANEI
			Zwierze * cub;//wskaznik na nowo narodzone zwierze
			
			for (auto i = this->pairs.begin(); i != this->pairs.end(); ++i) //pelta dla kazdego elementu vectora
			{
			
					cub = (*i)->female->breed((*i)->male->getChrom(), (*i)->female->getChrom());//tworze nowe zwierze na podstawie chromosomow rodzicow
					if (cub->isMale())
					{
						this->males.push_back(cub);
					}
					if (cub->isFemale())
					{
						this->females.push_back(cub);
					}
			}
		}
	}
	else//gatunek nie rozmnaza sie np muly
	{
		return;
	}
	this->clearPairs();
}


//Sprawdzenie ktorzy z czlownkow populacji przezyja i ewentualne usuniecie ich
void Populacja::survive(float w)
{	
	if (this->sizeOfPopulation() == 0)
	{
		return;
	}
	//sprawdzam dla samic
	for(int i = 0; i < this->females.size(); i++)
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

void Populacja::addMale(Zwierze* a)
{
	this->males.push_back(a);
}

void Populacja::addFemale(Zwierze* a)
{
	this->females.push_back(a);
}

int Populacja::sizeOfPopulation()
{
	return this->females.size() + this->males.size();
}

vector<Zwierze*> Populacja::getMalesVec()
{
	return (this->males);
}

vector<Zwierze*> Populacja::getFemalesVec()
{
	return (this->females);
}
void Populacja::setMalesToBreedVec(vector<Zwierze*> a)
{
	this->malesToBreed = a;
}
void Populacja::setFemalesToBreedVec(vector<Zwierze*> a)
{
	this->femalesToBreed = a;
}

int  Populacja::sizeOfMalesToBreedVec()
{
	return this->malesToBreed.size();
}

int  Populacja::sizeOfFemalesToBreedVec()
{
	return this->femalesToBreed.size();
}

vector<Zwierze*> Populacja::getMalesToBreedVec()
{
	return (this->malesToBreed);
}

vector<Zwierze*> Populacja::getFemalesToBreedVec()
{
	return (this->femalesToBreed);
}

void Populacja::clearMalesToBreed()
{
	this->malesToBreed.clear();
}

void Populacja::clearFemalesToBreed()
{
	this->femalesToBreed.clear();

}


int Populacja::sizeOfFemalesVec()
{
	return this->females.size();
}

int Populacja::sizeOfMalesVec()
{
	return this->males.size();
}

void Populacja::slayPopulation()//usuwa wszystkich przedstawicieli populacji bez usuwania calego obiektu
{
	cout << "Populacja: " << this->spieceID << " wyginala";
	for (auto i = males.begin(); i != males.end(); i++)
	{
		delete *i;
	}
	for (auto i = females.begin(); i != females.end(); i++)
	{
		delete *i;
	}
	for (auto i = pairs.begin(); i != pairs.end(); i++)
	{
		delete *i;
	}

	males.clear();
	females.clear();
	pairs.clear();
	malesToBreed.clear();
	femalesToBreed.clear();
}


void Populacja::SetBreedable(bool a) 
{
	this->breedable = a;
}

void Populacja::eraseAnimal(GENDER gender, int index)
{
	if (gender == MALE)
	{
		delete this->males[index];
		this->males.erase(this->males.begin() + index);
	}
	if (gender == FEMALE)
	{
		delete this->females[index];
		this->females.erase(this->females.begin() + index);
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

