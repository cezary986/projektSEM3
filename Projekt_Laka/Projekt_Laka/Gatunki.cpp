#include "Gatunki.h"

//Wszystkie metody born tworza i zwracaja nowe zwierze tego samego typu co rodzic 
//jego chromosom tworza na podstawie chromosomow rodzicow


Zwierze * Kon::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Kon;
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < this->dadsPart * dadsPart.size(); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i <this->momsPart * mamsPart.size(); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
		cub->sex = GENDER(rand() % 1);//losujemy plec
		return cub;
}

Zwierze * Osiol::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Osiol;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < this->dadsPart * dadsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <this->momsPart * mamsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zwierze * Mul::born(vector<int> mamsPart, vector <int> dadsPart)
{
	return this;
}

Zwierze * Jastrzab::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Jastrzab;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < this->dadsPart * dadsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < this->momsPart * mamsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}
Zwierze * Myszolow::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Myszolow;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < this->dadsPart * dadsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <this->momsPart * mamsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zwierze * Mysz::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Mysz;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < this->dadsPart * dadsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <this->momsPart * mamsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zwierze * Zajac::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Zajac
;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < this->dadsPart * dadsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <this->momsPart * mamsPart.size(); i++)
	{
		cub->chromosome.push_back(this->chromosome[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}