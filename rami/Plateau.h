#pragma once
#include "Combinaison.h"
#include <vector>
//Plateau est la clesse qui va nous permettre de poser des combinaisons. On pourra également les modifier.
class Plateau
{
	vector<Combinaison> combinaisons_;//Un vecteur qui contient chacune des combinaison du plateau.
	int nombreCombinaison_ = 0;//On a le nombre de combinaisons du plateau.
public:
	Plateau();
	void afficher();//Affiche toute les combinaisons du plateau.
	void afficherCombinaison(int id);//affiche une combinaison du plateau. 
	int getnombreCombinaison() { return nombreCombinaison_; }//Retourne le nombre de combinaison.
	void setNombreCombinaison(int value) { nombreCombinaison_ = value; }//Définie le nombre de combinaison.
	Combinaison getCombinaison(int id) { return combinaisons_[id]; };//Retourne une combinaison du plateur.
	void setCombinaison(int id,Combinaison combinaison) { combinaisons_[id]= combinaison; };//Définie une combinaison du plateau.
	void setCombinaisons(vector<Combinaison> value) { combinaisons_ = value; }//Définie les combinaisons du plateau.
	void ajouterCombinaison(Combinaison& Combinaison);//Permet d'ajouter une combinaison au plateau.
	void modifierCombinaison(Combinaison& Combinaison,int id);//On peut modifier une combinaison.
	void clearPlateau();//On supprime toute les combinaison du plateau.
	~Plateau();
};

