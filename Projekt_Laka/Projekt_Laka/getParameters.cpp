#include "getParameters.h"

using namespace std;

void ParamsChecking::ExceptionHandling(ExceptionTypes a)
{
	switch (int(a))
	{
	case NUMBER:
		cerr << "Blad parametrów! Bledna liczba parametrow, powinno byc podanych 6\n";
		cerr << "Podaj: -i nazwa_pliku_wej -o nazwa_pliku_wyj -w wspolczynnik wymierania -r wspolczynnik rozmanzania - t liczba_miesiecy_symulacji - k liczba_par_losowanych_do_rozmnazania";
		break;
	case IN:
		cerr << "Blad parametrów! Bledna nazwa pliku wejsciowego lub plik nie istnieje\n";
		break;
	case OUT:
		cerr << "Blad parametrów! Bledna nazwa pliku wyjsciowego lub plik nie istnieje\n";
		break;
	case W:
		cerr << "Blad parametrów! Bledny wspolczynnik wymierania\n Sprawdz czy wspolczynnik  0 < w < 1 \n";
		break;
	case R:
		cerr << "Blad parametrów! Bledny wspolczynnik rozmazania\n Sprawdz czy wspolczynnik  0 < r < 1 \n";
		break;
	case UNDEF:
		cerr << "Blad parametrow! \nPodaj : -i nazwa_pliku_wej - o nazwa_pliku_wyj - w wspolczynnik wymierania - r wspolczynnik rozmanzania - t liczba_miesiecy_symulacji - k liczba_par_losowanych_do_rozmnazania";
	}
}


bool ParamsChecking::getParameters(int arg, char **tab, string &input, string &output, float &w, int &monthNumber, int &k, float &r)
{
	int guard = 0;
	string Switches[2 * PARAMSNUMBER] = { "-i", "-o", "-w","-r","-t","-k" };
	try
	{
		//Sprawdzenie liczby przelacznikow
		if (arg != 2 * PARAMSNUMBER + 1)
		{
			throw NUMBER;
		}
		//Sprawdzam czy nie ma na ostatnim przelacznika
		for (int i = 0; i < PARAMSNUMBER; ++i)
		{
			if (tab[2 * PARAMSNUMBER] == Switches[i])
			{
				throw UNDEF;
			}
		}
		//Przelacznik znaleziony 
		for (int i = 1; i < arg; ++i)
		{
			for (int j = 0; j < PARAMSNUMBER; ++j)
			{
				if (tab[i] == Switches[j])
				{
					Switches[j + PARAMSNUMBER] = tab[i + 1];
					++guard;
					break;
				}
			}
		}
		//Sprawdzam czy sa wszystkie przalczniki
		if (guard != PARAMSNUMBER)
		{
			throw NUMBER;
		}
		//Sprawdzam czy podano wszsytkie parametry
		for (int i = 0; i < PARAMSNUMBER; ++i)
		{
			for (int j = PARAMSNUMBER; j < 2 * PARAMSNUMBER; ++j)
			{
				if (Switches[i] == Switches[j])
				{
					throw UNDEF;
				}
			}
		}

		input = Switches[6];
		output = Switches[7];
		//zmiana z string na float
		w = stof(Switches[8]);
		r = stof(Switches[9]);
		monthNumber = stoi(Switches[10]);
		k = stoi(Switches[11]);

		if (w < 0 || w > 1)
		{
			throw W;
		}
		if (r < 0 || r > 1)
		{
			throw W;
		}
		return true;
	}
	catch (ExceptionTypes a)
	{
		ExceptionHandling(a);
		return false;
	}
}

