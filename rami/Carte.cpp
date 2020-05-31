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
	if (valeur_ == "11")cout << "V";
	else if(valeur_ == "12")cout << "D";
	else if (valeur_ == "13")cout << "R";
	else if (valeur_ == "x")cout << "J";
	else cout << valeur_;
	if (couleur_ == "x")cout << "";
	else cout <<"-"<< couleur_;

}

bool Carte::operator<(Carte & carte) 
{
	if((valeur_<carte.getValeur() && valeur_!="x")|| carte.getValeur() =="x")
		return true;
	return false;
}

bool Carte::operator==(Carte & carte) 
{
	if (valeur_ == carte.getValeur() || valeur_ == "x"|| carte.getValeur() == "x")
		return true;
	return false;
}

int Carte::operator-(Carte & carte)
{
	if  (valeur_ == "x" || carte.getValeur() == "x")
	{
		return 1;
	}

	if (valeur_ == "13"&&carte.getValeur() == "1")
	{
		return 1;
	}
	if (valeur_ == "12"&&carte.getValeur() == "1")
	{
		return 2;
	}
		istringstream is1(carte.getValeur());
		int n1;
		is1 >> n1;
		istringstream is2(valeur_);
		int n2;
		is2 >> n2;
		int n3 = n1 - n2;
		return n3;
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
