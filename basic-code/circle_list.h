#ifndef     _CIRCLE_LIST_H
#define     _CIRCLE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>



typedef     struct double_list_node
{
    struct double_list_node *next;
    struct double_list_node *prev;

    void*   p_data;
} double_list_node_t;

typedef     double_list_node_t*     p_double_list_node_t;

typedef     struct circle_list
{
    p_double_list_node_t    head;
    p_double_list_node_t    tail;
    int size;
} circle_list_t;

typedef     circle_list_t*      p_circle_list_t;

extern      int     errno;

p_circle_list_t     circle_list_create(void);
int     circle_list_insert(p_circle_list_t, int, void*, size_t);
void    circle_list_delete(p_circle_list_t, int);
void    circle_list_update(p_circle_list_t, int, void*, size_t);
void    circle_list_trav(p_circle_list_t, void(*)(void*));
void    circle_list_destroy(p_circle_list_t);
void*   circle_list_visit(p_circle_list_t, int);
int     circle_list_search(p_circle_list_t, void*, int (*)(void*, void*));
void    circle_list_rotate(p_circle_list_t, int);

#endif      /*_CIRCLE_LIST_H */
