#ifndef magic_H
#define magic_H


#include "joueur.h"
using namespace std;

class magic  : public joueur
{
public:
    // La méthode pioche_tir16 détermine si une nouvelle carte doit être tirée en fonction du score actuel.
    bool pioche_magic(int score);
};

#endif
