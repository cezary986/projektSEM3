#include "Laka.h"


using namespace std;

Laka::Laka(int sk, float sw, float sr, int mn)
{
	k = sk;
	w = sw;
	r = sr;
	monthsNumber = mn;

	Konie = new Populacja("Kon");
	Osly = new Populacja("Osiol");
	Muly = new Populacja("Mul");
	Jastrzebie= new Populacja("Jastrzab");
	Myszolowy = new Populacja("Myszolow");
	Myszy = new Populacja("Mysz");
	Zajace = new Populacja("Zajac");

	//1 - moze sie rozmnazac, 0 - nie moze
	Muly->SetBreedable(false);
	Osly->SetBreedable(true);
	Konie->SetBreedable(true);
	Jastrzebie->SetBreedable(true);
	Myszolowy->SetBreedable(true);
	Myszy->SetBreedable(true);
	Zajace->SetBreedable(true);
}

Laka::~Laka()
{
	delete Konie;
	delete Osly;
	delete Muly;
	delete Jastrzebie;
	delete Myszolowy;
	delete Myszy;
	delete Zajace;
	Konie = Osly = Muly = Jastrzebie = Myszolowy = Myszy = Zajace = nullptr;
}


//metoda wcztujaca populacje z pliku ( wszyskie populacje)
bool Laka::CreatePop(ifstream &sfile, string filename)
{
	sfile.open(filename, ios::out);
	stringstream ssLine;
	string line;
	string gatunek;
	string temp;
	vector <int> chrom;

	if (sfile.good())
	{
		while (getline(sfile, line))
		{
			ssLine.str(line);
			ssLine >> gatunek;
			while (ssLine >> temp)
			{
				chrom.push_back(stoi(temp));
			}

			Zwierze * animal;

			//Losuje plec bo nie podaje sie jej w pliku
			//Sprawdzam gatunek i dodaje do populacji
			if (gatunek == "Osiol")
			{
				animal = new Osiol(chrom);
				if (animal->isMale())
				{
					this->Osly->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Osly->addFemale(animal);
				}
			}
			if (gatunek == "Kon")
			{
				animal = new Kon(chrom);
				if (animal->isMale())
				{
					this->Konie->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Konie->addFemale(animal);
				}
			}
			if (gatunek == "Mul")
			{
				animal = new Mul(chrom);
				if (animal->isMale())
				{
					this->Muly->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Muly->addFemale(animal);
				}
			}
			if (gatunek == "Jastrzab")
			{
				animal = new Jastrzab(chrom);
				if (animal->isMale())
				{
					this->Jastrzebie->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Jastrzebie->addFemale(animal);
				}
			}
			if (gatunek == "Myszolow")
			{
				animal = new Myszolow(chrom);
				if (animal->isMale())
				{
					this->Myszolowy->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Myszolowy->addFemale(animal);
				}
			}
			if (gatunek == "Mysz")
			{
				animal = new Mysz(chrom);
				if (animal->isMale())
				{
					this->Myszy->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Myszy->addFemale(animal);
				}
			}
			if (gatunek == "Zajac")
			{
				animal = new Zajac(chrom);
				if (animal->isMale())
				{
					this->Zajace->addMale(animal);
				}
				if (animal->isFemale())
				{
					this->Zajace->addFemale(animal);
				}
			}
			line.empty();
			ssLine.flush();
			ssLine.clear();
			chrom.clear();
		}
		//#############
		cout << "STAN LAKI:\n";
		cout << "Konie - " << this->Konie->sizeOfPopulation() << endl;
		cout << "Osly - " << this->Osly->sizeOfPopulation() << endl;
		cout << "Muly - " << this->Muly->sizeOfPopulation() << endl;
		cout << "Jastrzebie - " << this->Jastrzebie->sizeOfPopulation() << endl;
		cout << "Myszolowy - " << this->Myszolowy->sizeOfPopulation() << endl;
		cout << "Myszy - " << this->Myszy->sizeOfPopulation() << endl;
		cout << "Zajace - " << this->Zajace->sizeOfPopulation() << endl;
		//#########
		return 1;
	}
	else
	{
		sfile.close();
		return 0;
	}

}


//Glowna metoda symulujaca caly rozwoj populacji na lace
void Laka::Symyluj()
{	
	//dla wybranej liczby miesiecy
	for (int mounth = 0; mounth < this->monthsNumber; mounth++)
	{
		if (mounth % KONIE_F == 0)
		{
			this->Konie->breed(this->k, this->r);
		}
		if (mounth % OSLY_F == 0)
		{
			this->Osly->breed(this->k, this->r);
		}
		if (mounth % MULY_F == 0)
		{
			this->Muly->breed(this->k, this->r);
		}
		if (mounth % JASTRZEBIE_F == 0)
		{
			this->Jastrzebie->breed(this->k, this->r);
		}
		if (mounth % MYSZOLOWY_F == 0)
		{
			this->Myszolowy->breed(this->k,this->r);
		}
		if (mounth % MYSZY_F == 0)
		{
			this->Myszy->breed(this->k, this->r);
		}
		if (mounth % ZAJACE_F == 0)
		{
			this->Zajace->breed(this->k, this->r);
		}
//Sprawdzenie przezycia
		this->Konie->survive(this->w);
		this->Osly->survive(this->w);
		this->Muly->survive(this->w);
		this->Jastrzebie->survive(this->w);
		this->Myszolowy->survive(this->w);
		this->Myszy->survive(this->w);
		this->Zajace->survive(this->w);
//Pozywianie sie
		//cout << *this;
		this->feed(this->Myszolowy,this->Myszy, MYSZOLOW_FOOD);
		this->feed(this->Jastrzebie, this->Zajace, JASTRZAB_FOOD);
//Krzyzowanie sie
		this->crossBreed(this->Konie, this->Osly, MUL);
	}
	//#############
	cout << "STAN LAKI:\n";
	cout << "Konie - " << this->Konie->sizeOfPopulation() << endl;
	cout << "Osly - " << this->Osly->sizeOfPopulation() << endl;
	cout << "Muly - " << this->Muly->sizeOfPopulation() << endl;
	cout << "Jastrzebie - " << this->Jastrzebie->sizeOfPopulation() << endl;
	cout << "Myszolowy - " << this->Myszolowy->sizeOfPopulation() << endl;
	cout << "Myszy - " << this->Myszy->sizeOfPopulation() << endl;
	cout << "Zajace - " << this->Zajace->sizeOfPopulation() << endl;
	//#########
}

void Laka::feed(Populacja * whosEating, Populacja *whosEaten, int how_many)
{
	int indexFemales = 0;
	int indexMales = 0;
	GENDER genderOfEaten;
	int indexOfEaten;

	if ((whosEating->sizeOfFemalesVec() == 0 && whosEating->sizeOfMalesVec() == 0))
	{
		//Nie ma kto jesc koncze
		return;
	}
	if ((whosEaten->sizeOfFemalesVec() == 0 && whosEaten->sizeOfMalesVec() == 0) ||
		(whosEaten->sizeOfFemalesVec() + whosEaten->sizeOfMalesVec() < how_many))
	{
		//Nie ma co jesc wszyscy gina
		whosEaten->slayPopulation();
		whosEating->slayPopulation();
		return;
	} {
		int indexFemales = 0;
		int indexMales = 0;
		GENDER genderOfEaten;
		int indexOfEaten;

		if (whosEating->sizeOfPopulation() == 0)
		{
			//Nie ma kto jesc koncze
			return;
		}
		if (whosEaten->sizeOfPopulation() < how_many)
		{
			//Nie ma co jesc wszyscy gina
			whosEaten->slayPopulation();
			whosEating->slayPopulation();
			return;
		}
		//Dla kazdej samicy i samce (naprzemian)
		while (indexFemales + indexMales <= whosEating->sizeOfPopulation())
		{
			//Tyle razy ile ma byc zjedzonych zwierzat
			for (int i = 0; i < how_many; i++)
			{
				//sprawdzam czy nie zabraklo jedzenia
				if (whosEaten->sizeOfFemalesVec() == 0 && whosEaten->sizeOfMalesVec() == 0)
				{
					//Nie ma co jesc wszyscy gina
					whosEaten->slayPopulation();
					whosEating->slayPopulation();
					return;
				}
				//losuje plec
				genderOfEaten = GENDER(rand() % 2);

				if (whosEaten->sizeOfMalesVec() == 0)
				{
					genderOfEaten = FEMALE;
				}
				if (whosEaten->sizeOfFemalesVec() == 0)
				{
					genderOfEaten = MALE;
				}
				if (whosEaten->sizeOfMalesVec() != 0)
				{
					if (genderOfEaten == MALE)
					{	//losuje samca do zjedzenia
						indexOfEaten = rand() % whosEaten->sizeOfMalesVec();
						//usuwam zjedzonego
						//delete whosEaten->getMalesVec()[whosEaten->sizeOfMalesVec()];
						//whosEaten->getMalesVec().pop_back();
						whosEaten->eraseAnimal(genderOfEaten, indexOfEaten);
					}
				}
				if (whosEaten->sizeOfFemalesVec() != 0)
				{
					if (genderOfEaten == FEMALE)
					{	//losuje samice do zjedzenia
						indexOfEaten = rand() % whosEaten->sizeOfFemalesVec();
						//usuwam zjedzonego
						//delete whosEaten->getFemalesVec()[whosEaten->sizeOfFemalesVec()];
						//whosEaten->getFemalesVec().pop_back();
						whosEaten->eraseAnimal(genderOfEaten, indexOfEaten);
					}
				}
			}
			indexFemales++;
			indexMales++;
		}
	}
}


/*void Laka::feed(Populacja * whosEating, Populacja *whosEaten, int how_many)
{
	int indexOfFem = 0;
	int indexOfMale = 0;
	GENDER genderOfEaten;
	GENDER genderOfEating;
	int indexOfEaten;

	if (whosEating->sizeOfPopulation() == 0)
	{
//Nie ma kto jesc koncze
		return;
	}
	if (whosEaten->sizeOfPopulation() < how_many)
	{
//Nie ma co jesc wszyscy gina
		whosEaten->slayPopulation();
		whosEating->slayPopulation();
		return;
	}
//Dla kazdego z drapiznikow
	while ((whosEating->sizeOfFemalesVec() + whosEating->sizeOfMalesVec())  <= whosEating->sizeOfPopulation())
	{
		//Tyle razy ile ma byc zjedzonych zwierzat
		for (int i = 0; i < how_many; i++)
		{
//Sprawdzamy czy nie zabraklo pozywania
			if (whosEaten->sizeOfMalesVec() > 0 && whosEaten->sizeOfFemalesVec() > 0)
			{
				whosEaten->slayPopulation();
				whosEating->slayPopulation();
				return;
			}
//Losuje plec tego kto ma byc zjedzony
			genderOfEaten = GENDER(rand() % 2);
//Jesli nie ma samcow zjadane sa samice
			if (whosEaten->getMalesVec().size() == 0)
			{
				genderOfEaten = FEMALE;
			}
//Jesli nie ma samic znajadane sa samce
			if (whosEaten->getFemalesVec().size() == 0)
			{
				genderOfEaten = MALE;
			}
//Losuje plec drapieznika
			genderOfEating = GENDER(rand() % 2);
//Jesli nie ma samcow drapieznik to samica
			if (whosEating->getMalesVec().size() == 0 || indexOfMale >= whosEating->sizeOfMalesVec())
			{
				genderOfEating = FEMALE;
			}
//Jesli nie ma samic drapieznik jest samcem
			if (whosEating->getFemalesVec().size() == 0 || indexOfFem >= whosEating->sizeOfFemalesVec())
			{
				genderOfEating = MALE;
			}
			if (genderOfEating == MALE)
			{
				indexOfMale++;
			}
			if (genderOfEating == FEMALE)
			{
				indexOfFem++;
			}
//Zjedzony jest samcem usuwam go z populacji
			if (genderOfEaten == MALE)
			{
				delete 	&(whosEaten->getMalesVec().end());
				whosEaten->getMalesVec().pop_back();
			}
//Zjedzony jest samica usuwam go z populacji
			if (genderOfEaten == MALE)
			{
				delete 	&(whosEaten->getFemalesVec().end());
				whosEaten->getFemalesVec().pop_back();
			}
		}
		whosEating++;
	}
}
*/

void Laka::crossBreed(Populacja *first, Populacja* second, ANIMALS childType)
{
	first->setFemalesToBreedVec(first->getFemalesVec());
	first->setMalesToBreedVec(first->getMalesVec());
	second->setFemalesToBreedVec(second->getFemalesVec());
	second->setMalesToBreedVec(second->getMalesVec());
	
	first->randomPairs(this->k, this->r);
	second->randomPairs(this->k, this->r);

	Zwierze * male;
	Zwierze * female;

	vector <Zwierze*> temp;

	switch (int(childType))
	{
	case int(MUL) :
		if (first->sizeOfMalesToBreedVec() < second->sizeOfFemalesToBreedVec())
		{
			for (int i = 0; i < first->sizeOfMalesToBreedVec(); i++)//dla kazdego samca z pierwszego gatunku
			{
				/*Jest szansa ze samcow jednego gatunku bedzie mniej niz samic drugiego i vice versa stad femalesToBreed[i] moze wyjsc poza zakres
				*/
				if (i >= second->sizeOfFemalesToBreedVec())
				{
					break;
				}
				female = (second->getFemalesToBreedVec())[i];//dobieram samice z drugiego
				male = (first->getMalesToBreedVec())[i];
				Zwierze * cub = new Mul(male->chromosome, female->chromosome);
				if (cub->isMale())
				{
					this->Muly->addMale(cub);
				}
				if(cub->isFemale())
				{
					this->Muly->addFemale(cub);
				}
			}
		}
		else
		{
			for (int i = 0; i < (second->sizeOfMalesToBreedVec()); i++)//dla kazdego samca z pierwszego gatunku
			{
				if (i >= first->sizeOfFemalesToBreedVec())
				{
					break;
				}
				female = first->getFemalesToBreedVec()[i];//dobieram samice z drugiego
				male = second->getMalesToBreedVec()[i];
				Zwierze * cub = new Mul(male->chromosome, female->chromosome);
				if (cub->isMale())
				{
					this->Muly->addMale(cub);
				}
				if (cub->isFemale())
				{
					this->Muly->addFemale(cub);
				}
			}
		}
		break;
	}
	first->clearMalesToBreed();
	first->clearFemalesToBreed();
	second->clearMalesToBreed();
	second->clearFemalesToBreed();
}


ostream& operator<< (ostream &output, Laka const& laka)
{	
	output << *laka.Konie;
	output << *laka.Osly;
	output << *laka.Muly;
	output << *laka.Jastrzebie;
	output << *laka.Myszolowy;
	output << *laka.Myszy;
	output << *laka.Zajace;


	//output << "LAKA\n";
	return output;
}