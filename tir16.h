#ifndef TIR16_H
#define TIR16_H


#include "joueur.h"
using namespace std;

class tir16  : public joueur
{
public:
    // La méthode pioche_tir16 détermine si une nouvelle carte doit être tirée en fonction du score actuel.
    bool pioche_tir16(int score);
};

#endif
