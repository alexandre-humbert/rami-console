#include "Joueur.h"
#include <iostream>
Carte Joueur::choisirCarte(int i)
{

	return main[i];
}

void Joueur::nouvelleCombinaison(vector<Carte>)
{
}

void Joueur::afficherMain()
{
	for (int i = 0; i < (int)main.size(); i++)
	{
		std::cout << i << ".";
		main[i].afficherCarte();
		std::cout << " \n";
	}
}

void Joueur::sauverJoueur()
{
}

void Joueur::chargerJoueur()
{
}

void Joueur::piocher()
{
	if (pioche_->getTaille() != 0)
	{

		main.push_back(pioche_->tirerCarte());
	}
	else cout << "plus de carte";
}

Joueur::Joueur(string nom,Pioche *pioche)
{
	pioche_ = pioche;
	nom_ = nom;
	for (int i = 0; i < 7; i++)
	{
		main.push_back(pioche_->tirerCarte());
	}
}


Joueur::~Joueur()
{
}
