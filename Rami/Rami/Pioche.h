#pragma once
#include <vector>
#include "Carte.h"

class Pioche
{
	vector<Carte> cartes_;
	int taillePioche_=53;
	vector<Carte>defausse_;
	int tailleDefausse_ = 0;

public:
	Pioche();
	int getTaillePioche();
	int getTailleDefausse();
	void melanger();
	void renouvelerPioche();
	Carte tirerCarte();
	void afficherDefausse();
	void defausserCarte(Carte c);
	void sauverPioche();
	void chargerPioche();
	~Pioche();
};

