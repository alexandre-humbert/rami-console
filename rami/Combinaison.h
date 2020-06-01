// Classe Combinaison réalisée par Aurélien Arbaretaz

#pragma once
#include <vector> 
#include <string>
#include <sstream>
#include <algorithm> 
#include "Carte.h"
//Cette classe va permettre de regrouper des cartes pour créer une combinaison. On pourra vérifier 
//la validité de la combinaison et l'afficher.
class Combinaison
{
	vector<Carte> cartes_;//Une combinaison sera composée d'un vecteur de cartes.
	//enum combin { Suite, Brelan, Carré };
public:
	
	Combinaison();//On a deux constructeurs avec des paramètres en entrée ou non.
	Combinaison(vector<Carte>& cartes);
	bool hasJoker(); // Retourne vrai si la combinaison contient un joker.
	void afficherCombinaison();//Affiche une combinaison de carte.
	Carte getCarte(int id) { return cartes_[id]; }//On pourra obtenir une carte à partir de son id 
	vector<Carte> getCartes() { return cartes_; }//ou obtenir toutes les cartes avec getCartes.
	void ajouterCarte(Carte value) { cartes_.push_back(value); }//On peut ajouter une carte à l'arrière rapidement.
	bool isValid();//isValid permet de determiner si une combinaison est valide.
	bool isBrelan();//Détermine si une combinaison est un brelan.
	bool isSuite();// Déterminer si une combinaison est une suite.
	bool isCarre();//Déterminer si une combinaison est un carré.
	int getScore();//Retourne le score d'une combaison.
	~Combinaison();
};

