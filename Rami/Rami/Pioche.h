#pragma once
#include <vector>
#include "Carte.h"

class Pioche
{
	vector<Carte> carte_;
	vector<Carte>defausse_;
public:
	Pioche();
	Carte tirerCarte();
	void défausserCarte();
	void sauverPioche();
	void chargerPioche();
	~Pioche();
};

