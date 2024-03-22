

#include "ret3.h"

bool ret3::pioche_ret3(int score)
{
    static int i=0;
    if(score >= 21){
      return false;
    }
    if (i<3)
    {
      i=i+1;
      return true;
    }
    else
    {
      i=0;
      return false;
    }

}
