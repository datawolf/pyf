#include <stdio.h>

void maopao(int *list, int n)
{
    int i,j, temp;

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i; j++)
        {
            if (list[j] > list[j+1])
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
int main(int argc, char **argv)
{
    int list[10];
    int n,i;

    printf("input 10  number: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &list[i]);
    }

    printf("\n");

    maopao(list, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%5d", list[i]);
    }
    
    printf("\n");

    return 0;

}
