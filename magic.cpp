#include "magic.h"

bool magic::pioche_magic(int score) {
    // Si le score est inférieur à 17, la méthode retourne vrai, indiquant qu'une carte doit être tirée.
    // Sinon, elle retourne faux, indiquant qu'aucune carte supplémentaire ne doit être tirée.
    return score < 19;
}
