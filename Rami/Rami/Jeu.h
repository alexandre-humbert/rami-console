#pragma once
#include <vector>
#include "Joueur.h"
#include "Plateau.h"
#include <stdlib.h>
#include "odrive.h"

class Jeu
{
	string nom_ = "Partie";
	int nbJoueurs_ = 0;
	int numJoueur_ = 0;
	vector<Joueur>joueurs_;
	Plateau	plateau_;
	Pioche pioche_;
	int manche_ = 0;
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
	void sauverJeu(ODrive od);
	void chargerJeu(ODrive od);
	~Jeu();
};

