#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>



typedef struct single_list_node
{
    void* p_data;
    struct single_list_node *next;
}single_list_node_t;

typedef single_list_node_t* p_single_list_node_t;

typedef struct stack
{
    p_single_list_node_t    top;
    p_single_list_node_t    base;
    int size;
}stack_t;

typedef stack_t* p_stack_t;

extern int errno;

p_stack_t   stack_create(void);
int push(p_stack_t, void*, size_t);
void pop(p_stack_t);
void stack_destroy(p_stack_t);
int is_empty(p_stack_t);
void* top(p_stack_t);

#endif /*_STACK_H */
