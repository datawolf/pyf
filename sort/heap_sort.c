#include "type.h"
/* adjust the binary tree in establish the heap */
void adjust(element list[], int root, int n)
{
    int child, rootkey;
    element temp;
    temp = list[root];
    rootkey = list[root].key;
    child = root * 2;   /* left child */

    while (child <= n)
    {
        if ((child < n) &&  (list[child].key < list[child + 1].key))
            child++;

        if (rootkey > list[child].key) /* compare root and max child */
            break;
        else
        {
            list[child/2] = list[child];
            child *= 2;
        }
    }
    list[child/2] = temp;
}

void heapsort(element list[], int n)
{
    int i,j;
    element temp;

    for (i = n/2; i > 0; i--)
        adjust(list, i, n);
    for (i = n-1; i > 0; i--)
    {
        SWAP(list[1], list[i+1], temp);
        adjust(list, 1, i);
    }
}
