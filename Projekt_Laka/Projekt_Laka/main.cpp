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
	srand(time(nullptr));
	//zmienne z wartoœciami prze³¹czników
	string input, output;
	int mounthNumber, k;
	float w, r;
	//funkcja dla sprawdzenia poprawnoœci prze³aczników i przypisuje im podane nazwy
	getParameters(argc, argv,input,output,w,mounthNumber,k,r);
	
	ifstream inputFile; 
	inputFile.open(input, ios::in);
	ofstream outputFile;
	outputFile.open(output, ios::out);
	
	Laka * laka = new Laka(k, w, r, mounthNumber);

	laka->CreatePop(inputFile, input);

    cout<<"HELLO!";


	return 0;

}
