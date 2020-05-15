#include "Carte.h"



Carte::Carte(string valeur, string couleur)
{
	valeur_ = valeur;
	couleur_ = couleur;
}

void Carte::afficherCarte()
{

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
