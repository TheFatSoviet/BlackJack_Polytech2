#include "magic.h"

bool magic::pioche_magic(int score) {
    // Toujours piocher avec 11 ou moins, pas de risque de dépasser 21.
    if (score <= 11) {
        return true;
    }
    // Zone délicate : avec un score de 12 à 16, la décision de piocher dépend de la stratégie.
    // On peut choisir de piocher si on se sent chanceux ou si on a besoin d'augmenter le risque pour gagner.
    // Ici, pour une approche conservatrice, nous ne piocherons pas.
    if (score >= 12 && score <= 16) {
        return false;
    }
    // Avec un score de 17 ou plus, le risque de dépasser 21 est trop grand.
    return false;
}
