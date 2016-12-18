#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "getParameters.h"
#include "Laka.h"
#include <vld.h>

using namespace std;

double Kon::momsPart = KON_MOM_PART;
double Kon::dadsPart = KON_DAD_PART;

double Osiol::momsPart = OSIOL_MOM_PART;
double Osiol::dadsPart = OSIOL_DAD_PART;

double Mul::momsPart = MUL_MOM_PART;
double Mul::dadsPart = MUL_DAD_PART;

double Jastrzab::momsPart = JASTRZAB_MOM_PART;
double Jastrzab::dadsPart = JASTRZAB_DAD_PART;

double Myszolow::momsPart = MYSZOLOW_MOM_PART;
double Myszolow::dadsPart = MYSZOLOW_DAD_PART;

double Mysz::momsPart = MYSZ_MOM_PART;
double Mysz::dadsPart = MYSZ_DAD_PART;

double Zajac::momsPart = ZAJAC_MOM_PART;
double Zajac::dadsPart = ZAJAC_DAD_PART;


int main(int argc, char **argv)
{
	srand(time(nullptr));
	//zmienne z wartoœciami przelaczników
	string input, output;
	int mounthNumber, k;
	float w, r;
	//Obiekt tworzony dla sprawdzenia i przypisywania parametrom wartosci
	ParamsChecking * parameters = new ParamsChecking();
	if (parameters->getParameters(argc, argv, input, output, w, mounthNumber, k, r))
	{
		delete parameters;

		ifstream inputFile;
		ofstream outputFile;

		Laka * laka = new Laka(k, w, r, mounthNumber);
		laka->CreatePop(inputFile, input);
		laka->Symyluj();

		outputFile.open(output, ios::out);
		outputFile << *laka;
		outputFile.close();

		delete laka;
		return 1;
	}
	else//sprawdzanie parametrow nie przebieglo pomyslnie
	{
		delete parameters;
		return 0;
	}
}
