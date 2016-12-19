#ifndef POPULACJA_H_INCLUDED
#define POPULACJA_H_INCLUDED

#include <vector>
#include "Gatunki.h"
#include <vector>
#include <string>

class Populacja
{
private:
	vector <Zwierze*> males;
	vector <Zwierze*> females;
	//Wektory z ktorych bede losowal pary do rozmnazania 
	vector <Zwierze*> malesToBreed;
	vector <Zwierze*> femalesToBreed;
	vector <Pair*> pairs;//vector na wylosowane do rozmnazania sie pary
	const string spieceID;
	void Populacja::clearPairs();
	bool breedable;
public:
	Populacja(string spieceID);
	~Populacja();
	//bool IsBreedable();
	void SetBreedable(bool a);
	void breed(int, float);
	void survive(float);
	void randomPairs(int, float);
	void addMale(Zwierze* a);
	void addFemale(Zwierze* a);
	int sizeOfPopulation();
	int sizeOfMalesToBreedVec();
	int sizeOfFemalesVec();
	int sizeOfMalesVec();
	int sizeOfFemalesToBreedVec();
	vector<Zwierze*> getMalesVec();
	vector<Zwierze*> getFemalesVec();
	void  setMalesToBreedVec(vector<Zwierze*> a);
	void setFemalesToBreedVec(vector<Zwierze*> a);
	vector<Zwierze*> getMalesToBreedVec();
	vector<Zwierze*> getFemalesToBreedVec();
	void clearMalesToBreed();
	void clearFemalesToBreed();
	void eraseAnimal(GENDER gender,int index);
	void slayPopulation();//usuwa wszystkich przedstawicieli populacji bez usuwania calego obiektu
	friend ostream& operator<< (ostream& output, Populacja const& ex);
};

#endif // POPULACJA_H_INCLUDED
