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
	bool operator < (const Carte& carte) const;
	bool operator == (const Carte& carte) const;
	int operator - (Carte& carte);
	string getValeur();
	string getCouleur();
	~Carte();
};

