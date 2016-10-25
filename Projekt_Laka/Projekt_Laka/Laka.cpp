#include "Laka.h"



Laka::Laka(int sk, int sw, int sr, int mn)
{
	k = sk;
	w = sw;
	r = sr;
	monthsNumber = mn;

	Kon = nullptr;
	Osiol = nullptr;
	Mul = nullptr;
	Jastrzab = nullptr;
	Myszolow = nullptr;
	Mysz = nullptr;
	Zajac = nullptr;
}

bool Laka::CreatePop(ifstream sfile, string filename)
{
	sfile.open(filename,ios::out);
	string line;
	string temp;

	if (sfile.good())
	{
		while (sfile)
		{
			getline(sfile, line);
			//Trzeba poszukac sposobu na tokenizacje elementow 	
			/*
				CIALO 
			*/
		}
	}
	else
	{
		sfile.close();
		return 0;
	}

}