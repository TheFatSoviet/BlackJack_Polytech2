#ifndef JOUEUR_H
#define JOUEUR_H

#include "jeu.h"

#include <string>
#include <vector>
#include <cstddef>  // Pour size_t


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
    void creation_joueur(const char* nouveau_nom);
    void setTypeJoueur(const char* type);
    void Afficher_Cartes_Joueur(const joueur& joueur, size_t numeroDuJoueur);
    void Afficher_donner_joueur();
};


#endif
