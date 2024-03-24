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
bool joueur::setTypeJoueur(const string type)
{
  bool typeValide;
  typeValide = type == "humain" || type == "ret3" || type == "rand1" || type == "tir16" || type == "magic";
  if (!typeValide) {
    std::cout << "Type invalide. Veuillez réessayer." << std::endl;
    return false;
  }
  else{
    strncpy(type_joueur, type.c_str(), sizeof(type_joueur) - 1);
    type_joueur[sizeof(type_joueur) - 1] = '\0'; // Assure que la chaîne est terminée par un '\0'
    return true;
  }
}


// Méthode pour définir ou changer le nom du joueur.
void joueur::def_nom_joueur(const string nouveau_nom)
{
  strcpy(nom, nouveau_nom.c_str());
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

void joueur::Afficher_donner_joueur(){
      cout << "," << nom << "," << nb_partie_joue << ',' << jeton_disponible << std::endl;
}
