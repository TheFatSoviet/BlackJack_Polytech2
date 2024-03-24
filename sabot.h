#ifndef SABOT_H
#define SABOT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

//#include "jeu.h"
#include "joueur.h"

using namespace std;

class sabot : public joueur
{
public:

  int Melange_Cartes(int value);

  void Ranger_Cartes(vector<joueur>& joueurs);

  void Distribuer_Cartes(vector<joueur>& joueurs);

  void Retire_Cartes(joueur& joueur);

void Afficher_Cartes_Joueur(const joueur& joueur, size_t numeroDuJoueur);
};

#endif
