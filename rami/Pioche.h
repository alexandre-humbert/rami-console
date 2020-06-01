#pragma once
#include <vector>
#include "Carte.h"
//Cette classe va gérer à la fois la pioche et la défausse du jeu.

mélanger permet de mélanger les cartes de la pioche.\newline
Lorsque la pioche est vide on peut utiliser la défausse pour la renouveler.\newline
tirerCarte permet à un joueur de tirer une carte sur le dessus de la pioche.\newline
\newline
On peut prendre la carte de la déffausse avec prendreDeffausse.\newline
class Pioche
{
	vector<Carte> cartes_;//On a comme attribut des vecteurs de Carte qui correspondent respectivement à la pioche et à la défausse.
	int taillePioche_=53;//On a aussi leur taille actuelle.
	vector<Carte>defausse_;
	int tailleDefausse_ = 0;

public:
	Pioche(string name =" ");//Le constructeur de pioche va initialiser les cartes de la pioche et va les mélanger ou non si il s'agit d'une démo ou non.
	int getTaillePioche();//On peut pour chaque attribut utiliser des set et des get.\newline
	int getTailleDefausse();
	vector<Carte> getPioche() { return cartes_; }
	vector<Carte> getDefausse() { return defausse_; }
	void setTaillePioche(int value) { taillePioche_ = value; }
	void setTailleDefausse(int value) { tailleDefausse_ = value; }
	void setPioche(vector<Carte> value) {cartes_=value; }
	void setDefausse(vector<Carte> value) { defausse_=value; }
	void melanger();//Permet de mélanger les cartes de la pioche.\newline
	void renouvelerPioche();//Lorsque la pioche est vide on peut utiliser la défausse pour la renouveler.
	Carte tirerCarte();//tirerCarte permet à un joueur de tirer une carte sur le dessus de la pioche.
	void afficherDefausse();//Avec afficherDefausse on peut afficher la première carte de la défausse.
	void defausserCarte(Carte c);//On peut deffausser une carte et ainsi l'ajouter à la défausse.
	Carte prendreDefausse();//On peut prendre la carte de la déffausse avec prendreDeffausse.
	~Pioche();
};

