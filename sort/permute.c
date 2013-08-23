#include <stdlib.h>
#include <time.h>
#include "type.h"

void permute(element list[], int n)
{
   int i,j;
   element temp;

   for (i = n-1; i >= 1; i--)
   {
        srand((int)time(NULL));
        j = rand() % (n-1) + 1;
        SWAP(list[i], list[j], temp)
   }
}
