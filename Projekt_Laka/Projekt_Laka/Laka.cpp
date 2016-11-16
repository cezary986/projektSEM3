#include <string>       
#include <iostream>     
#include <sstream>//zeby tokenizowac stringi   
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
	Muly->breedable = 0;
	Osly->breedable = 1;
	Konie->breedable = 1;
	Jastrzebie->breedable = 1;
	Myszolowy->breedable = 1;
	Myszy->breedable = 1;
	Zajace->breedable = 1;
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
	GENDER gender;

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
			gender = GENDER(rand() % 2);
			//Sprawdzam gatunek i dodaje do populacji
			if (gatunek == "Osiol")
			{
				animal = new Osiol();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Osly->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Osly->females.push_back(animal);
				}
			}
			if (gatunek == "Kon")
			{
				animal = new Kon();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Konie->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Konie->females.push_back(animal);
				}
			}
			if (gatunek == "Mul")
			{
				animal = new Mul();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Muly->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Muly->females.push_back(animal);
				}
			}
			if (gatunek == "Jastrzab")
			{
				animal = new Jastrzab();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Jastrzebie->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Jastrzebie->females.push_back(animal);
				}
			}
			if (gatunek == "Myszolow")
			{
				animal = new Myszolow();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Myszolowy->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Myszolowy->females.push_back(animal);
				}
			}
			if (gatunek == "Mysz")
			{
				animal = new Mysz();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Myszy->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Myszy->females.push_back(animal);
				}
			}
			if (gatunek == "Zajac")
			{
				animal = new Zajac();
				animal->chromosome = chrom;
				if (gender == MALE)
				{
					this->Zajace->males.push_back(animal);
				}
				if (gender == FEMALE)
				{
					this->Zajace->females.push_back(animal);
				}
			}
			line.empty();
			ssLine.flush();
			ssLine.clear();
			chrom.clear();
		}
		//#############
		cout << "STAN LAKI:\n";
		cout << "Konie - " << this->Konie->males.size() + this->Konie->females.size() << endl;
		cout << "Osly - " << this->Osly->males.size() + this->Osly->females.size() << endl;
		cout << "Muly - " << this->Muly->males.size() + this->Muly->females.size() << endl;
		cout << "Jastrzebie - " << this->Jastrzebie->males.size() + this->Jastrzebie->females.size() << endl;
		cout << "Myszolowy - " << this->Myszolowy->males.size() + this->Myszolowy->females.size() << endl;
		cout << "Myszy - " << this->Myszy->males.size() + this->Myszy->females.size() << endl;
		cout << "Zajace - " << this->Zajace->males.size() + this->Zajace->females.size() << endl;
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
		this->feed(this->Myszolowy,this->Myszy, MYSZOLOW_FOOD);
		this->feed(this->Jastrzebie, this->Zajace, JASTRZAB_FOOD);
//Krzyzowanie sie
		this->crossBreed(this->Konie, this->Osly, MUL);
	}
	//#############
	cout << "STAN LAKI:\n";
	cout << "Konie - " << this->Konie->males.size() + this->Konie->females.size() << endl;
	cout << "Osly - " << this->Osly->males.size() + this->Osly->females.size() << endl;
	cout << "Muly - " << this->Muly->males.size() + this->Muly->females.size() << endl;
	cout << "Jastrzebie - " << this->Jastrzebie->males.size() + this->Jastrzebie->females.size() << endl;
	cout << "Myszolowy - " << this->Myszolowy->males.size() + this->Myszolowy->females.size() << endl;
	cout << "Myszy - " << this->Myszy->males.size() + this->Myszy->females.size() << endl;
	cout << "Zajace - " << this->Zajace->males.size() + this->Zajace->females.size() << endl;
	//#########
}

void Laka::feed(Populacja * whosEating, Populacja *whosEaten, int how_many)
{
	int indexFemales =0;
	int indexMales =0;
	GENDER genderOfEaten;
	int indexOfEaten;

	if ((whosEating->females.size() == 0 && whosEating->males.size() == 0))
	{
	//Nie ma kto jesc koncze
		return;
	}
	if((whosEaten->females.size() == 0 && whosEaten->males.size() ==0) ||
	  (whosEaten->females.size() + whosEaten->males.size() < how_many))
	{
	//Nie ma co jesc wszyscy gina
		whosEating->females.clear();
		whosEating->males.clear();
		return;
	}
//Dla kazdej samicy i samce (naprzemian)
		while (indexFemales <= whosEating->females.size() || indexMales <= whosEating->males.size())
		{
	//Tyle razy ile ma byc zjedzonych zwierzat
			for (int i = 0; i < how_many; i++)
			{	
				//sprawdzam czy nie zabraklo jedzenia
				if (whosEaten->females.size() == 0 && whosEaten->males.size() == 0)
				{
					//Nie ma co jesc wszyscy gina
					whosEating->females.clear();
					whosEating->males.clear();
					return;
				}
				//losuje plec
				genderOfEaten = GENDER(rand() % 2);

				if (whosEaten->males.size() == 0)
				{
					genderOfEaten = FEMALE;
				}
				if (whosEaten->females.size() != 0)
				{
					genderOfEaten = MALE;
				}
				if (whosEaten->males.size() == 0)
				{
					if (genderOfEaten == MALE)
					{	//losuje samca do zjedzenia
						indexOfEaten = rand() % whosEaten->males.size();
						//usuwam zjedzonego
						 delete whosEaten->males[indexOfEaten];
						whosEaten->males.erase(whosEaten->males.begin() + indexOfEaten);
					}
				}
				if (whosEaten->females.size() != 0)
				{
					if (genderOfEaten == FEMALE)
					{	//losuje samice do zjedzenia
						indexOfEaten = rand() % whosEaten->females.size();
						//usuwam zjedzonego
						delete whosEaten->females[indexOfEaten];
						whosEaten->females.erase(whosEaten->females.begin() + indexOfEaten);
					}
				}
			}
				indexFemales++;
				indexMales++;
		}
}

void Laka::crossBreed(Populacja *first, Populacja* second, ANIMALS childType)
{
	first->femalesToBreed = first->females;
	first->malesToBreed = first->males;
	second->femalesToBreed = second->females;
	second->malesToBreed = second->males;
	
	first->randomPairs(this->k, this->r);
	second->randomPairs(this->k, this->r);

	Zwierze * male;
	Zwierze * female;

	vector <Zwierze*> temp;

	switch (int(childType))
	{
	case int(MUL) :
		if (first->malesToBreed.size() < second->femalesToBreed.size())
		{
			for (int i = 0; i < first->malesToBreed.size(); i++)//dla kazdego samca z pierwszego gatunku
			{
				/*Jest szansa ze samcow jednego gatunku bedzie mniej niz samic drugiego i vice versa stad femalesToBreed[i] moze wyjsc poza zakres
				*/
				if (i >= second->femalesToBreed.size())
				{
					break;
				}
				female = second->femalesToBreed[i];//dobieram samice z drugiego
				male = first->males[i];
				Zwierze * cub = new Mul();
				cub = cub->born(female->chromosome, male->chromosome);
				cub->sex = GENDER(rand() % 2);
				if (cub->sex == MALE)
				{
					this->Muly->males.push_back(cub);
				}
				else
				{
					this->Muly->females.push_back(cub);
				}
			}
		}
		else
		{

			for (int i = 0; i < second->malesToBreed.size(); i++)//dla kazdego samca z pierwszego gatunku
			{
				if (i >= first->femalesToBreed.size())
				{
					break;
				}
				female = first->femalesToBreed[i];//dobieram samice z drugiego
				male = second->males[i];
				Zwierze * cub = new Mul();
				cub = cub->born(female->chromosome, male->chromosome);
				cub->sex = GENDER(rand() % 2);
				if (cub->sex == MALE)
				{
					this->Muly->males.push_back(cub);
				}
				else
				{
					this->Muly->females.push_back(cub);
				}
			}
		}

		break;
	}
	first->malesToBreed.clear();
	first->femalesToBreed.clear();
	second->malesToBreed.clear();
	second->femalesToBreed.clear();
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