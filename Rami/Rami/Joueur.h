#pragma once
#include "Carte.h"
#include "Pioche.h"
#include <vector>

class Joueur
{
	string nom_;
	string id_;
	bool premierePose_ = false;
	int score_ =0;
	int nombreCarte_;
	vector<Carte> main;
	Pioche* pioche_;
public:
	string getNom() { return nom_; }
	string getId() { return id_; }
	int getScore() { return score_; }
	int getNombreCarte() { return nombreCarte_; }
	Carte choisirCarte(int i);
	void nouvelleCombinaison(vector<Carte>);
	void afficherMain();
	void piocher();
	void defausser();
	Joueur(string nom, string id, Pioche* pioche);
	~Joueur();
};

