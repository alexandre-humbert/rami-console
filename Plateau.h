#pragma once
#include "Combinaison.h"
#include <vector>
class Plateau
{
	vector<Combinaison> combinaisons_;
	int nombreCombinaison_;
public:
	Plateau();
	void afficher();
	void ajouterCombinaison();
	void modifierCombinaison(Combinaison& Combinaison);
	~Plateau();
};
