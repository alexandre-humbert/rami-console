#include "Joueur.h"
#include "Carte.h"
#include <iostream>
Carte Joueur::choisirCarte(int i)
{

	return main[i];
}
// Retourne une combinason de cartes séléectionnées par le joueur.
Combinaison Joueur::nouvelleCombinaison(vector<Carte> maino)
{
	int id = 1;
	vector<Carte> cartes;
	do
	{
		afficherMain(maino);
		cout << "Choisir l'id d'une carte et -1 pour finir : " << endl;
		cin >> id;
		if (id != -1)
		{
			cartes.push_back(maino[id-1]);
			maino.erase(maino.begin() + id);
		}	

	} while (id != -1);
	Combinaison combi(cartes);
	return combi;

}
void Joueur::afficherMain(vector<Carte> maino)
{

	for (int i = 0; i < (int)maino.size(); i++)
	{
		std::cout << i + 1 << ".";
		maino[i].afficherCarte();
		std::cout << " \n";
	}
}
// Affiche les cartes que le joueur à en main.
void Joueur::afficherMain()
{
	for (int i = 0; i < (int)main.size(); i++)
	{
		std::cout << i + 1 << ".";
		main[i].afficherCarte();
		std::cout << " \n";
	}
}

// Permet au joueur de piocher une carte de la pioche qui est renouvelée si besoin.
void Joueur::piocher()
{
	if (pioche_->getTaillePioche() != 0)
	{
		Carte c = pioche_->tirerCarte();
		cout << "Carte piochee : ";
		c.afficherCarte();
		cout << endl;
		main.push_back(c);
		nombreCarte_++;
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

// Permet au joueur de défausser une carte choisie.
void Joueur::defausser() {
	afficherMain();
	int choix;
	do {
		cout << "Choisissez la carte a defausser : ";
		cin >> choix;
	} while (choix < 1 || choix>nombreCarte_);
	choix--;
	pioche_->defausserCarte(main[choix]);
	main.erase(main.begin() + choix);
	nombreCarte_--;
}

// Constructeur de joueur
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

// Compte les points des cartes d'un joueur en fin de manche
int Joueur::compterPoints() {
	int points =0;
	for (int i = 0; i < nombreCarte_; i++) {
		if (main[i].getValeur() == "x") { points += 20; }
		else { points += min(stoi(main[i].getValeur()), 11);}
	}
	score_ += points;
	return points;
}

void Joueur::renouvelerCartes() {
	main.clear();
	for (int i = 0; i < 7; i++)
	{
		main.push_back(pioche_->tirerCarte());
	}
	nombreCarte_ = 7;
}

void Joueur::tirerDefausse()
{
	main.push_back(pioche_->prendreDefausse());
	nombreCarte_++;
}
Joueur::~Joueur()
{
}

