/**
 * 队列的入队和出队操作
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct linkqueue
{
    node*   first;
    node*   rear;
} queue;


/**
 * 入队操作
 *
 */

queue*  insert(queue  *q, int x)
{
   node *s;
   s = (node*)malloc(sizeof(node));
   s->next = NULL;
   s->data = x;
    /**
     *队列为空时
     */
   if (q->rear == NULL)
   {
        q->first = s;
        q->rear = s;
   }else//队列非空时，插入队列末尾
   {
        q->rear->next = s;
        q->rear = s;
   }

   return q;
}


/**
 * 出队操作
 *
 */

queue*  delete(queue *q)
{
    node    *p;

    if (q->first == NULL)
    {
        printf("over flow\n");
    }else
    {
        p = q->first;
        if (q->first == q->rear)//队列中只有一个元素时
        {
            q->first = NULL;
            q->rear = NULL;
        }
        else//队列中多于一个元素
        {
            q->first = q->first->next;
        }

        free(p);
    }

    return q;
}
int main(int argc, char **argv)
{
    queue*  q;
    q = (queue*)malloc(sizeof(queue));

    q->first = NULL;
    q->rear = NULL;

    q = insert(q, 1);
    q = insert(q, 2);
    q = insert(q, 5);
    q = insert(q, 8);

    printf("%d\n", delete(q)->first->data);
    printf("%d\n", delete(q)->first->data);
    printf("%d\n", delete(q)->first->data);

    return 0;
}
