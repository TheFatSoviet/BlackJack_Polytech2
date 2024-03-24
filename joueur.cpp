#include <cstring> // Pour les fonctions de manipulation de chaînes de caractères comme strcpy et strncpy.
#include <iostream> // Pour l'entrée/sortie, notamment std::cerr.
#include "joueur.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
// Définition du constructeur de la classe Joueur.
// joueur :: joueur() : nom('\0'),type_joueur('\0'),score_in_game(0),nb_partie_joue(0),jeton_disponible(0),jeton_mise(0),cartes{
//     // nom[0] = '\0'; // Initialise le nom du joueur avec une chaîne vide.
//     // type_joueur[0] = '\0'; // Initialise le type du joueur avec une chaîne vide.
//     // score_in_game = 0; // Initialise le score du joueur à 0 pour le début de la partie.
//     // nb_partie_joue = 0; // Initialise le nombre de parties jouées à 0.
//     // jeton_disponible = 0; // Initialise le nombre de jetons possédés à 0.
//     // jeton_mise = 0; // Initialise le nombre de jetons misés à 0.
//     // std::vector<std::string> cartes; // Crée un vecteur pour stocker les cartes, mais cette ligne ne fait rien et devrait être retirée ou modifiée.
// }:

// Méthode pour définir le type de joueur.
void joueur::setTypeJoueur(int i)
{
  string type;
  bool typeValide;
  do {
    cout << "Entrez le type pour le joueur " << i << " (humain, ret3, rand1, tir16, magic): ";
    getline(std::cin, type);
    typeValide = type == "humain" || type == "ret3" || type == "rand1" || type == "tir16" || type == "magic";
    if (!typeValide) {
      std::cout << "Type invalide. Veuillez réessayer." << std::endl;
    }
  } while (!typeValide); // Répéter jusqu'à obtenir un type valide
    strncpy(type_joueur, type.c_str(), sizeof(type_joueur) - 1);
    type_joueur[sizeof(type_joueur) - 1] = '\0';
}


string joueur::set_nom(vector<joueur>& joueurs,int i)
{
  string nomTemp;
  bool nomUnique;

  do {
    nomUnique = true; // On suppose initialement que le nom est unique

    cout << "Entrez le nom pour le joueur " << i << ": ";
    getline(std::cin, nomTemp);

    // Vérifier si le nom est trop long et le tronquer si nécessaire
    if (nomTemp.length() >= sizeof(joueurs[i].nom)) {
      cerr << "Erreur : le nom est trop long. Il sera tronque." << endl;
      nomTemp.resize(sizeof(joueurs[i].nom) - 1);
    }

    // Vérifier si le nom est unique par rapport à tous les noms déjà entrés
    for (int j = 1; j < i; ++j) {
      if (nomTemp == joueurs[j].nom) {
        cerr << "Erreur : ce nom est déjà pris. Veuillez en choisir un autre." << endl;
        nomUnique = false; // Le nom n'est pas unique, demande un autre nom
        break; // Pas besoin de continuer à vérifier les autres noms
      }
    }
  } while (!nomUnique); // Répéter tant que le nom n'est pas unique

  return nomTemp;
}


int joueur::calcul_gain(int score_j,int score_c,int jeton, int mise)
  {

    if (score_j<21)
    {
        if(score_c<score_j || score_c>21)
        {
          jeton=jeton+mise;
        }
        if(score_c>score_j  && score_c<=21)
        {
          jeton=jeton-mise;
        }
    }
    else
    {
      if(score_j==21)
      {
        if(score_c==21)
        {
          jeton=jeton+mise;
        }
        else //jeton_c != 21
        {
          jeton=jeton+(3*mise)/2;
        }
      }
      else //score_j > 21
      {
        jeton=jeton-mise;
      }
    }


    return jeton;
}

void joueur::Afficher_Cartes_Joueur(const joueur& joueur, size_t numeroDuJoueur)
{
    cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") (" << joueur.type_joueur
              << ") a les cartes: ";

    if (numeroDuJoueur == 0)
    {
        // Affiche la première carte normalement, les autres en tant que "X"
        bool premiereCarteAffichee = false;
        for (const auto& carte : joueur.cartes)
        {
            if (!premiereCarteAffichee)
            {
                cout << carte << " "; // Affiche la première carte
                premiereCarteAffichee = true;
            }
            else
            {
                cout << "# "; // Remplace les autres cartes par "X"
            }
        }
    }
    else
    {
        // Pour les autres joueurs, affiche toutes les cartes normalement
        for (const auto& carte : joueur.cartes)
        {
            cout << carte << " ";
        }
    }

    cout <<endl;
}


int joueur::set_mise(vector<joueur>& joueurs,int i)
{
  int tampon;

  if (strcmp(joueurs[i].type_joueur, "humain") != 0) { // Si le joueur n'est pas humain
    // Assigner une mise aléatoire entre 10 et 100
    tampon = rand() % 91 + 10; // % 91 assure une plage de 0-90, + 10 décale à 10-100
  } else {
    // Demander la mise pour les joueurs humains
    do {
      cout << "Joueur " << joueurs[i].nom << ", entrez votre mise (entre 10 et 100 jetons) : ";
      cin >> tampon;
      if (tampon < 10 || tampon > 100) {
        cout << "Mise non valide. Veuillez miser entre 10 et 100 jetons." << endl;
      }
    } while (tampon < 10 || tampon > 100);
  }
  return tampon;
}

void joueur::Afficher_donner_joueur(){
      cout << "," << nom << "," << nb_partie_joue << ',' << jeton_disponible << std::endl;
}
