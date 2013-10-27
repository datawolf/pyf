#include "queue.h"


p_queue_t   queue_create(void)
{
    p_queue_t   queue;

    queue = (p_queue_t)malloc(sizeof(queue_t));
    if (queue == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }
    queue->head = (p_single_list_node_t)malloc(sizeof(single_list_node_t));
    if (queue->head == NULL)
    {
        free(queue);
        errno = ENOMEM;
        return NULL;
    }

    queue->size = 0;
    queue->head->p_data = NULL;
    queue->head->next = NULL;
    queue->tail = queue->head;

    return queue;
}


int queue_is_empty(p_queue_t queue)
{
    if (queue == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    return queue->size == 0;
}
int queue_put(p_queue_t queue, void* pitem,size_t n)
{
    p_single_list_node_t    new_item;
    void *newp = NULL;

    if (queue == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    newp = malloc(n);

    if (newp == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    memcpy(newp, pitem, n);
    if (queue->size == 0)
    {
        queue->tail->p_data = newp;
        queue->size++;
    }
    else
    {
        new_item = (p_single_list_node_t)malloc(sizeof(single_list_node_t));
        if (new_item == NULL)
        {
            free(newp);
            errno = ENOMEM;
            return -1;
        }

        new_item->p_data = newp;
        new_item->next = NULL;
        queue->tail->next = new_item;
        queue->tail = new_item;
        queue->size++;
    }

    return 0;
}
void* queue_get(p_queue_t queue)
{
    /* Notice here! if a is false, when computes a||b,  the compiler will not compute expression b.*/
    if (queue == NULL || queue->size == 0)
    {
        errno = EINVAL;
        return NULL;
    }

    return queue->head->p_data;
}

void queue_delete(p_queue_t queue)
{
    p_single_list_node_t p;


    if (queue == NULL )
    {
        errno = EINVAL;
        return;
    }

    p = queue->head;
    queue->head = p->next;
    free(p->p_data);
    free(p);
    queue->size--;
}
void queue_destroy(p_queue_t queue)
{
    int count;

    if (queue == NULL )
    {
        errno = EINVAL;
        return ;
    }

    for(count = queue->size; count >= 1; count--)
        queue_delete(queue);

    free(queue);

}
