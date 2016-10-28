#ifndef GATUNKI_H_INCLUDED
#define GATUNKI_H_INCLUDED

#include "Zwierze.h"

using namespace std;

class Kon : public Zwierze
{
	friend class Osiol;
	Kon* operator +(const Kon*);
	//Mul* operator +(const Osiol*);
};

class Osiol : public Zwierze
{
	friend class Kon;
	Osiol *operator +(const Osiol*);
	//Mul* operator +(const Kon*);
};

class Mul : public Zwierze
{
	friend class Osiol;
	friend class Kon;
	Mul * operator +(const Mul*);
};

class Jastrzab : public Zwierze
{
	Jastrzab * operator +(const Jastrzab*);
};

class Myszolow : public  Zwierze
{
	Myszolow * operator +(const Myszolow*);
};

class Zajac : public Zwierze
{
	Zajac * operator +(const Zajac*);
};

class Mysz : public Zwierze
{
	Mysz * operator +(const Mysz*);
};

#endif // GATUNKI_H_INCLUDED