#include <stdio.h>
#include "type.h"


int main(int argc, char **argv)
{
    element list[20];
    int i;

    for (i = 0; i < 20; i++)
    {
        list[i].key = i;
    }

    permute(list, 20);

    
    for (i = 0; i < 20; i++)
    {
        printf("%d " ,  list[i].key);
    }
    printf("\n");
}
