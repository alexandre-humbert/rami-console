#include "Jeu.h"
#include<iostream>
#include "odrive.h"
#include <fstream>

Jeu::Jeu()
{

}

void Jeu::afficherTour()
{
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
    cout <<" Appyer sur une touche pour commencer la partie" << endl;
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
    if (choix == "1")	creerPartie();
    if (choix == "2") rejoindrePartie();
    else demarrerPartie();

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
    sauverJeu(od);

}
void Jeu::rejoindrePartie() {
    system("CLS");
    string baseDir = "Rami";
    string nomPartie;
    cout << "Entrez le nom de la partie :" << endl;
    getline(cin, nomPartie);
    string gameDir = baseDir + '/' + nomPartie;
    ODrive od;
    od.refresh(baseDir);
    if (!od.isDir(gameDir))
    {
        cout << "Cette partie n'existe pas" << endl;
        system("PAUSE");
        rejoindrePartie();
    }
    else {
        chargerJeu(od);
        cout << "Entrez votre nom :" << endl;
        string nomJoueur;
        getline(cin, nomJoueur);
        pioche_.melanger();
        nouveauJoueur(nomJoueur, "j2");
        sauverJeu(od);
    }
}

void Jeu::nouveauJoueur(string nom, string id) {
    joueurs_.push_back(Joueur(nom, id, &pioche_));
}

void Jeu::afficherRegles() {
    cout << "Voici les règles blabla ... " << endl;
    cout << " Appyer sur une touche pour commencer la partie" << endl;
    getchar();
    system("CLS");
}

void Jeu::sauverJeu(ODrive od) {

    string baseDir = "Rami";
    string gameDir = baseDir + '/' + nom_;
    od.refresh(gameDir);

    ofstream ofile(od.getFullName(gameDir + "/jeu.txt"));
    ofile << nom_ << endl;
    ofile << manche_ << endl;
    ofile.close();

    for (int i = 0; i < joueurs_.size(); i++) {
        string fileName = joueurs_[i].getId();
        ofstream ofile(od.getFullName(gameDir + '/' + fileName + ".txt"));
        ofile << joueurs_[i].getNom() << endl;
        ofile << joueurs_[i].getId() << endl;
        ofile << joueurs_[i].getScore() << endl;
        ofile << joueurs_[i].getNombreCarte() << endl;
        ofile.close();
    }

   ofile.open(od.getFullName(gameDir + "/pioche.txt"));
    for (int i = 0; i < pioche_.getTaillePioche(); i++) {
        ofile << pioche_.getPioche()[i].getValeur() << endl;
        ofile << pioche_.getPioche()[i].getCouleur() << endl;
        
    }
    ofile.close();

    ofile.open(od.getFullName(gameDir + "/defausse.txt"));
    for (int i = 0; i < pioche_.getTailleDefausse(); i++) {
        ofile << pioche_.getDefausse()[i].getValeur() << endl;
        ofile << pioche_.getDefausse()[i].getCouleur() << endl;

    }   
    ofile.close();
    od.refresh(gameDir);
}


void Jeu::chargerJeu(ODrive od) {

}

Jeu::~Jeu()
{
}
