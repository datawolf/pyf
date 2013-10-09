#include <stdlib.h>
#include <stdio.h>

#include "list.h"

List * init_list(int n )
{
    List *temp, *prev, *L;
    int i = 0;

    L = (List *)malloc(sizeof(List));
  //  L->num = 0;
    L->next = NULL;
    prev = L;
    for ( i = 1 ; i <= n; i++)
    {
        temp = (List *)malloc(sizeof(List));
        temp->num = i;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
    }

    return L;
}

void show_list(List *head)
{
    List *curr = head->next;
    while(curr != NULL)
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
    printf("\n");
}


List*  reverse_list1(List *head)
{
    List *curr = head->next;
    List *next = NULL;
    List *nextnext = NULL;

    // if no elements or only one element exists
    if (curr == NULL || curr->next == NULL)
        return head;

    // if more than one element
    while (curr->next != NULL)
    {
        next = curr->next;
        nextnext = next->next;
        next->next = head->next;
        head->next = next;
        curr->next = nextnext;
    }


    return head;
}
List* reverse_list2(List *head)
{
    List *prev = NULL;
    List *next;
    List *curr = head->next;

    // if no elements or only one element exists
    if (curr == NULL || curr->next == NULL)
        return head;

    // if more than one element
    while (curr->next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    head->next = curr;
}

void  reverse_list3(List *head)
{
    if (head->next != NULL)
    {
        reverse_list3(head->next);
        printf("%d ", head->next->num);
    }
}

List *reverse_list(List *head)
{
    List * rhead;
    if (head->next == NULL)
        return head;

    rhead = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return rhead;
}
List *reverse_list4(List *head)
{
    // if no elements or only one element exists
    if (head == NULL || head->next == NULL)
        return head;
    
    head->next = reverse_list(head->next);
    return head;
}

int main(int argc, char **argv)
{
    List *head;
    head = init_list(10);

    show_list(head);

    head = reverse_list4(head);
    //reverse_list3(head);
    show_list(head);

    return 0;
}
