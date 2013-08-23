#include "type.h"



void quiksort(element list[], int left, int right)
{
    int pivot,i,j;
    element temp;

    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = list[left].key;

        do {
           do
               i++;
           while (list[i].key < pivot);

           do
               j--;
           while (list[j].key > pivot);

           if (i < j)
               SWAP(list[i], list[j], temp);
        }
        while (i < j);
        SWAP(list[left], list[j], temp);
        quiksort(list, left, j-1);
        quiksort(list, j+1, right);
    }
}
