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
	void setNombreCombinaison(int value) { nombreCombinaison_ = value; }
	Combinaison getCombinaison(int id) { return combinaisons_[id]; };
	void setCombinaison(int id,Combinaison combinaison) { combinaisons_[id]= combinaison; };
	void setCombinaisons(vector<Combinaison> value) { combinaisons_ = value; }
	void ajouterCombinaison(Combinaison& Combinaison);
	void modifierCombinaison(Combinaison& Combinaison,int id);
	void clearPlateau();
	~Plateau();
};

