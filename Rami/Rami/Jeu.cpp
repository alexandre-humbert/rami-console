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
			afficherTour();
			cout << "Piochez une carte" << endl;
			system("PAUSE");
			system("CLS");
			joueurs_[numJoueur_].piocher();
			menuTour();		
			cout << " C'est au joueur adverse de jouer" << endl;
			od.waitForChange("Rami/" + nom_ + ".txt");
			chargerJeu();
	}

	if (numJoueur_ == 1) {
		cout << "C'est au joueur adverse de jouer" << endl;
		od.waitForChange("Rami/" + nom_ + ".txt");
		chargerJeu();
		cout << "_________________" << endl;
		cout << "C'est votre tour" << endl;
		cout << "_________________" << endl;
		afficherTour();
		cout << "Piochez une carte" << endl;
		system("PAUSE");
		system("CLS");
		joueurs_[numJoueur_].piocher();
		menuTour();
		manche_++;
		sauverJeu();
		cout << "_________________" << endl;
		cout << "Fin de votre tour" << endl;
		cout << "_________________" << endl;
	}
}


void Jeu::menuTour() {

	string choix = "0";
	while (choix != "1" && choix != "2" && choix != "3" && choix=="4") {
		afficherTour();
		cout << "Que voulez-vous faire ?" << endl;
		cout << "1. Poser des combinaison" << endl;
		cout << "2. Modifier une combinaison" << endl;
		cout << "3. Defausser une carte" << endl;
		cout << "4. Abandonner" << endl;
		getline(cin, choix);
	}
	if (choix == "1") {
		poseCombinaison();
		menuTour();
	}

	else if (choix == "2") {
		if (plateau_.getnombreCombinaison() != 0) {
			changeCombinaison();
		}
		else { cout << " Aucune combinaison modifiable" << endl; }
		menuTour();
	}
	else if (choix == "3") {
		joueurs_[numJoueur_].defausser();
	}
	else if (choix =="4") {
		abandonner();
	}
	if (choix != "4") {
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
	nom_ = nomPartie;
	od.refresh(baseDir);
	od.sync(baseDir);
	cout << "Entrez votre nom :" << endl;
	string nomJoueur;
	getline(cin, nomJoueur);
	pioche_ = Pioche(nom_);
	nouveauJoueur(nomJoueur, "j1");
	numJoueur_ = 0;
	sauverJeu();
	cout << "En attente du joueur adverse" << endl;
	od.waitForChange("Rami/" + nom_ + ".txt");
	nouveauJoueur("j2", "j2");
	od.refresh(baseDir);
	chargerJeu();
}


void Jeu::rejoindrePartie() {
	system("CLS");
	string baseDir = "Rami";
	string nomPartie;
	cout << "Entrez le nom de la partie :" << endl;
	getline(cin, nomPartie);
	od.sync(baseDir);
	od.sync("Rami/" + nomPartie + ".txt");
	od.refresh(baseDir);

	if (!ifstream(od.getFullName("Rami/" + nomPartie + ".txt")).good())
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
	vector<Carte> main = joueurs_[numJoueur_].getMain();
	vector<Carte> main2 = joueurs_[numJoueur_].getMain();
	string ch = "o";

	do
	{
		vector<Carte> cartes;
		vector<int> ids;
		int id = 0;
		do
		{
			joueurs_[numJoueur_].afficherMain(main);
			cout << "Choisir l'id d'une carte et -1 pour finir : " << endl;
			cin >> id;
			if (id != -1)
			{
				cartes.push_back(main[id - 1]);
				main.erase(main.begin() + id - 1);
			}
		} while (id != -1);

		Combinaison combinaison(cartes);
		if (combinaison.isValid())
		{
			combinaisons.push_back(combinaison);
			main2 = main;
		}
		else
		{
			main = main2;
			cout << "Combinaison invalide" << endl;
			combinaison.afficherCombinaison();
		}
		cout << "Voulez-vous ajouter une autre combinaison? o/n" << endl;
		cin >> ch;
	} while (ch == "o");
	if (combinaisons.size() > 0)
	{
		if (joueurs_[numJoueur_].getPose())
		{
			for (int k = 0; k < combinaisons.size(); k++)
			{
				plateau_.ajouterCombinaison(combinaisons[k]);
			}
			joueurs_[numJoueur_].setMain(main);
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
				for (int j = 0; j < combinaisons.size(); j++)
				{

					plateau_.ajouterCombinaison(combinaisons[j]);
				}
				joueurs_[numJoueur_].setMain(main);
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
	cout << "Choisissez la combinaison a modifier : " << endl;
	cin >> id;
	string choix = "0";
	do
	{
		cout << "Que voulez vous faire ?";
		cout << "1. Rajouter une carte a l'avant";
		cout << "2. Rajouter une carte a l'arriere";
		if (plateau_.getCombinaison(id).hasJoker())
		{
			cout << "3. Remplacer le joker";
			cout << "4. Annuler";
		}
		else {
			cout << "3. Annuler";
		}
		getline(cin, choix);
	} while (!(choix == "1" || choix == "2" || choix == "3" || (choix == "4" && plateau_.getCombinaison(id).hasJoker())));

}

void Jeu::afficherRegles() {
	cout << "Voici les regles et le fonctionnement de ce jeu. " << endl;
	cout << " Chaque joueur dispose de 7 cartes. Vous devez poser des combinaions de cartes (brelan, carre, suite)" << endl;
	cout << "Le premier qui pose toutes ses cartes gagne la manche" << endl;
	cout << "Bonne chance " << endl;
	cout << " Appuyez sur une touche pour commencer la partie" << endl;
	system("PAUSE");
	system("CLS");
}


void Jeu::sauverJeu() {
	string baseDir = "Rami";
	ofstream ofile(od.getFullName(baseDir + '/' + nom_ + ".txt"));

	// Sauvegarde de jeu
	ofile << "JEU" << endl;
	ofile << nom_ << endl;
	ofile << nbJoueurs_ << endl;
	ofile << manche_ << endl;
	ofile << numJoueur_ << endl;


	// Sauver les joueurs
	for (int i = 0; i < joueurs_.size(); i++) {
		if (i == 0) { ofile << "J1" << endl; }
		if (i == 1) { ofile << "J2" << endl; }
		ofile << joueurs_[i].getNom() << endl;
		ofile << joueurs_[i].getId() << endl;
		ofile << joueurs_[i].getScore() << endl;
		ofile << joueurs_[i].getNombreCarte() << endl;
	}

	// Sauvegarde de la pioche
	ofile << "PIOCHE" << endl;
	ofile << pioche_.getTaillePioche() << endl;
	for (int i = 0; i < pioche_.getTaillePioche(); i++) {
		ofile << pioche_.getPioche()[i].getValeur() << endl;
		ofile << pioche_.getPioche()[i].getCouleur() << endl;

	}

	// Sauvegarde de la defausse
	ofile << "DEFAUSSE" << endl;
	ofile << pioche_.getTailleDefausse() << endl;
	for (int i = 0; i < pioche_.getTailleDefausse(); i++) {
		ofile << pioche_.getDefausse()[i].getValeur() << endl;
		ofile << pioche_.getDefausse()[i].getCouleur() << endl;

	}

	// Sauvegarde du plateau
	ofile << "PLATEAU" << endl;
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
	od.refresh(baseDir);
}


void Jeu::chargerJeu() {
	string baseDir = "Rami";
	ifstream ifile(od.getFullName(baseDir + '/' + nom_ + ".txt"));
	string buffer;
	if (ifile.good()) {
		// Charger le jeu
		ifile >> buffer;
		if (buffer == "JEU") {
			ifile >> nom_;
			ifile >> nbJoueurs_;
			ifile >> buffer;
			ifile >> buffer;
		}

		// Charger les joueurs
		for (int i = 0; i < joueurs_.size(); i++) {
			ifile >> buffer;
			if ((buffer == "J1" && i == 0) || (buffer == "J2" && i == 1)) {
				ifile >> buffer;
				joueurs_[i].setNom(buffer);
				ifile >> buffer;
				joueurs_[i].setId(buffer);
				ifile >> buffer;
				joueurs_[i].setScore(stoi(buffer));
				ifile >> buffer;
				joueurs_[i].setNombreCarte(stoi(buffer));
			}
		}

		// Charger la pioche
		ifile >> buffer;
		if (buffer == "PIOCHE") {
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

		// Charger la defausse
		ifile >> buffer;
		if (buffer == "DEFAUSSE") {
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

		// Charger le plateau
		ifile >> buffer;
		if (buffer == "PIOCHE") {
			int nb;
			ifile >> nb;
			plateau_.setNombreCombinaison(nb);
			string valeur = " ";
			string couleur = " ";
			int i = 0;
			vector<Combinaison> combinaisons;
			while (i < nb) {
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
	}
	ifile.close();
}

void Jeu::abandonner() {
	nbJoueurs_--;
	sauverJeu();
	cout << "__________________" << endl;
	cout << "FIN DE LA PARTIE" << endl;
	cout << " Abandon d'un des joueurs" << endl;
}

void Jeu::exec() {
	afficherBootScreen();
	afficherRegles();
	demarrerPartie();
	while (nbJoueurs_ == 2) {
		while (joueurs_[0].getNombreCarte() != 0 && joueurs_[1].getNombreCarte() != 0 && nbJoueurs_ == 2) {
			effectuerTour();
		}
		// Nouvelle pioche
		// Redistribuer carte
	}
}
Jeu::~Jeu()
{
	od.delFile("Rami/" + nom_ + ".txt");
}
