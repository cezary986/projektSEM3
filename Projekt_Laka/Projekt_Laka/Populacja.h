#ifndef POPULACJA_H_INCLUDED
#define POPULACJA_H_INCLUDED

#include "declarations.h"
#include "Zwierze.h"
#include <vector>

class Populacja
{
protected:
	vector <Zwierze*> animals;

public:
	void breed();

};

#endif // POPULACJA_H_INCLUDED
