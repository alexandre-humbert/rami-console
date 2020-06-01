// Classe Jeu réalisée par Alexandre Humbert et Aurélien Arbaretaz 

#pragma once
#include <vector>
#include "Joueur.h"
#include "Plateau.h"
#include <stdlib.h>
#include "odrive.h"

class Jeu
{
	string nom_ = "Partie"; // Le nom de la partie
	int nbJoueurs_ = 0; // Le nombre de joueurs
	int numJoueur_ = 0; // Le numéro du joueur
	vector<Joueur>joueurs_; // Un vecteur de joueurs
	Plateau	plateau_; // Un plateau
	Pioche pioche_; // Une pioche (et défausse)
	int tour_ = 1; // Le numéro du tour en cours.
	ODrive od;
public:

	Jeu();
	void afficherBootScreen(); // affiche un dessin au lancement.
	void menuTour(); // affiche les possibilité du joeur à chaque tour.
	void demarrerPartie(); // Permet de chosiir entre créer et rejoindre une partie.
	void creerPartie(); // Permet de créer une nouvelle partie.
	void rejoindrePartie(); // Permet de rejoindre une partie déjà créée.
	void nouveauJoueur(string nom, string id); // Ajoute un nouveau joueur avec un nom et un id.
	void afficherTour(); // Affiche le score, le nombre de carte et le nom de joueurs ainsi que les cartes du joueur et la première carte de la défausse et les combinaisons.
	void effectuerTour(); // permet d'effectuer un tour complet (poser, modifier des combinaisons)
	void poseCombinaison(); // Permet de poser une combianaison sur le plateau en demandant les cartes à mettre.
	void changeCombinaison(); // Permet de modifier une combinaisons déjà posée en demandant les changement à faire.
	void afficherRegles(); // Affiche les règles (au lancement du jeu)
	void sauverJeu(); // Sauvegarde la pioche, le plateau, les joueurs dans un fichier texte.
	void chargerJeu(); // Charge le plateau, la pîoche, les joueurs à partir du fichier texte.
	void abandonner(); // Permet d'abandonner en modifiant le fichier de sauvegarde.
	void exec(); // Contient tout le déroulement d'une partie à parir des fonctions précédentes.
	~Jeu(); // Destructeur de Jeu, supprime les fichiers de sauvegarde.
};
