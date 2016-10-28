#ifndef LAKA_H_INCLUDED
#define LAKA_H_INCLUDED

#include <vector>
#include <fstream>
#include <string>
#include "declarations.h"
#include "Populacja.h"
#include "Zwierze.h"

class Laka {
	int k;//ile sie losuje
	int w;//wpolczynnik wymierzania
	int r;//wspolczynnik rozmanzania
	int monthsNumber;//liczba miesiecy

protected:
	Populacja* Konie;
	Populacja* Osly;
	Populacja* Muly;
	Populacja* Jastrzebie;
	Populacja* Myszolowy;
	Populacja* Myszy;
	Populacja* Zajace;

public:
	void Symyluj(int monthsNumber);
	Laka(int sk, int sw, int sr, int smn);
	bool CreatePop(ifstream sfile, string filename);
};

#endif // LAKA_H_INCLUDED
