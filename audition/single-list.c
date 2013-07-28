#include <stdio.h>
#include <stdlib.h>
/**
 * 该文件是对单链表的一些操作，包括创建，删除，测量长度
 * 逆置，排序等操作。
 *
 * 该链表包含头节点，头节点不存储数据域。
 *
 * 2013-07-28
 */

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
        scanf("%d", &x);

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
//    head = head->next;
    p->next = NULL;
    return head;
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

    while (p->next != NULL)
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
    p = head->next;

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
    p1 = head->next;

    if (head == NULL || head->next == NULL)
      return head;

    while (p1->data != num && p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }

    printf("\ndelete the first node which the num = %d\n", num);
    if (p1->data != num)
    {
        printf("%d could not be found\n", num);
    }else
    {
       if (p1 == head->next)
       {
            head->next = p1->next;
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

   p1 = head->next;
   if (p1 == NULL)
   {
        s->next = NULL;
        head->next = s;
        return head;
   }

   while(p1->data < s->data && p1->next != NULL)
   {
        p2 = p1;
        p1 = p1->next;
   }

   //在链表头部插入节点
   if (p1 == head->next)
   {
        s->next = p1;
        head->next = s;
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


/**
 * 单链表的排序 
 *
 * */

node* sort(node* head)
{
    node *p, *p2, *p3;
    int n;
    int i,j;
    int temp;

    if (head == NULL || head->next == NULL)
      return head;

    n = length(head);

    for (j = 1; j < n; j++)
    {
        p = head->next;
        for(i = 0; i < n-j; i++)
        {
            if (p->data > p->next->data)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }

    return head;
}


/**
 *
 *
 * 单链表的逆置
 *
 */
node * reverse(node* head)
{
    node *p1, *p2, *p3;

    if (head == NULL || head->next == NULL)
      return head;

    p1 = head->next;
    p2 = p1->next;

    p1->next = NULL;
    while(p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    head->next = p1;

    return head;
}

/**
 * 寻找单链表的中心节点
 *
 */
void searchmid(node* head, node *mid)
{
    node *temp = head->next;

    if (head == NULL || head->next == NULL)
    {
        mid = NULL;
        return;
    }
    if (head->next->next == NULL)
    {
        mid = head->next;
        return;
    }
      
    while (head->next->next != NULL)
    {
        head = head->next->next;
        temp = temp->next;
        mid = temp;
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
    head = sort(head);
    print(head);
    head = reverse(head);
    print(head);

    return 0;
}
