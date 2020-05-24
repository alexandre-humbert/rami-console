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
		std::cout << i+1 << ".";
		main[i].afficherCarte();
		std::cout << " \n";
	}
}


void Joueur::piocher()
{
	if (pioche_->getTaillePioche() != 0)
	{
		Carte c = pioche_->tirerCarte();
		cout << "Carte piochee : ";
		c.afficherCarte();
		main.push_back(c);
	}
	else {
		if (pioche_->getTailleDefausse() != 0) {
			pioche_->renouvelerPioche();
		}
		else {
			cout << "Plus de carte" << endl;
		}
	}
}

void Joueur::defausser() {
	afficherMain();
	int choix;
	do {
		cout << "Choisissez la carte à défausser : " << endl;
		cin >> choix;
	} while (choix < 0 || choix>7);
	choix--;
	pioche_->defausserCarte(main[choix]);
	main.erase(main.begin() + choix);
	nombreCarte_--;
}


Joueur::Joueur(string nom, string id, Pioche *pioche)
{
	pioche_ = pioche;
	id_ = id;
	nom_ = nom;
	
	for (int i = 0; i < 7; i++)
	{
		main.push_back(pioche_->tirerCarte());
	}
	nombreCarte_ = 7;
}


Joueur::~Joueur()
{
}
