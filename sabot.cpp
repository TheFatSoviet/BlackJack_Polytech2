#include "sabot.h"


using namespace std;



  int sabot::Melange_Cartes(int value)
  {
      value++;
      if (value < 1 || value > 8)
          return 0; // Si la valeur n'est pas entre 1 et 8, renvoyer 0

      // Création d'un jeu de cartes
      vector<char> Sabot_Type = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'V', 'D', 'R'};
      vector<char> Cartes;

      // Multiplication du jeu de cartes par le nombre de joueurs
      for (int i = 0; i < (value)*4; ++i)
      {
          Cartes.insert(Cartes.end(), Sabot_Type.begin(), Sabot_Type.end());
      }

      // Utiliser srand pour initialiser le générateur de nombres aléatoires avec le temps actuel
      srand(static_cast<unsigned int>(std::time(0)));
      random_shuffle(Cartes.begin(), Cartes.end());

      // Création du nom du fichier
      string filename = "Sabot.txt";

      // Ouverture du fichier en mode écriture
      ofstream file(filename);

      // Vérification que le fichier est bien ouvert
      if (!file.is_open())
      {
          cerr << "Erreur : impossible d'ouvrir le fichier." << std::endl;
          return -1;
      }

      // Écriture des cartes dans le fichier
      for (char card : Cartes)
      {
          file << card << ",";
      }

      file.close(); // Fermeture du fichier
      return 1; // Renvoyer 1 si tout est ok
  }



  void sabot::Distribuer_Cartes(vector<joueur>& joueurs)
  {
      ifstream fileIn("Sabot.txt"); // Ouvre le fichier Sabot.txt pour lire les cartes disponibles.
      string contenu, carte;
      vector<std::string> cartes; // Vecteur pour stocker toutes les cartes lues du fichier.

      if (fileIn.is_open())
      {
          getline(fileIn, contenu); // Lit toute la ligne du fichier, les cartes étant supposées être séparées par des virgules.
          fileIn.close(); // Ferme le fichier après la lecture.

          stringstream ss(contenu); // Utilise un flux de chaîne pour traiter les cartes séparées par des virgules.

          // Lire et stocker chaque carte dans le vecteur de cartes.
          while (std::getline(ss, carte, ','))
          {
              if (!carte.empty()) { // Vérifie que la chaîne n'est pas vide pour éviter d'ajouter des cartes vides.
                  cartes.push_back(carte);
              }
          }
      }

      // Attribuer deux cartes à chaque joueur et les retirer de la liste des cartes disponibles.
      for (auto& joueur : joueurs)
      {
          if (cartes.size() >= 2)
          {
              joueur.cartes.push_back(cartes[0]);
              joueur.cartes.push_back(cartes[1]);
              cartes.erase(cartes.begin(), cartes.begin() + 2); // Supprime les cartes distribuées du vecteur.
          }
      }

      // Mettre à jour le fichier Sabot.txt avec les cartes restantes.
      ofstream fileOut("Sabot.txt");
      if (fileOut.is_open())
      {
          for (size_t i = 0; i < cartes.size(); ++i)
          {
              fileOut << cartes[i];
              if (i != cartes.size() - 1)
              { // Ajoute une virgule entre les cartes, sauf après la dernière.
                  fileOut << ",";
              }
          }
          fileOut.close(); // Ferme le fichier après l'écriture.
      }
  }



  void sabot::verifierSabot(int nombreDeJoueurs) {
    ifstream fileIn("Sabot.txt");
    string contenu;
    map < std::string, int > compteurCartes;
    int totalCartes = 0;

    if (fileIn.is_open()) {
      std::getline(fileIn, contenu);
      fileIn.close();

      std::stringstream ss(contenu);
      std::string carte;
      while (std::getline(ss, carte, ',')) {
        compteurCartes[carte]++;
        totalCartes++;
      }
    } else {
      cerr << "Erreur : impossible d'ouvrir le fichier Sabot.txt" << endl;
      return;
    }

    int totalCartesAttendu = 52 * (nombreDeJoueurs + 1); // Le +1 est pour inclure les cartes du croupier dans le calcul
    map < std::string, int > valeursAttendues = {
      {
        "1",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "2",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "3",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "4",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "5",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "6",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "7",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "8",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "9",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "X",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "V",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "D",
        4 * (nombreDeJoueurs + 1)
      },
      {
        "R",
        4 * (nombreDeJoueurs + 1)
      }
    };

    bool validationReussie = true;
    if (totalCartes != totalCartesAttendu) {
      std::cout << "Erreur : le nombre total de cartes dans le sabot (" << totalCartes << ") ne correspond pas au nombre attendu (" << totalCartesAttendu << ")." << std::endl;
      validationReussie = false;
    }

    for (const auto & paire: valeursAttendues) {
      if (compteurCartes[paire.first] != paire.second) {
        std::cout << "Erreur : le nombre de cartes de valeur " << paire.first << " (" << compteurCartes[paire.first] << ") ne correspond pas au nombre attendu (" << paire.second << ")." << std::endl;
        validationReussie = false;
      }
    }

    if (validationReussie) {
      std::cout << "La vérification du sabot est valide." << std::endl;
    }
  }
