#ifndef  GETPARAMETERS_H_INCLUDED
#define GETPARAMETERS_H_INCLUDED

#include <stdio.h>
#include <string>
#include "declarations.h"
#include <iostream>
#include <exception>

/*Enum na rodzaje wyjatkow ktore obsluguje metoda ExceptionHandler
NUMBER - bledna liczba parametrow
IN - plik wejsciowy nie istnieje lub brak dostepu
OUT -plik wyjsciowy nie istnieje lub brak dostepu
W - bledny wspolczynnik wymierania
R - bledny wspolczynnik rozmanazania
UNDEF - niezdefiniowany blad, wyrzucany przy blednych przelacznikach np dwa takie same
*/
enum ExceptionTypes { NUMBER, IN, OUT, W, R, UNDEF };

class ParamsChecking
{
public:
	//Funkcja sprawdza parametry i wprowadza je do zmiennych podanych w liscie argumentow
	bool getParameters(int arg, char **tab, string &input, string &output, float &w, int &monthNumber, int &k, float &r);
	//Metoda do obslugi wyjatkow wyrzuconych przed getParameters w czasie sprawdzania parametrow
	void ExceptionHandling(ExceptionTypes a);
};


#endif //  GETPARAMETERS_H_INCLUDED

