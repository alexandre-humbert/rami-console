#pragma once
#include <vector>
#include "Joueur.h"
#include "Plateau.h"
class Jeu
{
	vector<Joueur>joueurs_;
	Plateau	plateau_;
	
public:

	Jeu();
	void initialiserTour();
	void effectuerTour();
	~Jeu();
};

