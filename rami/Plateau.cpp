#include "Plateau.h"
#include <iostream>


Plateau::Plateau()
{

}

// Affiche les cartes du plateau
void Plateau::afficher()
{
	for (int i = 0; i < (int)combinaisons_.size(); i++)
	{
		std::cout << i + 1 << ".";
		combinaisons_[i].afficherCombinaison();
		std::cout << " \n";
	}
}

// Affiche la combinaison numéro i
void Plateau::afficherCombinaison(int id)
{
	combinaisons_[id].afficherCombinaison();
}

// Ajoute une combinaison
void Plateau::ajouterCombinaison(Combinaison& Combinaison)
{
	combinaisons_.push_back(Combinaison);
	nombreCombinaison_++;
}

// Change la combinaison en ième position
void Plateau::modifierCombinaison(Combinaison & Combinaison,int id)
{
	if (id > 0 && id < combinaisons_.size())
	{
		combinaisons_[id] = Combinaison;
	}
	else
	{
		cout << "Erreur d'indice";
	}

}

// Vide les combinaisons du plateau
void Plateau::clearPlateau()
{
	combinaisons_.clear();
	nombreCombinaison_ = 0;
}


Plateau::~Plateau()
{
}
