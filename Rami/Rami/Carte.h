#pragma once
#include <string>

using namespace std;

class Carte
{
	string valeur_;
	string couleur_;
public:
	Carte(string valeur,string couleur);
	void afficherCarte();
	bool operator < ( Carte& carte) ;
	bool operator == ( Carte& carte) ;
	int operator - (Carte& carte);
	string getValeur();
	string getCouleur();
	~Carte();
};

