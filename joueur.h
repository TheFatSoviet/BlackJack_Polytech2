#ifndef JOUEUR_H
#define JOUEUR_H

#include "jeu.h"

#include <string>
#include <vector>
#include <cstddef>  // Pour size_t
#include <cstring> // Pour les fonctions de manipulation de chaînes de caractères comme strcpy et strncpy.
#include <ctime>

class joueur : public jeu
{
public:
    char nom[20];
    char type_joueur[20];
    int score_in_game;
    int nb_partie_joue;
    int jeton_disponible;
    int jeton_mise;
    vector<string> cartes;

    //joueur();
    bool setTypeJoueur(const string type);
    void Afficher_Cartes_Joueur(const joueur& joueur, size_t numeroDuJoueur);
    void Afficher_donner_joueur();
    string set_nom(vector<joueur>& joueurs,int i);
    int set_mise(vector<joueur>& joueurs,int i);
};


#endif
