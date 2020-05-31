#include "Pioche.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

Pioche::Pioche(string name)
{
	if (name.find("demo") == 0) {
		cartes_.push_back(Carte("1", "Ca"));
		cartes_.push_back(Carte("2", "Ca"));
		cartes_.push_back(Carte("3", "Ca"));
		cartes_.push_back(Carte("4", "Ca"));
		cartes_.push_back(Carte("5", "Ca"));
		cartes_.push_back(Carte("6", "Ca"));
		cartes_.push_back(Carte("7", "Ca"));
		cartes_.push_back(Carte("8", "Ca"));
		cartes_.push_back(Carte("9", "Ca"));
		cartes_.push_back(Carte("10", "Ca"));
		cartes_.push_back(Carte("11", "Ca"));
		cartes_.push_back(Carte("12", "Ca"));
		cartes_.push_back(Carte("1", "Co"));
		cartes_.push_back(Carte("2", "Co"));
		cartes_.push_back(Carte("3", "Co"));
		cartes_.push_back(Carte("4", "Co"));
		cartes_.push_back(Carte("5", "Co"));
		cartes_.push_back(Carte("6", "Co"));
		cartes_.push_back(Carte("7", "Co"));
		cartes_.push_back(Carte("8", "Co"));
		cartes_.push_back(Carte("9", "Co"));
		cartes_.push_back(Carte("10", "Co"));
		cartes_.push_back(Carte("11", "Co"));
		cartes_.push_back(Carte("1", "P"));
		cartes_.push_back(Carte("2", "P"));
		cartes_.push_back(Carte("3", "P"));
		cartes_.push_back(Carte("4", "P"));
		cartes_.push_back(Carte("5", "P"));
		cartes_.push_back(Carte("6", "P"));
		cartes_.push_back(Carte("7", "P"));
		cartes_.push_back(Carte("8", "P"));
		cartes_.push_back(Carte("9", "P"));
		cartes_.push_back(Carte("10", "P"));
		cartes_.push_back(Carte("11", "P"));
		cartes_.push_back(Carte("12", "P"));
		cartes_.push_back(Carte("1", "T"));
		cartes_.push_back(Carte("12", "Co"));
		cartes_.push_back(Carte("2", "T"));
		cartes_.push_back(Carte("3", "T"));
		cartes_.push_back(Carte("4", "T"));
		cartes_.push_back(Carte("5", "T"));
		cartes_.push_back(Carte("6", "T"));
		cartes_.push_back(Carte("7", "T"));
		cartes_.push_back(Carte("8", "T"));
		cartes_.push_back(Carte("9", "T"));
		cartes_.push_back(Carte("10", "T"));
		cartes_.push_back(Carte("11", "T"));
		cartes_.push_back(Carte("12", "T"));
		cartes_.push_back(Carte("13", "Co"));
		cartes_.push_back(Carte("13", "T"));
		cartes_.push_back(Carte("13", "Ca"));
		cartes_.push_back(Carte("13", "P"));
		cartes_.push_back(Carte("x", "x"));
	}
	else {
		cartes_.push_back(Carte("1", "Ca"));
		cartes_.push_back(Carte("2", "Ca"));
		cartes_.push_back(Carte("3", "Ca"));
		cartes_.push_back(Carte("4", "Ca"));
		cartes_.push_back(Carte("5", "Ca"));
		cartes_.push_back(Carte("6", "Ca"));
		cartes_.push_back(Carte("7", "Ca"));
		cartes_.push_back(Carte("8", "Ca"));
		cartes_.push_back(Carte("9", "Ca"));
		cartes_.push_back(Carte("10", "Ca"));
		cartes_.push_back(Carte("11", "Ca"));
		cartes_.push_back(Carte("12", "Ca"));
		cartes_.push_back(Carte("13", "Ca"));
		cartes_.push_back(Carte("1", "Co"));
		cartes_.push_back(Carte("2", "Co"));
		cartes_.push_back(Carte("3", "Co"));
		cartes_.push_back(Carte("4", "Co"));
		cartes_.push_back(Carte("5", "Co"));
		cartes_.push_back(Carte("6", "Co"));
		cartes_.push_back(Carte("7", "Co"));
		cartes_.push_back(Carte("8", "Co"));
		cartes_.push_back(Carte("9", "Co"));
		cartes_.push_back(Carte("10", "Co"));
		cartes_.push_back(Carte("11", "Co"));
		cartes_.push_back(Carte("12", "Co"));
		cartes_.push_back(Carte("13", "Co"));
		cartes_.push_back(Carte("1", "P"));
		cartes_.push_back(Carte("2", "P"));
		cartes_.push_back(Carte("3", "P"));
		cartes_.push_back(Carte("4", "P"));
		cartes_.push_back(Carte("5", "P"));
		cartes_.push_back(Carte("6", "P"));
		cartes_.push_back(Carte("7", "P"));
		cartes_.push_back(Carte("8", "P"));
		cartes_.push_back(Carte("9", "P"));
		cartes_.push_back(Carte("10", "P"));
		cartes_.push_back(Carte("11", "P"));
		cartes_.push_back(Carte("12", "P"));
		cartes_.push_back(Carte("13", "P"));
		cartes_.push_back(Carte("1", "T"));
		cartes_.push_back(Carte("2", "T"));
		cartes_.push_back(Carte("3", "T"));
		cartes_.push_back(Carte("4", "T"));
		cartes_.push_back(Carte("5", "T"));
		cartes_.push_back(Carte("6", "T"));
		cartes_.push_back(Carte("7", "T"));
		cartes_.push_back(Carte("8", "T"));
		cartes_.push_back(Carte("9", "T"));
		cartes_.push_back(Carte("10", "T"));
		cartes_.push_back(Carte("11", "T"));
		cartes_.push_back(Carte("12", "T"));
		cartes_.push_back(Carte("13", "T"));
		cartes_.push_back(Carte("x", "x"));
		melanger();
	}
	taillePioche_ = 53;

}

int Pioche::getTaillePioche()
{
	return taillePioche_;
}

int Pioche::getTailleDefausse()
{
	return tailleDefausse_;
}

// Remplace la pioche par la defausse quand elle est vide et melange la nouvelle pioche
void Pioche::renouvelerPioche() {
	cartes_ = defausse_;
	taillePioche_ = tailleDefausse_;
	defausse_.clear();
	tailleDefausse_ = 0;
	melanger();
}

// Permet de melanger la pioche
void Pioche::melanger() {
	srand(unsigned(time(0)));
	random_shuffle(cartes_.begin(), cartes_.end());
}
// Retourne une carte de la pioche en supprimant cette carte de la pioche
Carte Pioche::tirerCarte()
{
	Carte c;
	c = cartes_.back();
	cartes_.pop_back();
	taillePioche_--;
	return c;
}

// Affiche la premiere carte de la défausse
void Pioche::afficherDefausse() {
	(defausse_.back()).afficherCarte();
	cout << endl;
}

// Ajoute une carte a la défausse
void Pioche::defausserCarte(Carte c)
{
	defausse_.push_back(c);
	tailleDefausse_++;
}


Carte Pioche::prendreDefausse()
{
	Carte c;
	c = defausse_.back();
	defausse_.pop_back();
	tailleDefausse_--;
	return c;
}

Pioche::~Pioche()
{
}
