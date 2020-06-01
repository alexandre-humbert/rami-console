#pragma once
#include <vector> 
#include <string>
#include <sstream>
#include <algorithm> 
#include "Carte.h"
//Cette classe va permettre de regrouper des cartes pour créer une combinaison on pourra vérifier 
//la validité de la combinaison et l'afficher.
class Combinaison
{
	vector<Carte> cartes_;//Une combinaison sera composé d'un vecteur de cartes.
	//enum combin { Suite, Brelan, Carré };
public:
	
	Combinaison();//Ont a deux constructeurs avec des paramètre en entrée ou non.\newline
	Combinaison(vector<Carte>& cartes);
	vector<Carte> sortCarte(vector<Carte>& cartes);
	void afficherCombinaison();//Avec afficherCombinaison on peut afficher une combinaison de carte.
	Carte getCarte(int id) { return cartes_[id]; }//On pourra obtenir une carte à partir de son id 
	vector<Carte> getCartes() { return cartes_; }//ou obtenir toutes les cartes avec getCartes.
	void ajouterCarte(Carte value) { cartes_.push_back(value); }//On peut ajouter une carte à l'arrière rapidement avec ajouterCarte.
	bool isValid();//isValid permet de determiner si une combinaison est valide.
	bool isBrelan();//permet de determiner si une combinaison est un brelan.
	bool isSuite();// permet de determiner si une combinaison est une suite.
	bool isCarre();//permet de determiner si une combinaison est un carré.
	int getScore();//retourne le score d'une combaison.
	~Combinaison();
};

