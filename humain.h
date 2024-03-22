#ifndef HUMAIN_H
#define HUMAIN_H


#include <iostream>
#include <stdlib.h>

#include "Joueur.h"

using namespace std;


class humain : public joueur
{
public:
    // Méthode pour demander à l'utilisateur s'il souhaite tirer une carte.
    bool pioche_humain(int score);

};

#endif
