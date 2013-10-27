#ifndef     _QUEUE_H
#define     _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef    struct  single_list_node
{
    void* p_data;
    struct single_list_node*    next;
}single_list_node_t;

typedef single_list_node_t* p_single_list_node_t;

typedef   struct queue
{
    int size;
    p_single_list_node_t    head;
    p_single_list_node_t    tail;
} queue_t;
typedef queue_t*    p_queue_t;

extern int errno;
p_queue_t   queue_create(void);
int queue_is_empty(p_queue_t);
int queue_put(p_queue_t, void*,size_t);
void* queue_get(p_queue_t);
void queue_delete(p_queue_t);
void queue_destroy(p_queue_t);

#endif
