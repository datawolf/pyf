#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


typedef struct double_list_node
{
    struct double_list_node *prev;
    struct double_list_node *next;
    void*   p_data;
} double_list_node_t;

typedef double_list_node_t* p_double_list_node_t;

typedef struct  double_list
{
    p_double_list_node_t    head;
    p_double_list_node_t    tail;
    int size;
} double_list_t;

typedef double_list_t*  p_double_list_t;

p_double_list_t     double_list_create(void);
int double_list_add_after(p_double_list_t, int, void*, size_t);
int double_list_add_before(p_double_list_t, int, void*, size_t);
void double_list_delete(p_double_list_t, int);
void double_list_update(p_double_list_t, int, void* , size_t);
void double_list_destroy(p_double_list_t);
void* double_list_visit(p_double_list_t, int);
void double_list_trav(p_double_list_t, void(*)(void*));
int double_list_search(p_double_list_t, void*, int (*)(void*, void*));

#endif  /*_DOUBLE_LIST_H*/
