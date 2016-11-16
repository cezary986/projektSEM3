#ifndef LAKA_H_INCLUDED
#define LAKA_H_INCLUDED


#include <fstream>
#include <string>
#include "Populacja.h"
#include <typeinfo>

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

	void feed(Populacja * whosEating, Populacja *whosEaten, int howMany);
	void crossBreed(Populacja *, Populacja*, ANIMALS childType);

public:
	Laka(int sk, float sw, float sr, int smn);
	~Laka();
	void Symyluj();
	bool CreatePop(ifstream &sfile, string filename);
	friend ostream& operator<< (ostream &wyjscie, Laka const& ex);
};

#endif // LAKA_H_INCLUDED
