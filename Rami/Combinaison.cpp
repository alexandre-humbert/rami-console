#include "Combinaison.h"



Combinaison::Combinaison(vector<Carte> cartes)
{
	cartes_ = cartes;
}

bool Combinaison::isValid()
{
	if (isBrelan() || isSuite() || isCarre())
		return true;
	return false;
}

bool Combinaison::isBrelan()
{
	return false;
}

bool Combinaison::isSuite()
{
	return false;
}

bool Combinaison::isCarre()
{
	return false;
}


Combinaison::~Combinaison()
{
}
