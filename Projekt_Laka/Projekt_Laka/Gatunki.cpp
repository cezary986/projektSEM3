#include "Gatunki.h"

Kon * Kon::operator+(const Kon * ex)
{
	Kon * cub = new Kon;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}
////Kon moze takze z oslem
//Mul* Kon::operator +(const Osiol * ex)
//{
//	Mul * cub = new Mul;
//
//	if (this->sex == MALE)
//	{
//		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
//		for (int i = 0; i < int((cub->dadsPart)*(ex->chromSize)); i++)
//		{
//			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
//		}
//	}
//	else
//	{
//		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
//		for (int i = 0; i < int((cub->momsPart)*(this->chromSize)); i++)
//		{
//			cub->chromosome.push_back(this->chromosome[i]);
//		}
//	}
//	cub->sex = GENDER(rand() % 1);//losujemy plec
//	return cub;
//}
////Osiol moze z KOniem
//Mul* Osiol::operator +(const Kon* ex)
//{
//	Mul * cub = new Mul;
//
//	if (this->sex == MALE)
//	{
//		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
//		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
//		{
//			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
//		}
//	}
//	else
//	{
//		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
//		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
//		{
//			cub->chromosome.push_back(this->chromosome[i]);
//		}
//	}
//	cub->sex = GENDER(rand() % 1);//losujemy plec
//	return cub;
//}


Osiol * Osiol::operator +(const Osiol * ex)
{
	Osiol * cub = new Osiol;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Mul * Mul::operator +(const Mul* ex)
{
	return this;//Muly nie rozmanazaja sie
}

Jastrzab * Jastrzab::operator +(const Jastrzab* ex)
{
	Jastrzab * cub = new Jastrzab;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Myszolow * Myszolow::operator +(const Myszolow * ex)
{
	Myszolow * cub = new Myszolow;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Mysz * Mysz::operator +(const Mysz * ex)
{
	Mysz * cub = new Mysz;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

Zajac * Zajac::operator +(const Zajac * ex)
{
	Zajac * cub = new Zajac;

	if (this->sex == MALE)
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu ojca
		for (int i = 0; i < int((this->dadsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);//wpisuje liczby z chromosomu ojca do dziecka
		}
	}
	else
	{
		//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
		for (int i = 0; i < int((this->momsPart)*(this->chromSize)); i++)
		{
			cub->chromosome.push_back(this->chromosome[i]);
		}
	}
	cub->sex = GENDER(rand() % 1);//losujemy plec
	return cub;
}

