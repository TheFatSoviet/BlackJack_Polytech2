//Ruben SARGSYAN
//commentaires générer par ia
#include "joueur.cpp"
#include "rand.cpp"
#include "ret3.cpp"
#include "tir16.cpp"
#include "humain.cpp"
#include "sabot.cpp"
#include "jeu.cpp"


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring> // Pour les fonctions de manipulation de chaînes de caractères comme strcpy et strncpy.


// void Retire_Cartes(Joueur& joueur) {
//     std::ifstream fileIn("Sabot.txt");
//     std::string contenu, carte;
//     std::vector<std::string> cartes;
//
//     if (fileIn.is_open()) {
//         getline(fileIn, contenu); // Lit toute la ligne du fichier Sabot.txt.
//         fileIn.close();
//
//         std::stringstream ss(contenu);
//
//         // Lire toutes les cartes dans le vecteur.
//         while (std::getline(ss, carte, ',')) {
//             if (!carte.empty()) { // Vérifier que la chaîne n'est pas vide.
//                 cartes.push_back(carte);
//             }
//         }
//
//         if (!cartes.empty()) {
//             // Attribuer la première carte au joueur et la retirer du vecteur des cartes.
//             joueur.cartes.push_back(cartes[0]);
//             cartes.erase(cartes.begin());
//
//             // Mettre à jour le fichier Sabot.txt avec les cartes restantes.
//             std::ofstream fileOut("Sabot.txt");
//             if (fileOut.is_open()) {
//                 for (size_t i = 0; i < cartes.size(); ++i)
//                 {
//                     fileOut << cartes[i];
//                     if (i != cartes.size() - 1)
//                     {
//                         fileOut << ",";
//                     }
//                 }
//                 fileOut.close();
//             }
//             else
//             {
//                 std::cerr << "Erreur lors de la réouverture du fichier pour écriture." << std::endl;
//             }
//         } else {
//             std::cerr << "Pas de cartes disponibles pour retirer." << std::endl;
//         }
//     } else {
//         std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
//     }
// }
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// void BoucleDeJeu(std::vector<Joueur>& joueurs) {
//     bool quelquUnDoitPiocher;
//
//     std::cout << std::endl;
//     std::cout << "//////////////////////////////////////////////////" << std::endl;
//     std::cout << "/////////////////    PHASE DE PIOCHE    //////////" << std::endl;
//     std::cout << "//////////////////////////////////////////////////" << std::endl;
//
//     do {
//         quelquUnDoitPiocher = false; // Indicateur pour vérifier si au moins un joueur doit piocher
//         for (Joueur& joueur : joueurs) {
//             joueur.score_in_game = Calcule_Score(joueur.cartes);
//
//             // Appliquer la logique de pioche en fonction du type de joueur
//             if (strcmp(joueur.type_joueur, "croupier") == 0 && joueur.pioche_croupier(joueur.score_in_game))
//             {
//                 std::cout << "Le croupier " << joueur.nom << " pioche une carte." << std::endl;
//                 Retire_Cartes(joueur);
//                 quelquUnDoitPiocher = true;
//             }
//             else if (strcmp(joueur.type_joueur, "ret3") == 0 && joueur.pioche_ret3(joueur.score_in_game))
//             {
//                 std::cout << joueur.nom << " pioche une carte." << std::endl;
//                 Retire_Cartes(joueur);
//                 quelquUnDoitPiocher = true;
//             }
//             else if (strcmp(joueur.type_joueur, "tir16") == 0 && joueur.pioche_tir16(joueur.score_in_game))  //joueurs[0].pioche_tir16(joueurs[0].score_in_game)
//             {
//                 std::cout << joueur.nom << " pioche une carte." << std::endl;
//                 Retire_Cartes(joueur);
//                 quelquUnDoitPiocher = true;
//             }
//             else if (strcmp(joueur.type_joueur, "humain") == 0 && joueur.pioche_humain(joueur.score_in_game))
//             {
//                 std::cout << joueur.nom << " pioche une carte." << std::endl;
//                 Retire_Cartes(joueur);
//                 quelquUnDoitPiocher = true;
//             }
//             else if (strcmp(joueur.type_joueur, "rand1") == 0 && joueur.pioche_rand1())
//             {
//                 std::cout << joueur.nom << " pioche une carte." << std::endl;
//                 Retire_Cartes(joueur);
//                 quelquUnDoitPiocher = true;                       // PROBLEM ON BOCULE SIMULTANEMENT JOUEUR (plusieurs jourus) DANS LKES IF RESPECTIFSD
//             }
//             // Ajoutez ici d'autres conditions pour les autres types de joueurs
//             // ...
//
//             // Recalculer le score après chaque pioche
//
//
//             joueur.score_in_game = Calcule_Score(joueur.cartes);
//         }
//
//         // Si au moins un joueur a pioché, tous les scores sont recalculés et affichés
//         if (quelquUnDoitPiocher)
//         {
//             for (Joueur& joueur : joueurs)
//             {
//                 std::cout << ">--------------- Le joueur " << joueur.nom << " a un score de : " << joueur.score_in_game << std::endl;
//             }
//         }
//
//     }
//     while (quelquUnDoitPiocher); // Continuer tant qu'au moins un joueur doit piocher
// }




























// Le point d'entrée principal du programme.
int main()
{
   // Vecteur pour conserver les joueurs, y compris le dealer.
   vector<joueur> joueurs;

   //element class sabot
   jeu blackjack;
   sabot deck;

   blackjack.Nombre_Joueurs=blackjack.def_nb_joueur();

   // Appel de la fonction de mélange des cartes.
   deck.Melange_Cartes(blackjack.Nombre_Joueurs);


   // Initialisation des joueurs, y compris le dealer.
  joueurs.resize(blackjack.Nombre_Joueurs + 1);

  // Définition du nom du Croupier.
  strcpy(joueurs[0].nom, "Croupier");
  strcpy(joueurs[0].type_joueur, "croupier");


  //Boucle pour obtenir et définir les noms des joueurs.
  for (int i = 1; i <= blackjack.Nombre_Joueurs; ++i) {
    std::string nomTemp;
    bool nomUnique;

    do {
      nomUnique = true; // On suppose initialement que le nom est unique
      cout << "Entrez le nom pour le joueur " << i << ": ";
      getline(std::cin, nomTemp);

      // Vérifier si le nom est trop long et le tronquer si nécessaire
      if (nomTemp.length() >= sizeof(joueurs[i].nom)) {
        cerr << "Erreur : le nom est trop long. Il sera tronque." << std::endl;
        nomTemp.resize(sizeof(joueurs[i].nom) - 1);
      }

      // Vérifier si le nom est unique par rapport à tous les noms déjà entrés
      for (int j = 1; j < i; ++j) {
        if (nomTemp == joueurs[j].nom) {
          cerr << "Erreur : ce nom est déjà pris. Veuillez en choisir un autre." << std::endl;
          nomUnique = false; // Le nom n'est pas unique, demande un autre nom
          break; // Pas besoin de continuer à vérifier les autres noms
        }
      }
    } while (!nomUnique); // Répéter tant que le nom n'est pas unique

    // Une fois un nom unique obtenu, l'assigner au joueur
    joueurs[i].def_nom_joueur(nomTemp);
  }


  // Après avoir défini les types des joueurs
  for (int i = 1; i <= blackjack.Nombre_Joueurs; ++i) { // Exclure le croupier de la saisie
    string typeTemp;
    bool Valide;

    do {
      cout << "Entrez le type pour le joueur " << i << " (humain, ret3, rand1, tir16, magic): ";
      getline(std::cin, typeTemp);
      Valide = joueurs[i].setTypeJoueur(typeTemp);
    } while (!Valide); // Répéter jusqu'à obtenir un type valide
  }







 // Distribution des cartes
 deck.Distribuer_Cartes(joueurs);

 // Affichage des cartes du dealer
 //joueurs[0].Afficher_Cartes_Joueur(joueurs[0], 0);

 //Affichage des cartes de tous les joueurs, y compris le dealer
 for (size_t i = 0; i < joueurs.size(); ++i)
 {
     joueurs[i].Afficher_Cartes_Joueur(joueurs[i], i);
 }




  //joueurs[0].score_in_game = 10 ;
//----------------------------------------------------------------------------------------------------------------------------
  // joueurs[0].score_in_game = Calcule_Score(joueurs[0].cartes);
  //
  //
  // if (joueurs[0].pioche_tir16(joueurs[0].score_in_game))
  // {
  //     std::cout << "Le dealer " << joueurs[0].nom << " pioche une carte." << std::endl;
  //     Retire_Cartes(joueurs[0]);
  // }
  // else {
  //     std::cout << "Le dealer " << joueurs[0].nom << " ne pioche pas." << std::endl;
  // }
  //
  //
  //
  // // Affichage des cartes de tous les joueurs, y compris le dealer
  // for (size_t i = 0; i < joueurs.size(); ++i)
  // {
  //     Afficher_Cartes_Joueur(joueurs[i], i);
  // }
//----------------------------------------------------------------------------------------------------------------------------


//BoucleDeJeu(joueurs);

//ici faut :
// une boucle pour : calculer score
// mais en mm temps si ya une pioche faut encore calculer le score du joeur qui pioche
// en plus mettre en place les types


  // for (size_t i = 0; i < joueurs.size(); ++i)
  // {
  //       joueurs[i].score_in_game = Calcule_Score(joueurs[i].cartes);
  //
  //
  //
  //       if (joueurs[0].pioche_croupier(joueurs[0].score_in_game))
  //       {
  //           std::cout << "Le dealer " << joueurs[0].nom << " pioche une carte." << std::endl;
  //           Retire_Cartes(joueurs[0]);
  //           joueurs[0].score_in_game = Calcule_Score(joueurs[0].cartes);
  //
  //       }
  //       else {
  //           std::cout << "Le dealer " << joueurs[0].nom << " ne pioche pas." << std::endl;
  //       }
  //
  //
  //       //std::cout << "Le joueur " << joueurs[i].nom << "a :" << joueurs[i].score_in_game << std::endl;
  // }





























//
// //score
//   for (size_t i = 0; i < joueurs.size(); ++i)
//   {
//         std::cout << "Le joueur " << joueurs[i].nom << " a :" << joueurs[i].score_in_game << std::endl;
//   }




















  // Après toutes les manipulations des cartes
    //  Ranger_Cartes(joueurs);



//  int NB_Cartes_a_retirer;
//    std::cout << "Entrez le nombre de cartes a retirer : ";
//    std::cin >> NB_Cartes_a_retirer;

    // Exemple d'utilisation de la fonction RetireCartes
//    Retire_Cartes(NB_Cartes_a_retirer);


//    std::vector<std::string> cartes_a_ajouter = {"1", "2", "3"};
//    Rajout_Cartes(cartes_a_ajouter);

////////////////////////////////////////////////////////////

  //  std::vector<std::string> cartes = {"1", "5","8"};

    // Calcul du score pour cet ensemble de cartes
//    int score = Calcule_Score(cartes);

    // Affichage du score
  //  std::cout << "Le score est: " << score << std::endl;



    return 0;
}
