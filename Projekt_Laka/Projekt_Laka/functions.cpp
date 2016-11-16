#include "functions.h"

//Funkcja do czyszczenie vectoro ktore zawieraja alokowane dynamicznie obiekty
void delete_vector_el(vector <Zwierze*> a)
{
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		delete (*i);
		a.erase(i);
	}
}

void delete_vector_el(vector <Pair*> a)
{

	for (auto i = a.begin(); i != a.end(); ++i)
	{
		delete *i;
		a.erase(i);
	}
}