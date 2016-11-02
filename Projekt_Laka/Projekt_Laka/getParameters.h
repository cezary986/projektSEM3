#ifndef  GETPARAMETERS_H_INCLUDED
#define GETPARAMETERS_H_INCLUDED

#include <stdio.h>
#include <string>
#include "declarations.h"

using namespace std;


enum ErrorTypes { NUMBER, IN, OUT, W, R, UNDEF };

void getParameters(int arg, char **tab, string &input, string &output, float &w, int &monthNumber, int &k, float &r);
void error(ErrorTypes a);

#endif //  GETPARAMETERS_H_INCLUDED

