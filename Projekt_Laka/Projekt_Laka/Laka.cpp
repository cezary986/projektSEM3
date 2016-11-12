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

	Konie = new Populacja();
	Osly = new Populacja();
	Muly = new Populacja();
	Jastrzebie= new Populacja();
	Myszolowy = new Populacja();
	Myszy = new Populacja();
	Zajace = new Populacja();

	//1 - moze sie rozmnazac, 0 - nie moze
	Muly->breedable = 1;
	Osly->breedable = 1;
	Konie->breedable = 1;
	Jastrzebie->breedable = 1;
	Myszolowy->breedable = 1;
	Myszy->breedable = 1;
	Zajace->breedable = 1;
}

//metoda wcztujaca populacje z pliku ( wszyskie populacje)
bool Laka::CreatePop(ifstream &sfile, string filename)
{
	sfile.open(filename,ios::out);
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
			ssLine << line;
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
				else
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
				else
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
				else
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
				else
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
				else
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
				else
				{
					this->Zajace->females.push_back(animal);
				}
			}
			line.clear();
			ssLine.clear();
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
		cout << "MIESIAC " << mounth << endl;

		if (mounth % KONIE_F == 0)
		{
			//#############
			cout << "ROZMNAZAM KONIE:\n";
			//#########
			this->Konie->breed(this->k, this->r);
		}
		if (mounth % OSLY_F == 0)
		{
			//#############
			cout << "ROZMNAZAM OSLY:\n";
			//#########
			this->Osly->breed(this->k, this->r);
		}
		if (mounth % MULY_F == 0)
		{
			//#############
			cout << "ROZMNAZAM MULY:\n";
			//#########
			this->Muly->breed(this->k, this->r);
		}
		if (mounth % JASTRZEBIE_F == 0)
		{
			//#############
			cout << "ROZMNAZAM JASTRZEBIE:\n";
			//#########
			this->Jastrzebie->breed(this->k, this->r);
		}
		if (mounth % MYSZOLOWY_F == 0)
		{
			//#############
			cout << "ROZMNAZAM MYSZOLOWY:\n";
			//#########
			this->Myszolowy->breed(this->k,this->r);
		}
		if (mounth % MYSZY_F == 0)
		{
			//#############
			cout << "ROZMNAZAM MYSZY:\n";
			//#########
			this->Myszy->breed(this->k, this->r);
		}
		if (mounth % ZAJACE_F == 0)
		{
			//#############
			cout << "ROZMNAZAM ZAJACE:\n";
			//#########
			this->Zajace->breed(this->k, this->r);
		}
		this->Konie->survive(this->w);
		this->Osly->survive(this->w);
		this->Muly->survive(this->w);
		this->Jastrzebie->survive(this->w);
		this->Myszolowy->survive(this->w);
		this->Myszy->survive(this->w);
		this->Zajace->survive(this->w);
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