#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *next;
};

struct Node * init_list(int n );
struct Node * reorder(struct Node *L);
void show_list(struct Node *L);
struct Node * reverse(struct Node *L);
void del_list(struct Node *L);

int main(int argc, char **argv)
{
    int n;
    struct Node *L;
    scanf("%d", &n);

    L = init_list(n);
    show_list(L);

    L = reorder(L);

    show_list(L);
    del_list(L);

    return 0;
}

struct Node * init_list(int n )
{
    struct Node *temp, *prev, *L;
    int i = 0;
   
    L = (struct Node *)malloc(sizeof(struct Node));
    L->num = 0;
    L->next = NULL;
    prev = L;
    for ( i = 1 ; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->num = i;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }
    
    return L;
}


struct Node * reorder(struct Node *L)
{
    int num, skip, m;
    struct Node *head, *tail;
    struct Node *left, *right;
    struct Node *l, *r;
    num = 0;
    head = L;
    while(head != NULL)//num为list中节点的个数
    {
        num++;
        head = head->next;
    }

    head = L;

    skip = (num + 1)/2;

    while(skip--)
    {
        tail = head;
        head = head->next;
    }
    
    tail->next = NULL;
    
    head = reverse(head);

    left = L;
    right = head;
    m = num / 2;

    while (m--)
    {   
        l = left->next;
        r = right->next;
        left->next = right;
        right->next = l;
        left = l;
        right = r;
    }

    return L;
}


void show_list(struct Node *L)
{
    if (L == NULL)
        return;
    else
    {
        while(L != NULL)
        {
            printf("%d ", L->num);
            L = L->next;
        }
    }

    printf("\n");
}


struct Node * reverse(struct Node *L)
{
    struct Node *prev = NULL;
    struct Node *s = L;

    if (L == NULL || L->next == NULL)
        return L;
    while(L->next != NULL)
    {
        s = L->next;
        L->next = prev;
        prev = L;
        L = s;
    }

    L->next = prev;

    return L;
}


void del_list(struct Node *L)
{
    struct Node *temp;
    
    while (L != NULL)
    {
       temp = L;
       L = L->next;
       free(temp);
    }

}
