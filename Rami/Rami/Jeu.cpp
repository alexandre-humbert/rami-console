#include "Jeu.h"
#include<iostream>
#include "odrive.h"
#include <fstream>

Jeu::Jeu()
{

}

void Jeu::afficherTour()
{
    system("CLS");
    cout << "Bonjour " << joueurs_[numJoueur_].getNom() << endl;
    system("PAUSE");
}

void Jeu::effectuerTour()
{
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
    cout <<" Appuyez sur une touche pour commencer la partie" << endl;
    getchar();
    system("CLS");


}
void Jeu::demarrerPartie() {
    system("CLS");
    cout << "Que voulez-vous faire :" << endl;
    cout << "1. Créer une nouvelle partie" << endl;
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
    ODrive od;
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
    sauverJeu(od);
    while (nbJoueurs_ != 2) {
        od.waitForChange(gameDir + "/jeu.txt");
        chargerJeu(od);
    }
    do
    {   od.sync(gameDir + "/j2.txt");
        od.sync(gameDir);
        od.refresh(gameDir);
    }
    while (!ifstream(od.getFullName(gameDir + "/j2.txt")).good());
}


void Jeu::rejoindrePartie() {
    system("CLS");
    string baseDir = "Rami";
    string nomPartie;
    ODrive od;
    cout << "Entrez le nom de la partie :" << endl;
    getline(cin, nomPartie);
    string gameDir = baseDir + '/' + nomPartie;
    od.mkDir(gameDir);

    od.sync(gameDir);
    od.sync(gameDir + "/jeu.txt");
    od.sync(gameDir + "/j1.txt");
    od.sync(gameDir + "/pioche.txt");
    od.sync(gameDir + "/defausse.txt");
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
        chargerJeu(od);
        cout << "Entrez votre nom :" << endl;
        string nomJoueur;
        getline(cin, nomJoueur);
        pioche_.melanger();
        nouveauJoueur(nomJoueur, "j2");
        numJoueur_ = 1;
        sauverJeu(od);
    }
}

void Jeu::nouveauJoueur(string nom, string id) {
    joueurs_.push_back(Joueur(nom, id, &pioche_));
    nbJoueurs_++;
}

void Jeu::afficherRegles() {
    cout << "Voici les règles et le fonctioonnement de ce jeu. " << endl;
    cout << " Chaque joueur dispose de 7 cartes. Vous devez poser des combinaions de cartes (brelan, carre, suite)" << endl;
    cout << "Le premier qui pose toutes ses cartes gagne la manche" << endl;
    cout << "Bonne chance " << endl;
    cout << " Appuyez sur une touche pour commencer la partie" << endl;
    getchar();
    system("CLS");
}

void Jeu::sauverJeu(ODrive od) {

    string baseDir = "Rami";
    string gameDir = baseDir + '/' + nom_;
    od.refresh(gameDir);

    // Sauvegarde de jeu
    ofstream ofile(od.getFullName(gameDir + "/jeu.txt"));
    ofile << nom_ << endl;
    ofile << nbJoueurs_ << endl;
    ofile << manche_ << endl;
    ofile.close();

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
   ofile.open(od.getFullName(gameDir + "/pioche.txt"));
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
    od.sync(gameDir);
}


void Jeu::chargerJeu(ODrive od) {
    string baseDir = "Rami";
    string gameDir = baseDir + '/' + nom_;
    od.refresh(gameDir);

    // Charger le jeu
    ifstream ifile(od.getFullName(gameDir + "/jeu.txt"));
    if (ifile.good()) {
        ifile >> nom_;
        ifile >> nbJoueurs_;
        ifile >> manche_;
        ifile.close();
    }
    // Charger les joueurs
    for (int i = 0; i < nbJoueurs_; i++) {
        ifstream ifile(od.getFullName(gameDir + "/j" + to_string(i+1)  + ".txt"));
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
            ifile.close();
        }
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
        ifile.close();
    }

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
        ifile.close();
    }


}

Jeu::~Jeu()
{
    ODrive od;
    od.delFile("Rami/" + nom_ + "/jeu.txt");
    od.delFile("Rami/" + nom_ + "/j1.txt");
    od.delFile("Rami/" + nom_ + "/j2.txt");
    od.delFile("Rami/" + nom_ + "/pioche.txt");
    od.delFile("Rami/" + nom_ + "/defausse.txt");
}
