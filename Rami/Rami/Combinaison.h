#pragma once
#include <vector> 
#include "Carte.h"

class Combinaison
{
	vector<Carte> cartes_;
	//enum combin { Suite, Brelan, Carré };
public:
	Combinaison(vector<Carte>& cartes);
	vector<Carte> sortCarte(vector<Carte>& cartes);
	bool isValid();
	bool isBrelan();
	bool isSuite();
	bool isCarre();
	~Combinaison();
};

