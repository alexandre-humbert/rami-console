#include "Carte.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Carte::Carte(string valeur, string couleur)
{
	valeur_ = valeur;
	couleur_ = couleur;
}

void Carte::afficherCarte()
{

}

bool Carte::operator<(const Carte & carte) const
{
	if((valeur_<carte.valeur_ && valeur_!="x")|| carte.valeur_=="x")
		return true;
	return false;
}

bool Carte::operator==(const Carte & carte) const
{
	if (valeur_ == carte.valeur_|| valeur_ == "x"|| carte.valeur_ == "x")
		return true;
	return false;
}

int Carte::operator-(Carte & carte)
{
	istringstream is1(carte.getValeur);
	int n1;
	is1 >> n1;
	istringstream is2(valeur_);
	int n2;
	is2 >> n2;
	return (n2-n1);
}



string Carte::getValeur()
{
	
	return valeur_;
}

string Carte::getCouleur()
{
	return couleur_;
}


Carte::~Carte()
{
}
