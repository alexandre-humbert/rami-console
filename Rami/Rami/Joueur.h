#pragma once
#include "Carte.h"
#include "Pioche.h"
#include "Combinaison.h"
#include <vector>
/**
La classe joueur représente un joueur.
Elle contient son nom, un identifiant générique, l'information s'il à déjà posé une combinaison ou non,
son score, son nombre de cartes, ses cartes et un pointeur vers la pioche.
*/
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
	bool getPose() { return premierePose_; }
	int getNombreCarte() { return nombreCarte_; }
	void setNom(string value) { nom_ = value; }
	bool setPose(bool b) {  premierePose_=b; }
	void setId(string value) { id_ = value; }
	void setScore(int value) { score_ = value; }
	void setNombreCarte(int value) { nombreCarte_ = value; }
	Carte choisirCarte(int i);
	Combinaison nouvelleCombinaison();
	vector<Carte> getMain() { return main; }
	void afficherMain(vector<Carte> retir);
	void afficherMain();
	void piocher();
	void defausser();
	Joueur(string nom, string id, Pioche* pioche);
	~Joueur();
};

