#include "double_list.h"


p_double_list_t     double_list_create(void)
{
    p_double_list_t     list;

    if ((list = (p_double_list_t)malloc(sizeof(double_list_t))) == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    list->size = 0;
    list->head = (p_double_list_node_t)malloc(sizeof(double_list_node_t));

    if (list->head == NULL)
    {
        free(list);
        errno = ENOMEM;
        return NULL;
    }

    list->head->p_data = NULL;
    list->head->next = list->head->prev = NULL;
    list->tail = list->head;

    return list;

}
int double_list_add_after(p_double_list_t list, int number, void* pnew_item, size_t n)
{
    p_double_list_node_t current, new_node;
    void * new_pdata = NULL;
    int count = 0;

    if (list == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    new_pdata = malloc(n);
    
    if(new_pdata == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    if (list->size != 0)
    {
        new_node = (p_double_list_node_t)malloc(sizeof(double_list_node_t));
        if (new_node == NULL)
        {
            free(new_pdata);
            errno = ENOMEM;
            return -1;
        }

        memcpy(new_pdata, pnew_item, n);
        new_node->p_data = new_pdata;
        new_node->next = new_node->prev = NULL;

        if (number > 0 && number <= list->size)
        {
            current = list->head;
            while(count != number-1)
            {
                current = current->next;
                count++;
            }

            if (current->next == NULL)
            {
                current->next = new_node;
                new_node->prev = current;
                list->tail = new_node;
                list->size++;
                return 0;
            }
            new_node->prev = current;
            new_node->next = current->next;
            current->next->prev = new_node;
            current->next = new_node;

            list->size++;
        
        }else
        {
            free(new_node);
            free(new_pdata);
            errno = EINVAL;
            return -1;
        }
    }else
    {
        if (number != 0)
        {
            free(new_pdata);
            errno = EINVAL;
            return -1;
        }

        memcpy(new_pdata, pnew_item, n);
        list->head->p_data = new_pdata;
        list->size++;
    }

    return 0;
}

int double_list_add_before(p_double_list_t list, int number, void* pnew_item, size_t n)
{
    p_double_list_node_t current, new_node;
    void * new_pdata = NULL;
    int count = 1;

    if (list == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    new_pdata = malloc(n);
    
    if(new_pdata == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    if (list->size != 0)
    {
        new_node = (p_double_list_node_t)malloc(sizeof(double_list_node_t));
        if (new_node == NULL)
        {
            free(new_pdata);
            errno = ENOMEM;
            return -1;
        }

        memcpy(new_pdata, pnew_item, n);
        new_node->p_data = new_pdata;
        new_node->next = new_node->prev = NULL;

        if (number > 0 && number <= list->size)
        {
            current = list->head;
            while(count < number)
            {
                current = current->next;
                count++;
            }

            if (count == 1)
            {
                list->head->prev = new_node;
                new_node->next = list->head;
                list->head = new_node;
                list->size++;
                return 0;
            }
            
            current->prev->next = new_node;
            new_node->prev = current->prev;
            new_node->next = current;
            current->prev = new_node;

            list->size++;
        
        }else
        {
            free(new_node);
            free(new_pdata);
            errno = EINVAL;
            return -1;
        }
    }else
    {
        if (number != 0)
        {
            free(new_pdata);
            errno = EINVAL;
            return -1;
        }

        memcpy(new_pdata, pnew_item, n);
        list->head->p_data = new_pdata;
        list->size++;
    }

    return 0;
}
void double_list_delete(p_double_list_t list, int num)
{
    p_double_list_node_t    current, temp;

    int count = 1;

    if (list == NULL)
    {
        errno = ENOMEM;
        return;
    }
    current=list->head;

    while(count < num)
    {
        count++;
        current = current->next;
    }

    if (count == 1)
    {
        temp = list->head;
        list->head = temp->next;
        free(temp->p_data);
        free(temp);
        list->head->prev = NULL;
        list->size--;
        return;
    }else if (count == list->size)
    {
        temp = list->tail;
        list->tail = temp->prev;
        free(temp->p_data);
        free(temp);
        list->tail->next = NULL;
        list->size--;
    }

    temp = current;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(temp->p_data);
    free(temp);
    list->size--;
}

void double_list_update(p_double_list_t list, int number, void* pnew_item , size_t n)
{
    p_double_list_node_t    current;
    int count = 0;

    if (number < 0 || number > list->size)
    {
        errno = ENOMEM;
        return;
    }
    current = list->head;
    while(count != number-1)
    {
        current = current->next;
        count++;
    }

    memcpy(current->p_data, pnew_item, n);
}
void double_list_destroy(p_double_list_t list)
{

    int count;
    p_double_list_node_t    current, ptr;

    if (list == NULL)
    {
        errno = EINVAL;
        return;
    }
    ptr = current = list->head;

    if (list->size != 0)
    {
        for(count= 1; count <= list->size; count++)
        {
            current = current->next;
            free(ptr->p_data);
            free(ptr);
            ptr = current;
        }
    }

    free(list);
}

void* double_list_visit(p_double_list_t list, int number)
{
    int count;
    p_double_list_node_t    current;

    if (list == NULL || number < 0 || number > list->size)
    {
        errno = EINVAL;
        return NULL;
    }

    current = list->head;

    for (count = 1; count < number; count++)
        current = current->next;

    return current->p_data;
}


void double_list_trav(p_double_list_t list, void(*func)(void*))
{
    int i;
    p_double_list_node_t    current;

    if (list == NULL || list->size == 0)
    {
        errno = EINVAL;
        return ;
    }

    current = list->head;

    for ( i = 1; i <= list->size; current = current->next,i++)
        (*func)(current->p_data);

    return;
}

/* only can find the first item, if there are more than once*/
int double_list_search(p_double_list_t list, void* pnew_item, int (*comp)(void*, void*))
{
    p_double_list_node_t    current = list->head;
    int count = 1;

    while(comp(current->p_data, pnew_item) != 0 && current->next != NULL)
    {
        current = current->next;
        count++;
    }

    if (current->next == NULL && comp(current->p_data, pnew_item) != 0)
        return 0;

    return count;
}
