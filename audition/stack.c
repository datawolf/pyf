/**
 * 实现栈的入栈和出栈操作
 *
 */


#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct stackqueue
{
    node*   zhandi;
    node*   top;
} queue;


/**
 * 入栈操作
 * 将新入栈的元素放到链表末尾
 */
queue*  push(queue  *q, int x)
{
    node    *s, *p;
    s = (node*)malloc(sizeof(node));
    s->data = x;
    s->next = NULL;

    if (q->zhandi == NULL)
    {
        q->zhandi = s;
        q->top = s;
    }else
    {
        q->top->next = s;
        q->top = s;
    }

    return q;
}


/**
 * 出栈操作
 * 删除链表末尾的元素
 */

queue*  top(queue *q)
{
    node    *p;

    if (q->zhandi == NULL)
    {
        printf("over flow\n");
    }
    else
    {
        p = q->zhandi;
        if (q->zhandi == q->top)
        {
            q->zhandi = NULL;
            q->top = NULL;
            free(p);
        }
        else
        {
            while (p->next != q->top)
            {
                p = p->next;
            }

            q->top = p;
            free(p->next);
            q->top->next = NULL;
        }
    }

    return q;
}
int main(int argc, char **argv)
{
    queue   *q;
    q = (queue*)malloc(sizeof(queue));

    q->top = NULL;
    q->zhandi = NULL;

    q = push(q, 1);
    q = push(q, 2);
    q = push(q, 3);
    q = push(q, 4);
   

    printf("%d\n", top(q)->top->data);
    printf("%d\n", top(q)->top->data);
    printf("%d\n", top(q)->top->data);
    return 0;
}
