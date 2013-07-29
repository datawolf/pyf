/**
 *
 * 题目参见，程序员面试宝典（第三版）第174页
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct  Link
{
    int data;
    struct Link *next;
}link;


/**
 *创建具有n个节点的循环链表
 *不包含头节点
 */
link*   create(int n)
{
    int i;
    link    *head = NULL;
    link    *p, *curr;

    if ( n > 0)
    {
         head  = (link*)malloc(sizeof(link));
         head->data = n;
         head->next = head;

        curr = head;
        for (i = n-1; i >= 1; i--)
        {
            p = (link*)malloc(sizeof(link));
            p->data = i;
            p->next = head->next;
            head->next = p;
        }
    }
    return head;
}
/**
 * n 代表人的个数
 * 报数到m时，该人退出
 * 从第k个人开始报数
 */
void josephus(int m, int k, int n)
{
    link  *head, *p, *r;
    head = create(n);
    int s;
    
    p = head;
    while(k--)
    {
        r = p;
        p = p->next;
    }

    while(n--)
    {
        s = m-1;
        while(s--)
        {
            r = p;
            p = p->next;
        }
        printf("%d\n", p->data);
        r->next = p->next;
        free(p);
        p = r->next;
        

    }

}

int main(int argc, char **argv)
{
    //josephus(m, k, n)
    //n 为参与游戏的人数
    //k 为从第k个人开始报数
    //m 为报道m时，该人出列
    josephus(3, 4, 13);
    return 0;
}
