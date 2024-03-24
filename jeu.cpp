#include "jeu.h"


//jeu::jeu(char nb_joueur_char, int nb_joueur) : Nombre_Joueurs_char(nb_joueur_char), Nombre_Joueurs(nb_joueur){}

int jeu::def_nb_joueur()
{
  int Nombre_Joueurs=0;
  // Boucle pour s'assurer que le nombre de joueurs est dans la plage valide.
  while (Nombre_Joueurs < 1 || Nombre_Joueurs > 7) {
    cout << "Entrez le nombre de joueurs (entre 1 et 7) : ";
    cin >> Nombre_Joueurs;
    cin.ignore(); // Évite les problèmes de buffer en ignorant le retour à la ligne.

    // Vérification de la validité de l'entrée.
    if (Nombre_Joueurs < 1 || Nombre_Joueurs > 7) {
      std::cerr << "Le nombre de joueurs doit etre entre 1 et 7." << std::endl;
      // return 1; // Cette ligne est commentée mais peut être utilisée pour quitter si nécessaire.
    }
  }
  return Nombre_Joueurs;
}

// Fonction pour calculer le score à partir d'un vecteur de chaînes représentant les cartes.
int jeu::Calcule_Score(const vector<string>& cartes)
{
    int score = 0; // Initialisation du score total à 0.
    int nombreAs = 0; // Compteur pour le nombre d'As, car leur valeur peut être 1 ou 11.

    // Parcourir chaque carte dans le vecteur pour assigner les valeurs initiales.
    for (const std::string& carte : cartes)
    {
        if (carte == "D" || carte == "R" || carte == "V" || carte == "X") // Si la carte est un roi, une dame, ou un valet,
        {
            score += 10; // leur valeur est 10.
        }
        else if (carte == "1") // Si la carte est un As,
        {
            ++nombreAs; // incrémenter le compteur d'As sans ajouter de score pour l'instant.
        }
        else if (!carte.empty()) // Pour toutes les autres cartes (en ignorant les cartes vides),
        {
            score += std::stoi(carte); // convertir la valeur de la carte en entier et l'ajouter au score.
        }
    }

    // Après avoir assigné les valeurs initiales, traiter les As.
    for (int i = 0; i < nombreAs; ++i)
    {
        // Pour chaque As, décider de sa valeur pour maximiser le score sans dépasser 21.
        if (score + 11 > 21) // Si ajouter 11 dépasse 21,
        {
            score += 1; // l'As vaut 1.
        }
        else
        {
            score += 11; // Sinon, l'As vaut 11.
        }
    }

    return score; // Retourner le score total calculé.
}
