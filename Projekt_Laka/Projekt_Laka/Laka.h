#ifndef LAKA_H_INCLUDED
#define LAKA_H_INCLUDED

#include <vector>
#include <fstream>
#include <string>
#include "declarations.h"
#include "Populacja.h"

class Laka {
	int k;//ile sie losuje
	int w;//wpolczynnik wymierzania
	int r;//wspolczynnik rozmanzania
	int monthsNumber;//liczba miesiecy

protected:
	Populacja* Kon;
	Populacja* Osiol;
	Populacja* Mul;
	Populacja* Jastrzab;
	Populacja* Myszolow;
	Populacja* Mysz;
	Populacja* Zajac;

public:
	void Symyluj(int monthsNumber);
	Laka(int sk, int sw, int sr, int smn);
	bool CreatePop(ifstream sfile, string filename);
};

#endif // LAKA_H_INCLUDED
