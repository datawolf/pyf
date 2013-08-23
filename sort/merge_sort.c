#include "type.h"


void merge(element list[], element sorted[], int i, int m, int n)
{
    int j,k,t;
    j = m+1;
    k = i;

    while( i <= m && j <= n)
    {
        if (list[i].key < list[j].key)
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    if ( i > m)
        for (t = j; t <= n; t++)
            sorted[k++] = list[t];
    else
        for (t = i; t <= m; t++)
            sorted[k+t-i] = list[t];
}

void merge_pass(element list[], element sorted[], int n, int length)
{
    int i,j;

    for (i = 0; i <= n - 2 * length; i += 2 * length)
        merge(list, sorted, i, i+length-1, i+2*length-1);

    if (i + length < n)
        merge(list, sorted, i, i+length-1, n-1);
    else
        for(j = i; j < n; j++)
            sorted[j] = list[j];
}

void merge_sort(element list[], int n)
{
    int length = 1;
    element extra[MAX_SIZE];

    while (length < n)
    {
        merge_pass(list, extra, n, length);
        length *= 2;
        merge_pass(extra, list, n, length);
        length *= 2;
    }
}
