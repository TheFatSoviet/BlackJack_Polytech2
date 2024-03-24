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
#include <map>

#include "jeu.h"
#include "joueur.h"

using namespace std;

class sabot : public joueur
{
public:

  int Melange_Cartes(int value);

  void Distribuer_Cartes(vector<joueur>& joueurs);

  void verifierSabot(int nombreDeJoueurs);

};

#endif
