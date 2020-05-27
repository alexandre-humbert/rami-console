#include "Jeu.h"
#include<iostream>
#include "odrive.h"
#include <fstream>

Jeu::Jeu()
{

}

void Jeu::afficherTour()
{
	cout << "Manche " << manche_ << endl;
	for (int i = 0; i < 2; i++) {
		cout << "Joueur : " << joueurs_[i].getNom() << endl;
		cout << "Score : " << joueurs_[i].getScore() << endl;
		cout << "Nombre cartes : " << joueurs_[i].getNombreCarte() << endl;
		cout << endl;
	}
	if (pioche_.getTailleDefausse() != 0) {
		cout << "Defausse : ";
		pioche_.afficherDefausse();
	}
	cout << "Vos cartes : " << endl;
	joueurs_[numJoueur_].afficherMain();
}

void Jeu::effectuerTour()
{
	system("CLS");
		if (numJoueur_ == 0)
		{
			cout << "_________________" << endl;
			cout << "C'est votre tour" << endl;
			cout << "_________________" << endl;
			cout << "Piochez une carte" << endl;
			system("PAUSE");
			joueurs_[numJoueur_].piocher();
			string choix = "0";
			do
			{
				afficherTour();
				cout << "Que voulez-vous faire ?" << endl;
				cout << "1. Poser des combinaison" << endl;
				cout << "2. Defausser une carte" << endl;
				cout << "3. Abandonner" << endl;
				getline(cin, choix);
			} while (choix != "1" && choix != "2" && choix != "3");
			if (choix == "1")
			{
				poseCombinaison();
			}
		else if (choix == "2") {
			joueurs_[numJoueur_].defausser();
		}
		else {
			abandonner();
		}
		manche_++;
		sauverJeu();
		cout << "_________________" << endl;
		cout << "Fin de votre tour" << endl;
		cout << "_________________" << endl;
		cout << " C'est au joueur adverse de jouer" << endl;
		od.waitForChange("Rami/" + nom_ + "/jeu.txt");
		chargerJeu();
	}

	if (numJoueur_ == 1) {
		cout << "C'est au joueur adverse de jouer" << endl;
		od.waitForChange("Rami/" + nom_ + "/jeu.txt");
		chargerJeu();
		afficherTour();
		cout << "_________________" << endl;
		cout << "C'est votre tour" << endl;
		cout << "_________________" << endl;
		cout << "Piochez une carte" << endl;
		system("PAUSE");
		joueurs_[numJoueur_].piocher();
		string choix = "0";
		do {
			afficherTour();
			cout << "Que voulez-vous faire ?" << endl;
			cout << "1. Poser des combinaison" << endl;
			cout << "2. Defausser une carte" << endl;
			cout << "3. Abandonner" << endl;
			getline(cin, choix);
		} while (choix != "1" && choix != "2" && choix != "3");
		if (choix == "1") {
			poseCombinaison();
		}
		else if (choix == "2") {
			joueurs_[numJoueur_].defausser();
		}
		else {
			abandonner();
		}
		manche_++;
		sauverJeu();
		cout << "_________________" << endl;
		cout << "Fin de votre tour" << endl;
		cout << "_________________" << endl;
	}
}

void Jeu::afficherBootScreen() {
	cout << " " << endl;
	cout << "            _____" << endl;
	cout << "           |A .  | _____" << endl;
	cout << "           | /.\\ ||A ^  | _____" << endl;
	cout << "           |(_._)|| / \\ ||A _  | _____" << endl;
	cout << "           |  |  || \\ / || ( ) ||A_ _ |" << endl;
	cout << "           |____V||  .  ||( ' )|| (v) | " << endl;
	cout << "                  |____V||  |  || \\ / |" << endl;
	cout << "                         |____V||  .  |" << endl;
	cout << "                                |____V|" << endl;
	cout << " " << endl;
	cout << "______                    _      _____                 " << endl;
	cout << "| ___ \\                  (_)    /  __ \\     _        _   " << endl;
	cout << "| |_/ /  __ _  _ __ ___   _     | /  \\/   _| |_    _| |_ " << endl;
	cout << "|    /  / _` || '_ ` _ \\ | |    | |      |_   _|  |_   _| " << endl;
	cout << "| |\\ \\ | (_| || | | | | || |    | \\__/\\    |_|      |_|  " << endl;
	cout << "\\_| \\_| \\__,_||_| |_| |_||_|     \\____/                " << endl;
	cout << endl;
	system("PAUSE");
	system("CLS");


}
void Jeu::demarrerPartie() {
	system("CLS");
	cout << "Que voulez-vous faire :" << endl;
	cout << "1. Creer une nouvelle partie" << endl;
	cout << "2. Rejoindre une partie:" << endl;
	string choix;
	getline(cin, choix);
	if (choix == "1") { creerPartie(); }
	else if (choix == "2") { rejoindrePartie(); }
	else { demarrerPartie(); }

}

void Jeu::creerPartie() {
	system("CLS");
	string baseDir = "Rami";
	string nomPartie;
	cout << "Entrez le nom de la partie :" << endl;
	getline(cin, nomPartie);
	string gameDir = baseDir + '/' + nomPartie;
	od.refresh(baseDir);
	od.sync(baseDir);
	if (!od.isDir(gameDir))
	{
		od.mkDir(gameDir);
		od.refresh(baseDir);
	}

	nom_ = nomPartie;
	cout << "Entrez votre nom :" << endl;
	string nomJoueur;
	getline(cin, nomJoueur);
	pioche_.melanger();
	nouveauJoueur(nomJoueur, "j1");
	numJoueur_ = 0;
	sauverJeu();
	cout << "En attente du joueur adverse" << endl;
	od.waitForChange(gameDir + "/jeu.txt");
	do
	{
		od.refresh(gameDir);
		od.sync(gameDir + "/j2.txt");
		od.sync(gameDir);
		od.refresh(gameDir);
	} while (!ifstream(od.getFullName(gameDir + "/j2.txt")).good());
	nouveauJoueur("j2", "j2");
	chargerJeu();
}


void Jeu::rejoindrePartie() {
	system("CLS");
	string baseDir = "Rami";
	string nomPartie;
	cout << "Entrez le nom de la partie :" << endl;
	getline(cin, nomPartie);
	string gameDir = baseDir + '/' + nomPartie;
	od.mkDir(gameDir);

	od.sync(gameDir);
	od.sync(gameDir + "/jeu.txt");
	od.sync(gameDir + "/j1.txt");
	od.sync(gameDir + "/pioche.txt");
	od.sync(gameDir + "/defausse.txt");
	od.sync(gameDir + "/plateau.txt");
	od.refresh(gameDir);

	if (!ifstream(od.getFullName(gameDir + "/jeu.txt")).good())
	{
		cout << "Cette partie n'existe pas" << endl;
		system("PAUSE");
		rejoindrePartie();
	}
	else {
		nom_ = nomPartie;
		nouveauJoueur("j1", "j1");
		chargerJeu();
		cout << "Entrez votre nom :" << endl;
		string nomJoueur;
		getline(cin, nomJoueur);
		pioche_.melanger();
		nouveauJoueur(nomJoueur, "j2");
		numJoueur_ = 1;
		sauverJeu();
	}
}

void Jeu::nouveauJoueur(string nom, string id) {
	joueurs_.push_back(Joueur(nom, id, &pioche_));
	nbJoueurs_++;
}

void Jeu::poseCombinaison()
{
	vector<Combinaison> combinaisons;
	vector<Carte> main;
	string ch = "o";
	while (ch == "o")
	{
		Combinaison combinaison = joueurs_[numJoueur_].nouvelleCombinaison();
		if (combinaison.isValid())
		{
			combinaisons.push_back(combinaison);
			
			
		}
		else
		{
			cout << "Combinaison invalide" << endl;
		}
		cout << "Voulez-vous ajouter une autre combinaison? o/n" << endl;
		getline(cin, ch);
	}
	if (combinaisons.size() > 0)
	{
		if (joueurs_[numJoueur_].getPose())
		{
			for (int k = 0; k < combinaisons.size(); k++)
			{
				plateau_.ajouterCombinaison(combinaisons[k]);
				for (int j = 0; j < joueurs_[numJoueur_].getMain().size(); j++)
				{
					bool notRetir = true;
					for (int i = 0; i < combinaisons[k].getCartes().size(); i++)
					{
						if (joueurs_[numJoueur_].getMain()[i].getValeur() == combinaisons[k].getCartes()[j].getValeur()
							&& joueurs_[numJoueur_].getMain()[i].getCouleur() == combinaisons[k].getCartes()[j].getCouleur())
							notRetir = false;
					}
					if(notRetir)
					main.push_back(joueurs_[numJoueur_].getMain()[j]);
				}
			}
		}
		else
		{
			int score = 0;
			for (int i = 0; i < combinaisons.size(); i++)
			{
				score += combinaisons[i].getScore();
			}
			if (score > 20)
			{
				for (int i = 0; i < combinaisons.size(); i++)
				{
					plateau_.ajouterCombinaison(combinaisons[i]);
				}
			}
			else
			{
				cout << "La combinaison doit faire 20 points" << endl;
			}
		}
	}
}

void Jeu::changeCombinaison()
{
	int id = 0;
	plateau_.afficher();
	cout << "Choisissez la combinaison à modifier : " << endl;
	cin>> id;
	string choix = "0";
	do
	{	
		cout << "Que voulez vous faire ?";
		cout << "1. Rajouter une carte à l'avant";
		cout << "2. Rajouter une carte à l'arrière";
		if (plateau_.getCombinaison(id).hasJoker())
		{
			cout << "3. Remplacer le joker";
			cout << "4. Cancel";
		}
		else {
			cout << "3. Cancel";
		}
		getline(cin, choix);
	} while (!(choix == "1" || choix == "2" || choix == "3" || (choix == "4"&&plateau_.getCombinaison(id).hasJoker())));

}

void Jeu::afficherRegles() {
	cout << "Voici les regles et le fonctionnement de ce jeu. " << endl;
	cout << " Chaque joueur dispose de 7 cartes. Vous devez poser des combinaions de cartes (brelan, carre, suite)" << endl;
	cout << "Le premier qui pose toutes ses cartes gagne la manche" << endl;
	cout << "Bonne chance " << endl;
	system("PAUSE");
	system("CLS");
}

void Jeu::sauverJeu() {

	string baseDir = "Rami";
	string gameDir = baseDir + '/' + nom_;
	od.refresh(gameDir);

	// Sauvegarde des joueurs
	for (int i = 0; i < joueurs_.size(); i++) {
		string fileName = joueurs_[i].getId();
		ofstream ofile(od.getFullName(gameDir + '/' + fileName + ".txt"));
		ofile << joueurs_[i].getNom() << endl;
		ofile << joueurs_[i].getId() << endl;
		ofile << joueurs_[i].getScore() << endl;
		ofile << joueurs_[i].getNombreCarte() << endl;
		ofile.close();
	}

	// Sauvegarde de la pioche
	ofstream ofile(od.getFullName(gameDir + "/pioche.txt"));
	ofile << pioche_.getTaillePioche() << endl;
	for (int i = 0; i < pioche_.getTaillePioche(); i++) {
		ofile << pioche_.getPioche()[i].getValeur() << endl;
		ofile << pioche_.getPioche()[i].getCouleur() << endl;

	}
	ofile.close();

	// Sauvegarde de la defausse
	ofile.open(od.getFullName(gameDir + "/defausse.txt"));
	ofile << pioche_.getTailleDefausse() << endl;
	for (int i = 0; i < pioche_.getTailleDefausse(); i++) {
		ofile << pioche_.getDefausse()[i].getValeur() << endl;
		ofile << pioche_.getDefausse()[i].getCouleur() << endl;

	}
	ofile.close();


	// Sauvegarde du plateau
	ofile.open(od.getFullName(gameDir + "/plateau.txt"));
	ofile << plateau_.getnombreCombinaison() << endl;
	for (int i = 0; i < plateau_.getnombreCombinaison(); i++)
	{
		for (int j=0; j < (plateau_.getCombinaison(i)).getCartes().size(); j++) {
			ofile << plateau_.getCombinaison(i).getCarte(j).getValeur() << endl;
			ofile << plateau_.getCombinaison(i).getCarte(j).getCouleur() << endl;
		}
		ofile << "NB" << endl;
		ofile << "NB" << endl;
	}

	ofile.close();


	// Sauvegarde de jeu
	ofile.open(od.getFullName(gameDir + "/jeu.txt"));
	ofile << nom_ << endl;
	ofile << nbJoueurs_ << endl;
	ofile << manche_ << endl;
	ofile << numJoueur_ << endl;
	ofile.close();
	od.sync(gameDir);
	ofile.close();

}


void Jeu::chargerJeu() {
	string baseDir = "Rami";
	string gameDir = baseDir + '/' + nom_;
	od.refresh(gameDir);

	// Charger le jeu
	ifstream ifile(od.getFullName(gameDir + "/jeu.txt"));
	if (ifile.good()) {
		ifile >> nom_;
		ifile >> nbJoueurs_;
	}
	ifile.close();

	// Charger les joueurs
	for (int i = 0; i < joueurs_.size(); i++) {
		ifstream ifile(od.getFullName(gameDir + "/j" + to_string(i + 1) + ".txt"));
		if (ifile.good()) {
			string buffer;
			ifile >> buffer;
			joueurs_[i].setNom(buffer);
			ifile >> buffer;
			joueurs_[i].setId(buffer);
			ifile >> buffer;
			joueurs_[i].setScore(stoi(buffer));
			ifile >> buffer;
			joueurs_[i].setNombreCarte(stoi(buffer));
		}
		ifile.close();
	}

	// Charger la pioche
	ifile.open(od.getFullName(gameDir + "/pioche.txt"));
	if (ifile.good()) {
		string buffer;
		ifile >> buffer;
		pioche_.setTaillePioche(stoi(buffer));
		vector<Carte> nouvellePioche;
		string valeur;
		string couleur;
		for (int i = 0; i < pioche_.getTaillePioche(); i++) {
			ifile >> valeur;
			ifile >> couleur;
			nouvellePioche.push_back(Carte(valeur, couleur));
		}
		pioche_.setPioche(nouvellePioche);
	}
	ifile.close();


	// Charger la defausse
	ifile.open(od.getFullName(gameDir + "/defausse.txt"));
	if (ifile.good()) {
		string buffer;
		ifile >> buffer;
		pioche_.setTailleDefausse(stoi(buffer));
		vector<Carte> nouvelleDefausse;
		string valeur;
		string couleur;
		for (int i = 0; i < pioche_.getTailleDefausse(); i++) {
			ifile >> valeur;
			ifile >> couleur;
			nouvelleDefausse.push_back(Carte(valeur, couleur));
		}
		pioche_.setDefausse(nouvelleDefausse);
	}
	ifile.close();


	// Charger le plateau
	ifile.open(od.getFullName(gameDir + "/plateau.txt"));
	if (ifile.good()) {
		int nb;
		ifile >> nb;
		plateau_.setNombreCombinaison(nb);
		string valeur = " ";
		string couleur = " ";
		int i=0;
		vector<Combinaison> combinaisons;
		while ( i < nb){
			Combinaison c;
			while (valeur != "NC") {
				ifile >> valeur;
				ifile >> couleur;
				c.ajouterCarte(Carte(valeur, couleur));
			}
			combinaisons.push_back(c);
		}
		plateau_.setCombinaisons(combinaisons);
	}
	ifile.close();


}

void Jeu::abandonner() {
	nbJoueurs_--;
	sauverJeu();
}

void Jeu::exec() {
	afficherBootScreen();
	afficherRegles();
	demarrerPartie();
	while (1) {
		while (joueurs_[0].getNombreCarte() != 0 && joueurs_[1].getNombreCarte() != 0) {
			effectuerTour();
		}
		// Nouvelle pioche
		// Redistribuer carte
	}
}
Jeu::~Jeu()
{
	od.delFile("Rami/" + nom_ + "/jeu.txt");
	od.delFile("Rami/" + nom_ + "/j1.txt");
	od.delFile("Rami/" + nom_ + "/j2.txt");
	od.delFile("Rami/" + nom_ + "/pioche.txt");
	od.delFile("Rami/" + nom_ + "/defausse.txt");
	od.delFile("Rami/" + nom_ + "/plateau.txt");
}
