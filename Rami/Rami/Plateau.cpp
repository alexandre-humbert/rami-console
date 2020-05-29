#include "Plateau.h"
#include <iostream>


Plateau::Plateau()
{

}

void Plateau::afficher()
{
	for (int i = 0; i < (int)combinaisons_.size(); i++)
	{
		std::cout << i + 1 << ".";
		combinaisons_[i].afficherCombinaison();
		std::cout << " \n";
	}
}

void Plateau::afficherCombinaison(int id)
{
	combinaisons_[id].afficherCombinaison();
}

void Plateau::ajouterCombinaison(Combinaison& Combinaison)
{
	combinaisons_.push_back(Combinaison);
	nombreCombinaison_++;
}

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

void Plateau::clearPlateau()
{
	combinaisons_.clear();
	nombreCombinaison_ = 0;
}


Plateau::~Plateau()
{
}
