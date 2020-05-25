#pragma once
#include "Combinaison.h"
#include <vector>
class Plateau
{
	vector<Combinaison> combinaisons_;
	int nombreCombinaison_ = 0;
public:
	Plateau();
	void afficher();
	void afficherCombinaison(int id);
	int getnombreCombinaison() { return nombreCombinaison_; }
	Combinaison getCombinaison(int id) { return combinaisons_[id]; };
	void ajouterCombinaison(Combinaison& Combinaison);
	void modifierCombinaison(Combinaison& Combinaison,int id);
	~Plateau();
};

