
#include "tir16.h"

bool tir16::pioche_tir16(int score) {
    // Si le score est inférieur à 17, la méthode retourne vrai, indiquant qu'une carte doit être tirée.
    // Sinon, elle retourne faux, indiquant qu'aucune carte supplémentaire ne doit être tirée.
    return score < 17;
}
