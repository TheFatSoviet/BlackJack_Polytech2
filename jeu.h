#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <fstream>
#include <vector>
#include "joueur.h"

using namespace std;

class jeu
{
public:
    char Nombre_Joueurs_char = 2;
    int Nombre_Joueurs = 0;
    int N_Manche_Actuelle=0;
    int N_Manche_Total;

    //jeu(char nb_joueur_char, int nb_joueur);
    int def_nb_joueur();
    int Calcule_Score(const vector<string>& cartes);
};


#endif
