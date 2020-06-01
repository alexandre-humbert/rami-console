// Classe Joueur réalisée par Aurélien Arbaretaz et Alexandre Humbert

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
	string nom_; // Le nom du joueur
	string id_; // Son identifiant
	bool premierePose_ = false; // Vrai si le joueur a déjà posé.
	int score_ =0; // Le score du joueur
	int nombreCarte_; // Le nombre de cartes du joueur
	vector<Carte> main; //Un vecteur des cartes du joueurs
	Pioche* pioche_; // Un pointeur vers la pioche du jeu.
public:
	string getNom() { return nom_; } // Retourne le nom du joueur
	string getId() { return id_; } // Retourne son id
	int getScore() { return score_; } // retourne son score
	bool getPose() { return premierePose_; } // Retourne vrai s'il a déjà posé
	int getNombreCarte() { return nombreCarte_; } // Retourne le nombre de cartes du joueur
	void setNom(string value) { nom_ = value; } // Change son nom
	void setPose(bool b) {  premierePose_=b; } // Change l'état s'il à déjà posé
	void setId(string value) { id_ = value; } // Change son id
	void setScore(int value) { score_ = value; } // Change son score
	void setNombreCarte(int value) { nombreCarte_ = value; } // Change son nombre de cartes
	void setMain(vector<Carte> maino) { main = maino; } // Change sa main par un vecteur de carte en entrée
	Carte choisirCarte(int i); // Retourne la carte en i ème position
	vector<Carte> getMain() { return main; } // Retourne les cartes de la mains sous forme d'un vecteur de cartes
	Combinaison nouvelleCombinaison(vector<Carte> maino); // Retourne une combinaison formée de cartes du joueur
	void afficherMain(vector<Carte> maino); // Affiche un vecteur de carte mis en argument
	void afficherMain(); // Affiche la main du joueur
	void piocher(); // Pioche une carte : supprime de la pioche et l'ajoute à la main
	int compterPoints(); // Compte les points des cartes que le joueur à en main
	void renouvelerCartes(); // Vide la main du joueur et tire 7 cartes
	void tirerDefausse(); // Ajoute la première carte de la défausse à la main du joueur
	void defausser(); // Défausse une carte du joueur (gère la saisie de la carte)
	Joueur(string nom, string id, Pioche* pioche); // Constructeur de joueur
	~Joueur();
};

