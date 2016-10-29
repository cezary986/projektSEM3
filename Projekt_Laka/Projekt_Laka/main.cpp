#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

#include "switches.h"
#include "Laka.h"

using namespace std;


int main(int argc, char **argv)
{
	srand(time(nullptr));
	//zmienne z wartoœciami prze³¹czników
	string input, output;
	int w,mounthNumber, k, r;
	//funkcja dla sprawdzenia poprawnoœci prze³aczników i przypisuje im podane nazwy
	switches(argc, argv,input,output,w,mounthNumber,k,r);
	
	ifstream inputFile; 
	//inputFile.open(input, ios::in);
	ofstream outputFile;
	outputFile.open(output, ios::out);
	
	Laka * laka = new Laka(k, w, r, mounthNumber);

	laka->CreatePop(inputFile, output);


    cout<<"HELLO!";


	return 0;

}
