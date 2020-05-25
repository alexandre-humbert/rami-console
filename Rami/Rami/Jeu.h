#pragma once
#include <vector>
#include "Joueur.h"
#include "Plateau.h"
#include <stdlib.h>
#include "odrive.h"
/* La classe jeu est la classe principale de ce programme.
Elle contient le nom de la partie, le nombre de joueurs,la place du joueur, les joueurs, le plateau,
la pioche et le numéro de la manche.
*/
class Jeu
{
	string nom_ = "Partie";
	int nbJoueurs_ = 0;
	int numJoueur_ = 0;
	vector<Joueur>joueurs_;
	Plateau	plateau_;
	Pioche pioche_;
	int manche_ = 1;
	ODrive od;
public:

	Jeu();
	void afficherBootScreen();
	void demarrerPartie();
	void creerPartie();
	void rejoindrePartie();
	void nouveauJoueur(string nom, string id);
	void afficherTour();
	void effectuerTour();
	void afficherRegles();
	void sauverJeu();
	void chargerJeu();
	void abandonner();
	void exec();
	~Jeu();
};
