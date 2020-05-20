#pragma once
#include <vector>
#include "Carte.h"

class Pioche
{
	vector<Carte> carte_;
	int taillePioche_=53;
	vector<Carte>defausse_;
public:
	Pioche();
	int getTaille();
	Carte tirerCarte();
	void défausserCarte();
	void sauverPioche();
	void chargerPioche();
	~Pioche();
};

