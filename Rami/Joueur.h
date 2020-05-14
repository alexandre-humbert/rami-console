#pragma once
#include "Carte.h"
#include <vector>

class Joueur
{
	string nom_;
	int score_;
	int nombreCarte_;
	vector<Carte> main;
public:
	Carte choisirCarte();
	void nouvelleCombinaison(vector<Carte>);
	void afficherMain();
	void sauverJoueur();
	void chargerJoueur();
	Joueur();
	~Joueur();
};

