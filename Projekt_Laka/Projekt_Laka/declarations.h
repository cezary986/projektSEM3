#ifndef DEKLARACJE_H_INCLUDED
#define DEKLARACJE_H_INCLUDED

using namespace std;

#define maxstring 8
#define spiecesNumber 7

//Czestotliwosci rozmnazania sie zwierzat wyrazone w miesiacach
#define KONIE_F 12
#define OSLY_F 12
#define MULY_F 24
#define JASTRZEBIE_F 6
#define MYSZOLOWY_F 4
#define MYSZY_F 1
#define ZAJACE_F 2
//Ile je, dany gatunek
#define MYSZOLOW_FOOD 5
#define JASTRZAB_FOOD 2
//Czesci chromosow dla gatunkow;
#define KON_DAD_PART 0.5
#define KON_MOM_PART 0.5

#define OSIOL_DAD_PART 0.33333
#define OSIOL_MOM_PART 0.66666

#define MUL_DAD_PART 0.33333
#define MUL_MOM_PART 0.5

#define JASTRZAB_DAD_PART 0.1
#define JASTRZAB_MOM_PART 0.9

#define MYSZOLOW_DAD_PART 0.4
#define MYSZOLOW_MOM_PART 0.6

#define MYSZ_DAD_PART 0.5
#define MYSZ_MOM_PART 0.5

#define ZAJAC_DAD_PART 1
#define ZAJAC_MOM_PART 0.33333



#define PARAMSNUMBER 6

enum ANIMALS { KON, OSIOL, MUL, JASTRZAB, MYSZOLOW, MYSZ, ZAJAC };

#endif // DEKLARACJE_H_INCLUDED
