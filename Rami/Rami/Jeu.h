#pragma once
#include <vector>
#include "Joueur.h"
#include "Plateau.h"
#include <stdlib.h>

class Jeu
{
	vector<Joueur>joueurs_;
	Plateau	plateau_;
	
public:

	Jeu();
	void Jeu::afficherBootScreen();
	void initialiserTour();
	void effectuerTour();
	~Jeu();
};

