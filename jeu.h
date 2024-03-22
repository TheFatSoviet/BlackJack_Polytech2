#ifndef JEU_H
#define JEU_H

class jeu {
public:
    char Nombre_Joueurs_char = 0;
    int Nombre_Joueurs = 0;

    jeu(char nb_joueur_char, int nb_joueur);
    void BoucleDeJeu(std::vector<Joueur>& joueurs);
  //  void Afficher_Cartes_Joueur(const Joueur& joueur, size_t numeroDuJoueur);
};


#endif
