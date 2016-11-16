#include "Gatunki.h"

//Wszystkie metody born tworza i zwracaja nowe zwierze tego samego typu co rodzic 
//jego chromosom tworza na podstawie chromosomow rodzicow

Zwierze * Kon::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Kon;
	cout << "nowe rozmnazanie: ";
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
		{
			//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
			cub->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
		{
			//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
			cub->chromosome.push_back(mamsPart[i]);
		}
		//cout << "\n";
		cub->sex = GENDER(rand() % 1);//losujemy plec
		return cub;
}

Zwierze * Osiol::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Osiol;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
	{
		cub->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
	{
		cub->chromosome.push_back(mamsPart[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zwierze * Mul::born(vector<int> mamsPart, vector <int> dadsPart)
{
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
	{
		this->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
	{
		this->chromosome.push_back(mamsPart[i]);
	}
	this->sex = GENDER(rand() % 1);//losujemy plec
	return this;
}

Zwierze * Jastrzab::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Jastrzab;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
	{
		cub->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
	{
		cub->chromosome.push_back(mamsPart[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}
Zwierze * Myszolow::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Myszolow;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
	{
		cub->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
	{
		cub->chromosome.push_back(mamsPart[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zwierze * Mysz::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Mysz;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
	{
		cub->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
	{
		cub->chromosome.push_back(mamsPart[i]);
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zwierze * Zajac::born(vector<int> mamsPart, vector <int> dadsPart)
{
	Zwierze * cub = new Zajac;
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
	for (int i = 0; i < int(this->dadsPart * dadsPart.size()); i++)
	{
		cub->chromosome.push_back(dadsPart[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i <int(this->momsPart * mamsPart.size()); i++)
	{
		cub->chromosome.push_back(mamsPart[i]);
	}
	cout << "\n" << "nowe chrom size: " << cub->chromosome.size();
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

