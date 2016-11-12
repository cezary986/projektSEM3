#ifndef LAKA_H_INCLUDED
#define LAKA_H_INCLUDED


#include <fstream>
#include <string>
#include "Populacja.h"

class Laka {
	int k;//ile sie losuje
	float w;//wpolczynnik wymierzania
	float r;//wspolczynnik rozmanzania
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
	Laka(int sk, float sw, float sr, int smn);
	void Symyluj();
	bool CreatePop(ifstream &sfile, string filename);
};

#endif // LAKA_H_INCLUDED
