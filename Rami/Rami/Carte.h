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
	string getValeur();
	string getCouleur();
	~Carte();
};

