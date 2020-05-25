#pragma once
#include <vector> 
#include <string>
#include <sstream>
#include <algorithm> 
#include "Carte.h"

class Combinaison
{
	vector<Carte> cartes_;
	//enum combin { Suite, Brelan, Carré };
public:
	Combinaison(vector<Carte>& cartes);
	vector<Carte> sortCarte(vector<Carte>& cartes);
	void afficherCombinaison();
	Carte getCarte(int id) { return cartes_[id]; }
	vector<Carte> getCartes() { return cartes_; }
	bool hasJoker();
	bool isValid();
	bool isBrelan();
	bool isSuite();
	bool isCarre();
	int getScore();
	~Combinaison();
};

