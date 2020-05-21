#pragma once
#include "Carte.h"
#include "Pioche.h"
#include <vector>

class Joueur
{
	string nom_;
	int score_;
	int nombreCarte_;
	vector<Carte> main;
	Pioche* pioche_;
public:
	Carte choisirCarte(int i);
	void nouvelleCombinaison(vector<Carte>);
	void afficherMain();
	void sauverJoueur();
	void chargerJoueur();
	void piocher();
	void defausser();
	Joueur(string nom_, Pioche *pioche);
	~Joueur();
};

