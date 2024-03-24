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
#include "magic.cpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstring> // Pour les fonctions de manipulation de chaînes de caractères comme strcpy et strncpy.

void BoucleDeJeu(vector < joueur > & joueurs, jeu blackjack);
void Ranger_Cartes(std::vector<joueur>& joueurs);
void Retire_Cartes(joueur & joueur);

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
        cout << "Joueur " << joueur.nom << " possede " << joueur.jeton_disponible << " jetons." << endl;
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


           BoucleDeJeu(joueurs,blackjack);


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
          cout << "Joueur " << joueur.nom << " possede " << joueur.jeton_disponible << " jetons." << endl;
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

       Ranger_Cartes(joueurs);


       //creation fichier affiche_resultat

         joueurs[1].affiche_resultat(joueurs, blackjack.N_Manche_Actuelle);


      }

    return 0;
}













void Ranger_Cartes(std::vector<joueur>& joueurs)
{
    // Ouvre le fichier Sabot.txt en mode append pour ajouter du contenu à la fin sans supprimer le contenu existant.
    std::ofstream fileOut("Sabot.txt", std::ios::app);

    // Vérifie si le fichier a été correctement ouvert.
    if (!fileOut.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier pour ajouter." << std::endl;
        return; // Sort de la fonction en cas d'échec de l'ouverture du fichier.
    }

    // Détermine si le fichier est vide pour décider de l'ajout d'une virgule initiale.
    fileOut.seekp(0, std::ios::end); // Se déplace à la fin du fichier.
    if(fileOut.tellp() != 0) { // Si le fichier n'est pas vide (tellp renvoie la position actuelle dans le fichier),
        fileOut << ","; // ajoute une virgule pour séparer les nouveaux éléments des précédents.
    }

    bool isFirstCard = true; // Un drapeau pour gérer l'ajout de virgules entre les cartes.
    // Itérer sur tous les joueurs, en commençant par le joueur 1 (en supposant que le joueur 0 est le dealer et est traité en dernier).
    for (size_t i = 1; i < joueurs.size(); ++i)
    {
        for (const auto& carte : joueurs[i].cartes)
        {
            if (!isFirstCard)
            {
                fileOut << ","; // Ajoute une virgule avant d'ajouter la carte, sauf si c'est la première carte.
            }
            fileOut << carte; // Écrit la carte dans le fichier.
            isFirstCard = false; // Après la première carte, ce drapeau est toujours faux.
        }
    }

    // Ajouter les cartes du dealer en dernier pour conserver l'ordre.
    for (const auto& carte : joueurs[0].cartes)
    {
        if (!isFirstCard) // Si ce n'est pas la première carte à être ajoutée,
        {
            fileOut << ","; // insère une virgule avant la carte.
        }
        fileOut << carte; // Ajoute la carte du dealer au fichier.
        isFirstCard = false; // Assure que la première carte a déjà été traitée.
    }

    fileOut.close(); // Ferme le fichier après avoir terminé l'écriture.

    // Itérer sur tous les joueurs et supprimer leurs cartes
    for (joueur& joueur : joueurs)
    {
      joueur.cartes.clear(); // Vide le vecteur de cartes pour chaque joueur
    }
}

void Retire_Cartes(joueur & joueur) {
  std::ifstream fileIn("Sabot.txt");
  std::string contenu, carte;
  std::vector < std::string > cartes;

  if (fileIn.is_open()) {
    getline(fileIn, contenu); // Lit toute la ligne du fichier Sabot.txt.
    fileIn.close();

    std::stringstream ss(contenu);

    // Lire toutes les cartes dans le vecteur.
    while (std::getline(ss, carte, ',')) {
      if (!carte.empty()) { // Vérifier que la chaîne n'est pas vide.
        cartes.push_back(carte);
      }
    }

    if (!cartes.empty()) {
      // Attribuer la première carte au joueur et la retirer du vecteur des cartes.
      joueur.cartes.push_back(cartes[0]);
      cartes.erase(cartes.begin());

      // Mettre à jour le fichier Sabot.txt avec les cartes restantes.
      std::ofstream fileOut("Sabot.txt");
      if (fileOut.is_open()) {
        for (size_t i = 0; i < cartes.size(); ++i) {
          fileOut << cartes[i];
          if (i != cartes.size() - 1) {
            fileOut << ",";
          }
        }
        fileOut.close();
      } else {
        std::cerr << "Erreur lors de la réouverture du fichier pour écriture." << std::endl;
      }
    } else {
      std::cerr << "Pas de cartes disponibles pour retirer." << std::endl;
    }
  } else {
    std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
  }
}


void BoucleDeJeu(vector < joueur > & joueurs, jeu blackjack) {
  bool quelquUnDoitPiocher;

cout << endl;
cout << "//////////////////////////////////////////////////" << endl;
cout << "/////////////////    PHASE DE PIOCHE    //////////" << endl;
cout << "//////////////////////////////////////////////////" << endl;

do {
  quelquUnDoitPiocher = false; // Indicateur pour vérifier si au moins un joueur doit piocher
  for (joueur & joueur: joueurs) {
      joueur.score_in_game = blackjack.Calcule_Score(joueur.cartes);

    // Appliquer la logique de pioche en fonction du type de joueur
    if (strcmp(joueur.type_joueur, "croupier") == 0 ) {
      croupier test;
      if(test.pioche_croupier(joueur.score_in_game))
        {
          cout << "Le " << joueur.nom << " pioche une carte." << endl;
          Retire_Cartes(joueur);
          quelquUnDoitPiocher = true;
        }
    } else if (strcmp(joueur.type_joueur, "ret3") == 0 ) {
      ret3 test;
      if(test.pioche_ret3(joueur.score_in_game))
        {
      cout << joueur.nom << " pioche une carte." << endl;
      Retire_Cartes(joueur);
      quelquUnDoitPiocher = true;
    }
    } else if (strcmp(joueur.type_joueur, "tir16") == 0) //joueurs[0].pioche_tir16(joueurs[0].score_in_game)
    {
      tir16 test;
      if(test.pioche_tir16(joueur.score_in_game))
        {
      cout << joueur.nom << " pioche une carte." << endl;
      Retire_Cartes(joueur);
      quelquUnDoitPiocher = true;
    }
    } else if (strcmp(joueur.type_joueur, "humain") == 0 ) {
      humain test;
      if(test.pioche_humain(joueur.score_in_game))
        {
      cout << joueur.nom << " pioche une carte." << endl;
      Retire_Cartes(joueur);
      quelquUnDoitPiocher = true;
    }

    } else if (strcmp(joueur.type_joueur, "rand1") == 0 ) {
      rand1 test;
      if(test.pioche_rand1())
        {
      cout << joueur.nom << " pioche une carte." << endl;
      Retire_Cartes(joueur);
      quelquUnDoitPiocher = true;
    }
    }
    else if (strcmp(joueur.type_joueur, "magic") == 0 ) {
      magic test;
      if(test.pioche_magic(joueur.score_in_game))
        {
      cout << joueur.nom << " pioche une carte." << endl;
      Retire_Cartes(joueur);
      quelquUnDoitPiocher = true;
    }
    }


    joueur.score_in_game = blackjack.Calcule_Score(joueur.cartes);
  }

  // Si au moins un joueur a pioché, tous les scores sont recalculés et affichés
  if (quelquUnDoitPiocher) {
    for (joueur & joueur: joueurs) {
      std::cout << ">--------------- Le joueur " << joueur.nom << " a un score de : " << joueur.score_in_game << std::endl;
    }
  }

}
while (quelquUnDoitPiocher); // Continuer tant qu'au moins un joueur doit piocher
}
