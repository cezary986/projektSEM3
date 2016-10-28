#include <string>       
#include <iostream>     
#include <sstream>//zeby tokenizowac stringi   
#include "Laka.h"
#include "Zwierze.h"
#include "Gatunki.h"

using namespace std;

Laka::Laka(int sk, int sw, int sr, int mn)
{
	k = sk;
	w = sw;
	r = sr;
	monthsNumber = mn;

	Konie = nullptr;
	Osly = nullptr;
	Muly = nullptr;
	Jastrzebie= nullptr;
	Myszolowy = nullptr;
	Myszy = nullptr;
	Zajace = nullptr;

	Muly->breedable = 0;
	Osly->breedable = 1;
	Konie->breedable = 1;
	Jastrzebie->breedable = 1;
	Myszolowy->breedable = 1;
	Myszy->breedable = 1;
	Zajace->breedable = 1;
}

bool Laka::CreatePop(ifstream sfile, string filename)
{
	sfile.open(filename,ios::out);
	stringstream streamLine;
	string line;
	string gatunek,temp;
	vector <int> chrom;
	GENDER gender;

	if (sfile.good())
	{
		while (sfile)
		{
			getline(sfile, line);
			line += " guard";//zeby podczas pobierania ze strumienia ten sie nie skonczyl
			streamLine << line;//dodaje linie do strumienia
//Pobieram gatunek 
			streamLine >> gatunek;
//Pobieram chromosom			
			while (temp != "guard");
			{
				streamLine >>temp;
				chrom.push_back(stoi(temp));
			}
//Losuje plec bo nie podaje sie jej w pliku
			gender = GENDER(rand() % 1);
			Zwierze * animal;
//Sprawdzam gatunek i dodaje do populacji
			if (gatunek == "Osio³")
			{
				animal = new Osiol();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Osly->males.push_back(animal);
				}
				else
				{
					this->Osly->females.push_back(animal);
				}
			}
			if (gatunek == "Koñ")
			{
				animal = new Kon();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Konie->males.push_back(animal);
				}
				else
				{
					this->Konie->females.push_back(animal);
				}
			}
			if (gatunek == "Mu³")
			{
				animal = new Mul();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Muly->males.push_back(animal);
				}
				else
				{
					this->Muly->females.push_back(animal);
				}
			}
			if (gatunek == "Jastrz¹b")
			{
				animal = new Jastrzab();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Jastrzebie->males.push_back(animal);
				}
				else
				{
					this->Jastrzebie->females.push_back(animal);
				}
			}
			if (gatunek == "Myszo³ów")
			{
				animal = new Myszolow();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Myszolowy->males.push_back(animal);
				}
				else
				{
					this->Myszolowy->females.push_back(animal);
				}
			}
			if (gatunek == "Mysz")
			{
				animal = new Mysz();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Myszy->males.push_back(animal);
				}
				else
				{
					this->Myszy->females.push_back(animal);
				}
			}
			if (gatunek == "Zaj¹c")
			{
				animal = new Zajac();
				animal->chromosome = chrom;
				if (gender = MALE)
				{
					this->Zajace->males.push_back(animal);
				}
				else
				{
					this->Zajace->females.push_back(animal);
				}
			}
			
		}
		return 1;
	}
	else
	{
		sfile.close();
		return 0;
	}

}