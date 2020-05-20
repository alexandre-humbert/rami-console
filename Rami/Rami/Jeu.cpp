#include "Jeu.h"
#include<iostream>


Jeu::Jeu()
{
}

void Jeu::initialiserTour()
{
}

void Jeu::effectuerTour()
{
}

void Jeu::afficherBootScreen() {
    cout << "            _____" << endl;
    cout << "           |A .  | _____" << endl;
    cout << "           | /.\ ||A ^  | _____" << endl;
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
    cout << "C'est partie !!!";


}

Jeu::~Jeu()
{
}
