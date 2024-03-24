//Ruben SARGSYAN
//commentaires générer par ia
#include "joueur.cpp"
#include "rand.cpp"
#include "ret3.cpp"
#include "tir16.cpp"
#include "humain.cpp"
#include "sabot.cpp"
#include "jeu.cpp"
#include "croupier.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring> // Pour les fonctions de manipulation de chaînes de caractères comme strcpy et strncpy.


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

  // Boucle pour obtenir et définir les noms des joueurs.
  for (int i = 1; i <= blackjack.Nombre_Joueurs; ++i) {
    // Une fois un nom unique obtenu, l'assigner au joueur
    strcpy(joueurs[i].nom, joueurs[i].set_nom(joueurs,i).c_str());
  }

  // Après avoir défini les types des joueurs
  for (int i = 1; i <= blackjack.Nombre_Joueurs; ++i){ // Exclure le croupier de la saisie
    joueurs[i].setTypeJoueur(i);
  }




  // Initialiser les jetons pour tous les joueurs
    for (int i = 0; i <= blackjack.Nombre_Joueurs; ++i) { // Commence à 0 pour inclure le croupier
      if (i == 0) { // Le croupier est le joueur à l'indice 0
        joueurs[i].jeton_disponible = 100000000; // 100 millions pour le croupier
      } else {
        joueurs[i].jeton_disponible = 1000; // 1000 jetons pour les joueurs
      }
    }

    cout << "Combien de manche voulez-vous jouer ? : ";
    cin >> blackjack.N_Manche_Total;

    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    while (blackjack.N_Manche_Actuelle < blackjack.N_Manche_Total) {
      blackjack.N_Manche_Actuelle++;

      cout << std::endl;
      cout << "//////////////////////////////////////////////////" << endl;
      cout << "/////////////////    DEBUT ROUND " << blackjack.N_Manche_Actuelle << "////////////" << endl;
      cout << "//////////////////////////////////////////////////" << endl;
      cout << std::endl;

      deck.verifierSabot(blackjack.Nombre_Joueurs);

      cout << std::endl;
      cout << "//////////////////////////////////////////////////" << endl;
      cout << "/////////////////    PHASE DE MISE    ////////////" << endl;
      cout << "//////////////////////////////////////////////////" << endl;
      cout << endl;

      for (size_t i = 1; i < joueurs.size(); ++i) {
        const auto & joueur = joueurs[i];
        cout << "Joueur " << joueur.nom << " possède " << joueur.jeton_disponible << " jetons." << endl;
      }

      cout << endl;

      for (size_t i = 1; i < joueurs.size(); ++i) {
              const auto & joueur = joueurs[i];
              cout << "Joueur " << joueur.nom << " possède " << joueur.jeton_disponible << " jetons." << endl;
            }

            cout << endl;

            srand(static_cast < unsigned int > (time(nullptr)));

            for (size_t i = 1; i < joueurs.size(); ++i) { // Commence à 1 pour exclure le croupier
              joueurs[i].jeton_mise=joueurs[i].set_mise(joueurs,i);
            }

            // Afficher la mise de tous les joueurs (sauf le croupier)
            for (size_t i = 1; i < joueurs.size(); ++i) {
              cout << "Joueur " << joueurs[i].nom << " a mise " << joueurs[i].jeton_mise << " jetons." << endl;
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



 // Distribution des cartes
 deck.Distribuer_Cartes(joueurs);

 // Affichage des cartes du dealer
 //joueurs[0].Afficher_Cartes_Joueur(joueurs[0], 0);

 //Affichage des cartes de tous les joueurs, y compris le dealer
 for (size_t i = 0; i < joueurs.size(); ++i)
 {
     joueurs[i].Afficher_Cartes_Joueur(joueurs[i], i);
 }

 for (size_t i = 0; i < joueurs.size(); ++i)
 {
     joueurs[i].score_in_game = blackjack.Calcule_Score(joueurs[i].cartes);
     cout << "Le joueurs " << i << "a un score de : " << joueurs[i].score_in_game << endl;
 }





//BoucleDeJeu(joueurs);



        cout << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << "/////////////////    SCORE FINALE     ////////////" << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << endl;

        //score
        for (size_t i = 0; i < joueurs.size(); ++i) {
          std::cout << "Le joueur " << joueurs[i].nom << " a :" << joueurs[i].score_in_game << std::endl;
        }

        cout << std::endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << "/////////////////    PHASE DE GAIN    ////////////" << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << endl;



        for (size_t i = 1; i < joueurs.size(); ++i) {
          int nouveauTotalJetons =joueurs[i].calcul_gain(joueurs[i].score_in_game, joueurs[0].score_in_game, joueurs[i].jeton_disponible, joueurs[i].jeton_mise);

          // Imprimez le résultat et mettez à jour les jetons du joueur
          if (nouveauTotalJetons > joueurs[i].jeton_disponible) {
            cout << "Joueur " << joueurs[i].nom << " gagne " << (nouveauTotalJetons - joueurs[i].jeton_disponible) << " jetons." << endl;
          } else if (nouveauTotalJetons < joueurs[i].jeton_disponible) {
            cout << "Joueur " << joueurs[i].nom << " perd " << (joueurs[i].jeton_disponible - nouveauTotalJetons) << " jetons." << endl;
          } else {
            cout << "Joueur " << joueurs[i].nom << " ne gagne ni ne perd des jetons." << endl;
          }

          joueurs[i].jeton_disponible = nouveauTotalJetons; // Mettre à jour les jetons du joueur
        }

        cout << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << "/////////////////    INFO JETONS      ////////////" << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << endl;

        for (size_t i = 1; i < joueurs.size(); ++i) {
          const auto & joueur = joueurs[i];
          cout << "Joueur " << joueur.nom << " possède " << joueur.jeton_disponible << " jetons." << endl;
        }

        // Après toutes les manipulations des cartes

        cout << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << "/////////////////    FIN DE ROUND " << blackjack.N_Manche_Actuelle << "    ////////////" << endl;
        cout << "//////////////////////////////////////////////////" << endl;
        cout << endl;

        // // Reset le choix de l'humain de ne plus piocher de carte
        // for (auto & joueur: joueurs) {
        //   if (auto h = dynamic_cast < humain * > ( & joueur)) {
        //     h -> flag_repondu_non = 0; // Réinitialiser le flag pour le joueur humain
        //   }
        // }

        deck.Ranger_Cartes(joueurs);

      }

    return 0;
}
