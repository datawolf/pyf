#include <stdio.h>

//自定义结构体的方法1

typedef  struct node    *node_pointer;

//typedef  struct node {
struct node {
    node_pointer llink;
    int     data;
    node_pointer rlink;
};

int main()
{
    node_pointer    p;
    return 0;
}

//自定义结构体类型的方法
typedef  struct node    *node_pointer;

typedef  struct node {
    node_pointer llink;
    int     data;
    node_pointer rlink;
} mynode;

