#include <stdio.h>


struct node {
    int value;
    struct node * next;
    struct node * prev;
};


int main(int argc, char **argv)
{
    const int len = sizeof(struct node);

    if (__builtin_constant_p(len))
        printf("len is a constant.\n");
    else
        printf("len is not a constant.\n");

    return 0;
}
