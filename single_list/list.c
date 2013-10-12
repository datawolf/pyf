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

/**
 * 找出单链表的倒数第四个元素
 *
 */
List* get_last_4th_one(List *head)
{
    int i;
    List *first = head;
    List *second = head;

    for (i = 0; i < 4; i++)
    {
        if (first->next == NULL)
            return NULL;
        first = first->next;
    }

    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    return second;
}


/**
 * 找出单链表的倒数第四个元素
 *
 */
List* get_last_4th_one_by_array(List *head)
{
    List *curr = head;
    int i = 0;
    List* arr[4];

    while (curr->next != NULL)
    {
        arr[i] = curr->next;
        curr = curr->next;
        i = (i+1)%4;
    }

    if (arr[i] == NULL)
        return NULL;
    return arr[i];
}


/**
 *找出单链表的中间元素
 *
 */
List *get_middle_one(List *head)
{
    List *first = head;
    List *second = head;

    while(first != NULL && first->next != NULL)
    {
        first = first->next->next;
        second = second->next;
    }

    return second;
}

/**
 * 单链表交换任意两个元素
 *
 */
List* switch_point(List *head, List *p, List *q)
{
    List *curr = head;
    List *curr1 = p;
    List *curr2 = q;
    List *pre1 = NULL;
    List *pre2 = NULL;
    int count = 0;

    if (p == head || q = head)
        return head;
    if (p == q)
        return head;

    // find p and q in the list
    while(curr != NULL)
    {
        if (curr->next == p)
        {
            pre1 = curr;
            count++;
            if (count == 2)
                break;
        }
        else if (curr->next == q)
        {
            pre2 = curr;
            count++;
            if (count == 2)
                break;
        }
        curr = curr->next;
    }

    curr = curr1->next;
    pre1->next = curr2;
    curr1->next = curr2->next;
    pre2->next = curr1;
    curr2->next = curr;

    return head;
}


/**
 *判断单链表是否有环
 *return 1 if exist circle
 *return 0 if not exist circle
 * */
int is_exist_circle(List *head)
{
    List *first = head; //1 step each time
    List *second = head; //2 step each time

    while (second->next != NULL && second->next->next != NULL)
    {
        second = second->next->next;
        first = first->next;

        if (second == first)
            return 1;
    }

    return 0;

}


int main(int argc, char **argv)
{
    List *head;
    List *a;
    head = init_list(10);

    show_list(head);

    a = get_middle_one(head);
    //head = reverse_list4(head);
    //reverse_list3(head);
    printf("the middle element is %d\n", a->num);
//    show_list(head);

    return 0;
}
