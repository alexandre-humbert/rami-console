
#include <vector>  
#include <iostream>
#include "Carte.h"
#include "Combinaison.h"
#include "Pioche.h"
#include "Joueur.h"
#include "Jeu.h"
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL));
	Pioche pioche;
	pioche.melanger();
	Joueur joueur("Alexandre","j1", &pioche);
	joueur.afficherMain();
	vector<Carte> cartes;
	cartes.push_back(Carte("5", "Co"));
	cartes.push_back(Carte("x", "x"));
	cartes.push_back(Carte("5", "Ca"));
	cartes.push_back(Carte("5", "T"));
	Combinaison c1(cartes);
	if (c1.isCarre())
		cout << "Carre";
	else
		cout << "non";
	Jeu Partie("Ma partie");
	Partie.afficherBootScreen();


}

