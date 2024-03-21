#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class sabot : public joueur
{
public:

  int Melange_Cartes(char value);

  void Ranger_Cartes(std::vector<Joueur>& joueurs);

  void Distribuer_Cartes(std::vector<Joueur>& joueurs);

  void Retire_Cartes(Joueur& joueur);


};

#endif
