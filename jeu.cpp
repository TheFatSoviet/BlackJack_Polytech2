
#include "jeu.h"

//jeu::jeu(char nb_joueur_char, int nb_joueur) : Nombre_Joueurs_char(nb_joueur_char), Nombre_Joueurs(nb_joueur){}

int jeu::def_nb_joueur()
{
  Nombre_Joueurs=0;
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


/*void jeu::BoucleDeJeu(vector<joueur>& joueurs) {
    bool quelquUnDoitPiocher;

    std::cout << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;
    std::cout << "/////////////////    PHASE DE PIOCHE    //////////" << std::endl;
    std::cout << "//////////////////////////////////////////////////" << std::endl;

    do {
        quelquUnDoitPiocher = false; // Indicateur pour vérifier si au moins un joueur doit piocher
        for (Joueur& joueur : joueurs) {
            joueur.score_in_game = Calcule_Score(joueur.cartes);

            // Appliquer la logique de pioche en fonction du type de joueur
            if (strcmp(joueur.type_joueur, "croupier") == 0 && joueur.pioche_croupier(joueur.score_in_game))
            {
                std::cout << "Le croupier " << joueur.nom << " pioche une carte." << std::endl;
                Retire_Cartes(joueur);
                quelquUnDoitPiocher = true;
            }
            else if (strcmp(joueur.type_joueur, "ret3") == 0 && joueur.pioche_ret3(joueur.score_in_game))
            {
                std::cout << joueur.nom << " pioche une carte." << std::endl;
                Retire_Cartes(joueur);
                quelquUnDoitPiocher = true;
            }
            else if (strcmp(joueur.type_joueur, "tir16") == 0 && joueur.pioche_tir16(joueur.score_in_game))  //joueurs[0].pioche_tir16(joueurs[0].score_in_game)
            {
                std::cout << joueur.nom << " pioche une carte." << std::endl;
                Retire_Cartes(joueur);
                quelquUnDoitPiocher = true;
            }
            else if (strcmp(joueur.type_joueur, "humain") == 0 && joueur.pioche_humain(joueur.score_in_game))
            {
                std::cout << joueur.nom << " pioche une carte." << std::endl;
                Retire_Cartes(joueur);
                quelquUnDoitPiocher = true;
            }
            else if (strcmp(joueur.type_joueur, "rand1") == 0 && joueur.pioche_rand1())
            {
                std::cout << joueur.nom << " pioche une carte." << std::endl;
                Retire_Cartes(joueur);
                quelquUnDoitPiocher = true;                       // PROBLEM ON BOCULE SIMULTANEMENT JOUEUR (plusieurs jourus) DANS LKES IF RESPECTIFSD
            }
            // Ajoutez ici d'autres conditions pour les autres types de joueurs
            // ...

            // Recalculer le score après chaque pioche


            joueur.score_in_game = Calcule_Score(joueur.cartes);
        }

        // Si au moins un joueur a pioché, tous les scores sont recalculés et affichés
        if (quelquUnDoitPiocher)
        {
            for (Joueur& joueur : joueurs)
            {
                std::cout << ">--------------- Le joueur " << joueur.nom << " a un score de : " << joueur.score_in_game << std::endl;
            }
        }

    }
    while (quelquUnDoitPiocher); // Continuer tant qu'au moins un joueur doit piocher
}*/
// void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur)
// {
//     std::cout << "Joueur " << numeroDuJoueur << " (" << joueur.nom << ") (" << joueur.type_joueur
//               << ") a les cartes: ";
//
//     if (numeroDuJoueur == 0)
//     {
//         // Affiche la première carte normalement, les autres en tant que "X"
//         bool premiereCarteAffichee = false;
//         for (const auto& carte : joueur.cartes)
//         {
//             if (!premiereCarteAffichee)
//             {
//                 std::cout << carte << " "; // Affiche la première carte
//                 premiereCarteAffichee = true;
//             }
//             else
//             {
//                 std::cout << "X "; // Remplace les autres cartes par "X"
//             }
//         }
//     }
//     else
//     {
//         // Pour les autres joueurs, affiche toutes les cartes normalement
//         for (const auto& carte : joueur.cartes)
//         {
//             std::cout << carte << " ";
//         }
//     }
//
//     std::cout << std::endl;
// }
