/**
 * 双链表的建立与插入和删除操作
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int     data;
    struct  Node    *next;
    struct  Node    *pre;
}dnode;

/**
 * 创建链表
 *
 */
dnode*  create()
{
   dnode    *head, *p, *s;

   int x, cycle=1;

   head = (dnode*)malloc(sizeof(dnode));

   head->next = NULL;
   head->pre = NULL;
    
   p = head;

   while(cycle)
   {
       printf("please input the data: ");
       scanf("%d", &x);
       
       if (x != 0)
       {
            s = (dnode*)malloc(sizeof(dnode));
            s->data = x;
            printf("%d\n", s->data);
            p->next = s;
            s->pre = p;
            p = s;
       }else
       {
            cycle = 0;
       }
   }

    head->next->pre = NULL;
    p->next = NULL;

    return head;
}

/**
 *
 * 打印链表
 *
 */
void print(dnode* head)
{
    if (head == NULL || head->next == NULL)
      return;

    printf("the double linked list is the following: \n");
    while(head->next != NULL)
    {
        printf("%d\n", head->next->data);
        head = head->next;
    }
}

/**
 * 在链表头部插入新节点
 *
 */

dnode*  insert_first(dnode* head, int num)
{
    dnode   *s, *p1;
    if (head->next == NULL)
    {
        s = (dnode*)malloc(sizeof(dnode));
        s->data = num;
        head->next = s;
        s->pre = NULL;
        s->next = NULL;
    }else
    {
        p1 = head->next;
        s = (dnode*)malloc(sizeof(dnode));
        s->data = num;
        s->pre = NULL;
        s->next = p1;
        p1->pre = s;
        head->next = s;
    }

    return head;
}


dnode*  insert_last(dnode* head, int num)
{
    dnode *s, *p1;
    s = (dnode*)malloc(sizeof(dnode));
    s->data = num;
    s->next = NULL;

    p1 = head;
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }

    p1->next = s;
    s->pre = p1;

    return head;
}
int main(int argc, char **argv)
{
    dnode*  head;
    head = create();
    print(head);
    head = insert_first(head, 55);
    print(head);
    head = insert_last(head, 155);
    print(head);
}
