#include "sabot.h"

using namespace std;


  int sabot::Melange_Cartes(int value)
  {
      value++;
      if (value < 1 || value > 8)
          return 0; // Si la valeur n'est pas entre 1 et 8, renvoyer 0

      // Création d'un jeu de cartes
      vector<char> Sabot_Type = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'V', 'D', 'R'};
      vector<char> Cartes;

      // Multiplication du jeu de cartes par le nombre de joueurs
      for (int i = 0; i < (value - '0'); ++i)
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



  void sabot::Ranger_Cartes(vector<joueur>& joueurs)
  {
      // Ouvre le fichier Sabot.txt en mode append pour ajouter du contenu à la fin sans supprimer le contenu existant.
      ofstream fileOut("Sabot.txt", std::ios::app);

      // Vérifie si le fichier a été correctement ouvert.
      if (!fileOut.is_open())
      {
          cerr << "Erreur : impossible d'ouvrir le fichier pour ajouter." << std::endl;
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
      cout << "Cartes rangées avec succès dans le sabot." << std::endl; // Confirme que l'opération s'est bien déroulée.
  }

  void sabot::Distribuer_Cartes(std::vector<joueur>& joueurs)
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


/*  void sabot::Retire_Cartes(joueur& joueur)
  {
      ifstream fileIn("Sabot.txt");
      string contenu, carte;
      vector<std::string> cartes;

      if (fileIn.is_open()) {
          getline(fileIn, contenu); // Lit toute la ligne du fichier Sabot.txt.
          fileIn.close();

          stringstream ss(contenu);

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
              ofstream fileOut("Sabot.txt");
              if (fileOut.is_open()) {
                  for (size_t i = 0; i < cartes.size(); ++i) {
                      fileOut << cartes[i];
                      if (i != cartes.size() - 1) {
                          fileOut << ",";
                      }
                  }
                  fileOut.close();
              } else {
                  cerr << "Erreur lors de la réouverture du fichier pour écriture." <<endl;
              }
          } else {
              cerr << "Pas de cartes disponibles pour retirer." << endl;
          }
      } else {
          cerr << "Erreur lors de l'ouverture du fichier." << endl;
      }
  }

};*/
