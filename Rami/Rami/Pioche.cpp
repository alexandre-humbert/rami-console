#include "Pioche.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

Pioche::Pioche()
{
	 carte_.push_back(Carte("1", "Ca")); 
	 carte_.push_back(Carte("2", "Ca"));
	 carte_.push_back(Carte("3", "Ca"));
	 carte_.push_back(Carte("4", "Ca"));
	 carte_.push_back(Carte("5", "Ca"));
	 carte_.push_back(Carte("6", "Ca"));
	 carte_.push_back(Carte("7", "Ca"));
	 carte_.push_back(Carte("8", "Ca"));
	 carte_.push_back(Carte("9", "Ca"));
	 carte_.push_back(Carte("10", "Ca"));
	 carte_.push_back(Carte("11", "Ca"));
	 carte_.push_back(Carte("12", "Ca"));
	 carte_.push_back(Carte("13", "Ca"));
	 carte_.push_back(Carte("1", "Co"));
	 carte_.push_back(Carte("2", "Co"));
	 carte_.push_back(Carte("3", "Co"));
	 carte_.push_back(Carte("4", "Co"));
	 carte_.push_back(Carte("5", "Co"));
	 carte_.push_back(Carte("6", "Co"));
	 carte_.push_back(Carte("7", "Co"));
	 carte_.push_back(Carte("8", "Co"));
	 carte_.push_back(Carte("9", "Co"));
	 carte_.push_back(Carte("10", "Co"));
	 carte_.push_back(Carte("11", "Co"));
	 carte_.push_back(Carte("12", "Co"));
	 carte_.push_back(Carte("13", "Co"));
	 carte_.push_back(Carte("1", "P"));
	 carte_.push_back(Carte("2", "P"));
	 carte_.push_back(Carte("3", "P"));
	 carte_.push_back(Carte("4", "P"));
	 carte_.push_back(Carte("5", "P"));
	 carte_.push_back(Carte("6", "P"));
	 carte_.push_back(Carte("7", "P"));
	 carte_.push_back(Carte("8", "P"));
	 carte_.push_back(Carte("9", "P"));
	 carte_.push_back(Carte("10", "P"));
	 carte_.push_back(Carte("11", "P"));
	 carte_.push_back(Carte("12", "P"));
	 carte_.push_back(Carte("13", "P"));
	 carte_.push_back(Carte("1", "T"));
	 carte_.push_back(Carte("2", "T"));
	 carte_.push_back(Carte("3", "T"));
	 carte_.push_back(Carte("4", "T"));
	 carte_.push_back(Carte("5", "T"));
	 carte_.push_back(Carte("6", "T"));
	 carte_.push_back(Carte("7", "T"));
	 carte_.push_back(Carte("8", "T"));
	 carte_.push_back(Carte("9", "T"));
	 carte_.push_back(Carte("10", "T"));
	 carte_.push_back(Carte("11", "T"));
	 carte_.push_back(Carte("12", "T"));
	 carte_.push_back(Carte("13", "T"));
	 carte_.push_back(Carte("x", "x"));
}


Carte Pioche::tirerCarte()
{
	int nombre = 0;
	srand(time(NULL));
	nombre = rand();
	return carte_[nombre];
}

void Pioche::défausserCarte()
{
}


void Pioche::sauverPioche()
{
}

void Pioche::chargerPioche()
{
}


Pioche::~Pioche()
{
}
