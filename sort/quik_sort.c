#include "type.h"



void quiksort(element list[], int left, int right)
{
    int pivot,i,j;
    element temp;
    int middle;
    int a,b,c;
    if (left < right)
    {
        i = left;
        j = right + 1;
        middle = (left + right) / 2;
        a = list[left].key - list[middle].key;
        b = list[left].key - list[right].key;
        c = list[middle].key - list[right].key;
        if ((a >= 0 && c >= 0) || (a <= 0 && c <= 0))
            pivot = list[middle].key;
        if ((b >= 0 && c <= 0) || (b <= 0 && c >= 0))
            pivot = list[right].key;
        if ((a <= 0 && b >= 0) || (a >= 0 && b <= 0))
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
