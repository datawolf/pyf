#include <stdio.h>
#include "type.h"


int main(int argc, char **argv)
{
    element list[27];
    int i;
    element temp;

    for (i = 0; i < 27; i++)
    {
        list[i].key = i;
    }

    permute(list, 27);

    printf("before insert sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n");
    
    insertion_sort(list, 27); 
    printf("after insert  sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n\n");


    permute(list, 27);

    printf("before quik sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n");
    
    quiksort(list, 0, 26); 
    printf("after quik  sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n\n");

    permute(list, 27);

    printf("before merge sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n");
    
    merge_sort(list, 27); 
    printf("after merge  sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n\n");

    permute(list, 27);
    SWAP(list[0], list[26], temp);

    printf("before heap sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n");
    
    heapsort(list, 26); 
    printf("after heap sort\n"); 
    for (i = 0; i < 27; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n");
}
