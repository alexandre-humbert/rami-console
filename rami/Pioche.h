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
	Pioche(string name =" ");
	int getTaillePioche();
	int getTailleDefausse();
	vector<Carte> getPioche() { return cartes_; }
	vector<Carte> getDefausse() { return defausse_; }
	void setTaillePioche(int value) { taillePioche_ = value; }
	void setTailleDefausse(int value) { tailleDefausse_ = value; }
	void setPioche(vector<Carte> value) {cartes_=value; }
	void setDefausse(vector<Carte> value) { defausse_=value; }
	void melanger();
	void renouvelerPioche();
	Carte tirerCarte();
	void afficherDefausse();
	void defausserCarte(Carte c);
	Carte prendreDefausse();
	~Pioche();
};

