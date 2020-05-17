#include "Combinaison.h"


Combinaison::Combinaison(vector<Carte>& cartes)
{

	//std::sort(cartes.begin(), cartes.end());
	cartes_ = cartes;
}

vector<Carte> Combinaison::sortCarte(vector<Carte>& cartes)
{
	if (cartes.size() > 1)
	{
		int i, j, min;
		Carte temp("0", "0");
		for (i = 0; i < (int)cartes.size() - 1; i++) 
		{
			min = i;
			for (j = i + 1; j < (int)cartes.size(); j++)
			{
				if (cartes[j] < cartes[min])
					min = j;
			}
			temp = cartes[i];
			cartes[i] = cartes[min];
			cartes[min] = temp;
		}
	}

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
	else		if ((cartes_[0].getValeur() == cartes_[1].getValeur() )			&& (cartes_[1].getValeur() == cartes_[2].getValeur() )			&& (cartes_[2].getValeur() == cartes_[0].getValeur()))			return true;
		else
			return false;
}

bool Combinaison::isSuite()
{
	if (cartes_.size() <= 3)
		return false;
	else
	{
		vector<Carte> cartes = cartes_;
		cartes=sortCarte(cartes);
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
			if ((cartes[i] - cartes[i+1])!=1 && cartes[i + 1].getValeur!="x")
			{
				if (isJoker)
				{
					for (int j = (int)cartes.size(); j > i; j--)
					{
						cartes[j] = cartes[j - 1];
					}
					cartes[i] = joker;
					i++;
				}
				else
					return false;
			}
		}
	}
					
	return false;
}

bool Combinaison::isCarre()
{
	if (cartes_.size() != 3)
		return false;
	else		if ((cartes_[0].getValeur() == cartes_[1].getValeur())			&& (cartes_[1].getValeur() == cartes_[2].getValeur())			&& (cartes_[3].getValeur() == cartes_[0].getValeur())			&& (cartes_[2].getValeur() == cartes_[3].getValeur()))			return true;
		else
			return false;
	return false;
}


Combinaison::~Combinaison()
{
}
