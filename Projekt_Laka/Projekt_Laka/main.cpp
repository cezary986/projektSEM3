#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "getParameters.h"
#include "Laka.h"

using namespace std;


int main(int argc, char **argv)
{
	srand(time(NULL));
	//zmienne z wartoœciami przelaczników
	string input, output;
	int mounthNumber, k;
	float w, r;
	//funkcja dla sprawdzenia i przypisywania parametrom wartosci
	getParameters(argc, argv,input,output,w,mounthNumber,k,r);
	
	ifstream inputFile; 
//	inputFile.open(input, ios::in);
	ofstream outputFile;
	outputFile.open(output, ios::out);
	
	Laka * laka = new Laka(k, w, r, mounthNumber);

	laka->CreatePop(inputFile, input);

	laka->Symyluj();

    //cout<<"HELLO!";


	return 0;

}
