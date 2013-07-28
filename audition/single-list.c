#include <stdio.h>
#include <stdlib.h>


typedef     struct  Node
{
    int     data;
    struct  Node    *next;
} node;

/**
 * 建立一个单链表, 输入0结束创建节点
 *
 */
node*   create()
{
    node    *head, *p, *s;
    int x;
    int cycle = 1;

    head = (node*)malloc(sizeof(node));

    p = head;
    while(cycle)
    {
        printf("please input the data:");
        scanf("%x", &x);

        if (x != 0)
        {
            s = (node*)malloc(sizeof(node));
            s->data = x;
            printf("%d\n", s->data);
            p->next = s;
            p = s;
        }else
          cycle = 0;
    }
    head = head->next;
}

/**
 * 测试单链表的长度
 *
 */
int length(node * head)
{
    int n = 0;
    node *p;
    
    p = head;

    while (p != NULL)
    {
        p = p->next;
        n++;
    }
    
    return n;
}

/**
 * 打印单链表中的数据
 *
 */
void print(node *head)
{
    node *p;
    int  n;

    n = length(head);
    p = head;

    printf("\nNow, These %d records are : \n", n);

    if ( p != NULL)
      while(p != NULL)
      {
        printf("%d\n", p->data);
        p = p->next;
      }
    
}

/**
 * 删除单链表中的节点
 *
 */

node *del(node *head, int num)
{
    node *p1, *p2;
    p1 = head;

    while (p1->data != num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }

    printf("\ndelete the first node which the num = %d\n", num);
    if (p1->data != num)
    {
        printf("%d could be found\n", num);
    }else
    {
       if (p1 == head)
       {
            head = p1->next;
       }else
       {
            p2->next = p1->next;
       }
       free(p1);
    }

    return head;
}

/**
 *单链表节点的插入
 *
 * */

node*   insert(node *head, int num)
{
   node *p1, *p2, *s;

   s = (node*)malloc(sizeof(node));
   s->data = num;

   p1 = head;
   while(p1->data < s->data && p1->next != NULL)
   {
        p2 = p1;
        p1 = p1->next;
   }

   //在链表头部插入节点
   if (p1 == head)
   {
        s->next = p1;
        head = s;
        return head;
   }

   //在链表结尾插入节点
   if (p1->next == NULL)
   {
        p1->next = s;
        s->next = NULL;
        return head;
   }
    //在链表中间插入节点
   if (p1->next != NULL)
   {
        p2->next = s;
        s->next = p1;
        return head;
   }


}
int main( int argc, char **argv)
{
    node *head;
    
    head = create();
    print(head);
    head = del(head, 5);
    print(head);
    head = insert(head, 5);
    print(head);

    return 0;
}
