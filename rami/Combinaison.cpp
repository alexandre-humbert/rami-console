#include "Combinaison.h"
#include <iostream>
using namespace std;

Combinaison::Combinaison()
{

}

Combinaison::Combinaison(vector<Carte>& cartes)
{
	cartes_ = cartes;
}


// Affiche les combinaisons sur la sortie standard
void Combinaison::afficherCombinaison()
{
	for (int j = 0; j < (int)cartes_.size(); j++)
	{
		std::cout << " ";
		cartes_[j].afficherCarte();
		std::cout << " ";
	}
}
// Vérifie si la combinaison contient un joker
bool Combinaison::hasJoker()
{
	for (int i = 0; i < (int)cartes_.size(); i++)
	{
		if (cartes_[i].getValeur()=="x")
		{
				return true;
		}
	}
	return false;
}

// Vérifie si la combinaison est valide
bool Combinaison::isValid()
{
	if ((cartes_.size() > 2)&&(isBrelan() || isSuite() || isCarre()))
		return true;
	return false;
}

// Vérifie si la combinaison est un brelan
bool Combinaison::isBrelan()
{
	if (cartes_.size() != 3)
		return false;
	else
		if ((cartes_[0] == cartes_[1] )
			&& (cartes_[1] == cartes_[2] )
			&& (cartes_[2] == cartes_[0]))
			return true;
		else
			return false;
}

// Vérifie si la combinaison est une suite
bool Combinaison::isSuite()
{
	if (cartes_.size() < 3)
		return false;
	else
	{
		vector<Carte> cartes = cartes_;
		//cartes=sortCarte(cartes);
		Carte joker("-1","-1");
		bool isJoker = false;
		for (int i= 0; i < (int)cartes_.size() ; i++)
		{
			if (cartes_[i].getValeur() == "x")
			{
				joker = cartes_[i];
				isJoker = true;
			}
		}
		for (int i = 0; i < (int)cartes.size()-1; i++)
		{
			if (((cartes[i] - cartes[i+1])!=1 )||(cartes[i].getCouleur() != cartes[i +1].getCouleur()&& cartes[i].getCouleur() !="x" &&cartes[i+1].getCouleur() !="x" )||( cartes[i].getValeur()=="x"&&i>0))
			{
				if ((cartes[i].getValeur() == "x")&&(i > 0)&&((cartes[i-1]- cartes[i+1])==2))
				{

		
				}
				else
					return false;
			}
		}
		return true;
	}
		
			

	return false;
}

// Vérifie si la combinaison est un carré
bool Combinaison::isCarre()
{
	if (cartes_.size() != 4)
		return false;
	else
		if ((cartes_[0] == cartes_[1])
			&& (cartes_[1] == cartes_[2])
			&& (cartes_[3] == cartes_[0])
			&& (cartes_[2] == cartes_[3]))
			return true;
		else
			return false;
	return false;
}

// Calcul la valeur d'une combinaison
int Combinaison::getScore()
{
	int score = 0;
	if (isBrelan())
	{
		istringstream is1(cartes_[0].getValeur());
		int n1;
		is1 >> n1;
		score = 3 * min(n1,11);
	}
	if (isCarre())
	{
		istringstream is1(cartes_[0].getValeur());
		int n1;
		is1 >> n1;
		score = 4 * min(n1, 11);
	}
	if (isSuite())
	{
		for (int i = 0; i<cartes_.size(); i++)
		{
			if (cartes_[i].getValeur() != "1")
			{
				istringstream is1(cartes_[i].getValeur());
				int n1;
				is1 >> n1;
				score += min(n1, 11);
			}
			else
			{
				if (i == 0)
				{
					score += 1;
				}
				else
				{
					score += 11;
				}
			}
		}
	}

	return score;
}


Combinaison::~Combinaison()
{
}
