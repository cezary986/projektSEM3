#include "switches.h"
#include <iostream>

using namespace std;

void wys_komunikat()
{
	cout << "cos tam";
	return;
}

void switches(int arg, char **tab, string &input, string &output, string &type, int &date, int &lenghth, int &price)
{
	//liczba prze³¹czników
	const int K = 6;

	//przechowuje prze³¹czniki do porównania i potem ich wprowadzone nazwy
	string _switch[2 * K];

	_switch[0] = "-k";
	_switch[1] = "-o";
	_switch[2] = "-r";
	_switch[3] = "-t";
	_switch[4] = "-d";
	_switch[5] = "-c";


	//sprawdzenie czy liczba prze³¹czników jest dobra, +1 bo nazwa programu
	if (arg != 2 * K + 1)
		wys_komunikat();


	//sprawdzenie czy prze³¹cznik nie jest na ostatnim miejscu
	for (int i = 0; i < K; ++i)
	{
		if (tab[2 * K] == _switch[i])
			wys_komunikat();
	}

	//stra¿nik pilnuje czy odnalaz³ wszystkie poprawne prze³¹czniki
	int guard = 0;

	//odnalezenie przel¹cznika, nastêpny element to jego nazwa/liczba,
	for (int i = 1; i < arg; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			if (tab[i] == _switch[j])
			{
				_switch[j + 6] = tab[i + 1];
				++guard;
				break;
			}
		}
	}

	//sprawdzenie iloœæ poprawnych prze³¹czników
	if (guard != K)
		wys_komunikat();


	//sprawdzenie czy nie podano prze³¹cznika bez nazwy, czyli: "-k -o wejscie"
	for (int i = 0; i < K; ++i)
	{
		for (int j = 6; j < 2 * K; ++j)
		{
			if (_switch[i] == _switch[j])
				wys_komunikat();
		}
	}

	//przekazanie do main, bo referencja
	input = _switch[6];
	output = _switch[7];
	type = _switch[8];
	//zmiana z string na inta
	//	date= stoi(_switch[9]);
	//lenghth= stoi(_switch[10]);
	//	price= stoi(_switch[11]);
}
