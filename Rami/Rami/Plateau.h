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
	bool ajouterCombinaison(Combinaison& Combinaison);
	bool modifierCombinaison(Combinaison& Combinaison);
	~Plateau();
};

