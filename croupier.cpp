#include "croupier.h"


  bool croupier::pioche_croupier(int score_in_game){
      if (score_in_game > 17){
          return 0;
      }
      else{
          return 1;
      }
  }
