#include "Combinaison.h"
#include <algorithm>  


Combinaison::Combinaison(vector<Carte>& cartes)
{
	std::sort(cartes.begin(), cartes.end());
	cartes_ = cartes;
}

bool Combinaison::isValid()
{
	if ((cartes_.size() > 2)&&(isBrelan() || isSuite() || isCarre()))
		return true;
	return false;
}

bool Combinaison::isBrelan()
{
	if (cartes_.size() != 3)
		return false;
	else		if ((cartes_[0].getValeur() == cartes_[1].getValeur() || cartes_[0].getValeur()=="x" || cartes_[1].getValeur() == "x")			&& (cartes_[1].getValeur() == cartes_[2].getValeur() || cartes_[1].getValeur() == "x" || cartes_[2].getValeur() == "x")			&& (cartes_[2].getValeur() == cartes_[0].getValeur() || cartes_[2].getValeur() == "x" || cartes_[0].getValeur() == "x"))			return true;
		else
			return false;
}

bool Combinaison::isSuite()
{
	
	return false;
}

bool Combinaison::isCarre()
{
	if (cartes_.size() != 3)
		return false;
	else		if ((cartes_[0].getValeur() == cartes_[1].getValeur() || cartes_[0].getValeur() == "x" || cartes_[1].getValeur() == "x")			&& (cartes_[1].getValeur() == cartes_[2].getValeur() || cartes_[1].getValeur() == "x" || cartes_[2].getValeur() == "x")			&& (cartes_[3].getValeur() == cartes_[0].getValeur() || cartes_[3].getValeur() == "x" || cartes_[0].getValeur() == "x")			&& (cartes_[2].getValeur() == cartes_[3].getValeur() || cartes_[3].getValeur() == "x" || cartes_[2].getValeur() == "x"))			return true;
		else
			return false;
	return false;
}


Combinaison::~Combinaison()
{
}
