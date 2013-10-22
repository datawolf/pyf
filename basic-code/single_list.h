#ifndef _SINGLE_LIST_H
#define _SINGLE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// single list node
typedef struct single_list_node{
    void*   p_data;
    struct  single_list_node *next;
}single_list_node_t;
typedef single_list_node_t*  p_single_list_node_t;


//single list 
typedef struct single_list{
    int size;
    p_single_list_node_t head;
    p_single_list_node_t tail;
}single_list_t;
typedef single_list_t* p_single_list_t;

extern int errno;

// create a single list
p_single_list_t single_list_create(void);
int single_list_insert(p_single_list_t, int, void*, size_t);
void single_list_delete(p_single_list_t, int);
void single_list_update(p_single_list_t, int, void*, size_t);
void single_lsit_destroy(p_single_list_t);
int single_list_search(p_single_list_t, void*, int (*)(void*, void*));
void* single_list_visit(p_single_list_t, int);
void single_list_trav(p_single_list_t, void(*)(void*));

#endif
