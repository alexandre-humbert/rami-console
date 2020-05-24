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
	void setNom(string value) { nom_ = value; }
	void setId(string value) { id_ = value; }
	void setScore(int value) { score_ = value; }
	void setNombreCarte(int value) { nombreCarte_ = value; }
	Carte choisirCarte(int i);
	void nouvelleCombinaison(vector<Carte>);
	void afficherMain();
	void piocher();
	void defausser();
	Joueur(string nom, string id, Pioche* pioche);
	~Joueur();
};

