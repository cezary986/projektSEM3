#include "Gatunki.h"

//Wszystkie metody born tworza i zwracaja nowe zwierze tego samego typu co rodzic 
//jego chromosom tworza na podstawie chromosomow rodzicow

Kon::Kon(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	cout << "Tyle od ojca " << int(this->dadsPart * dad.size()) << " ";
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	cout << "Tyle od matki " << int(this->momsPart * mom.size()) << " \n";
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		chromosome.push_back(mom[i]);
	}

}

Kon* Kon::breed(vector<int> dad, vector<int> mom)
{
	return (new Kon(dad, mom));
}

Kon::Kon(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}

}

Kon::~Kon()
{
	chromosome.clear();
}


Osiol::Osiol(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
		chromosome.push_back(mom[i]);
	}

}

Osiol* Osiol::breed(vector<int> dad, vector<int> mom)
{
	return (new Osiol(dad, mom));
}

Osiol::Osiol(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}
}


Osiol::~Osiol()
{
	chromosome.clear();
}


Mul::Mul(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
		chromosome.push_back(mom[i]);
	}
}

Mul* Mul::breed(vector<int> dad, vector<int> mom)
{
	return (new Mul(dad, mom));
}

Mul::Mul(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}
}


Mul::~Mul()
{
	chromosome.clear();
}



Jastrzab::Jastrzab(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
		chromosome.push_back(mom[i]);
	}
	cout<<chromosome.size();
}

Jastrzab* Jastrzab::breed(vector<int> dad, vector<int> mom)
{
	return (new Jastrzab(dad, mom));
}

Jastrzab::Jastrzab(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}
}


Jastrzab::~Jastrzab()
{
	chromosome.clear();
}


Myszolow::Myszolow(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
		chromosome.push_back(mom[i]);
	}
}

Myszolow* Myszolow::breed(vector<int> dad, vector<int> mom)
{
	return (new Myszolow(dad, mom));
}

Myszolow::Myszolow(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}
}
Myszolow::~Myszolow()
{
	chromosome.clear();
}

Mysz::Mysz(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
		chromosome.push_back(mom[i]);
	}

}

Mysz* Mysz::breed(vector<int> dad, vector<int> mom)
{
	return (new Mysz(dad, mom));
}

Mysz::Mysz(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}

}


Mysz::~Mysz()
{
	chromosome.clear();
}

Zajac::Zajac(vector<int> dad, vector<int> mom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < ceil(this->dadsPart * dad.size()); i++)
	{
		//cout <<"Tyle od ojca" << int(this->dadsPart * dadsPart.size()) << " ";
		chromosome.push_back(dad[i]);//wpisuje liczby z chromosomu ojca do dziecka
	}
	//warunek krancowy to liczba liczb ktore beda pochodzic z chromosomu matki
	for (int i = 0; i < ceil(this->momsPart * mom.size()); i++)
	{
		//cout <<"Tyle od matki" <<int(this->momsPart * mamsPart.size()) << " ";
		chromosome.push_back(mom[i]);
	}

}

Zajac::Zajac(vector<int> chrom)
{
	sex = GENDER(rand() % 2);

	for (int i = 0; i < chrom.size(); i++)
	{
		chromosome.push_back(chrom[i]);
	}

}

Zajac* Zajac::breed(vector<int> dad, vector<int> mom)
{
	return (new Zajac(dad, mom));
}

Zajac::~Zajac()
{
	chromosome.clear();
}

//TODO sklejanie chromosowmow insertem 