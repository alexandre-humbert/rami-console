// Classe Carte réalisée par Aurélien Arbaretaz


#pragma once
#include <string>

using namespace std;
//Cette classe va permettre de créer et manipuler chacune des cartes.
class Carte
{
	string valeur_;//Cette classe à deux attributs qui vont chacun indiquer une valeur et une couleur.
	string couleur_;
public:
	Carte(string valeur="0",string couleur="0");
	void afficherCarte();//va afficher une carte.
	bool operator < ( Carte& carte) ;//permet de comparer la valeur de deux cartes.
	bool operator == ( Carte& carte) ;//permet de comparer la valeur de deux cartes.
	int operator - (Carte& carte);//- on retourne la différence de deux valeurs de cartes en prenant en compte le Joker et l'as on l'utilisera pour verifier q'une suite est bonne.
	string getValeur();//getValeur et getCouleur permettent d'obtenir la valeur des attributs.
	string getCouleur();
	~Carte();
};

