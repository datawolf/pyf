#include "single_list.h"


// create a single list
p_single_list_t single_list_create(void)
{
    p_single_list_t list;

    // allocate the single_list_t
    list = (p_single_list_t)malloc(sizeof(single_list_t));

    if (list == NULL){
        errno = ENOMEM;
        return NULL;
    }
    
    list->size = 0;

    // allocate the single_list_node_t
    list->head = (p_single_list_node_t)malloc(sizeof(single_list_node_t));

    if (list->head == NULL){
        free(list);
        errno = ENOMEM;
        return NULL;
    }

    list->head->p_data = NULL;
    list->head->next = NULL;
    list->tail = list->head;

    return list;
}

/*
 * insert a node to the single list
 *
 * On success, return 0;
 * else return -1;
 *
 * list: the single list
 * number: where the new node to be inserted
 * pnew_itme: the pointer to the new node's item
 * n: the length of the new node's item
 *
 * */
int single_list_insert(p_single_list_t list, int number, void* pnew_item, size_t n)
{
    p_single_list_node_t    current, new_node;
    void *new_p_data = NULL;
    int count = 0;

    if (list == NULL){
        errno = EINVAL;
        return -1;
    }

    new_p_data = malloc(n);
    if (new_p_data == NULL){
        errno = ENOMEM;
        return -1;
    }

    // if list is not empty
    if (list->size != 0)
    {
        // the number is bigger than 0, skip 'number' node in the list
        if (number > 0 && number <= list->size){
            new_node = (p_single_list_node_t)malloc(sizeof(single_list_node_t));
            if (new_node == NULL){
                errno = ENOMEM;
                return -1;
            }
            current = list->head;
            memcpy(new_p_data, pnew_item, n);
            new_node->p_data = new_p_data; // points to the new-allocated mem

            while(count != number - 1){
                count++;
                current = current->next;
            }

            if (current->next == NULL)
                list->tail = new_node;
            new_node->next = current->next;
            current->next = new_node;
            list->size++;
        }else if (number == 0){// the number is 0, insert the new node at the head
            new_node = (p_single_list_node_t)malloc(sizeof(single_list_node_t));
            if (new_node == NULL){
                errno = ENOMEM;
                return -1;
            }
            memcpy(new_p_data, pnew_item, n);
            new_node->p_data = new_p_data; // points to the new-allocated mem
            new_node->next = list->head;
            list->head = new_node;
            list->size++;
            
        }else{
            free(new_p_data);
            errno = EINVAL;
            return -1;
        }
    }else if (list->size == 0 && number == 0){// the list is empty
        memcpy(new_p_data, pnew_item, n);
        list->head->p_data = new_p_data;
        list->tail = list->head;
        list->size++;
    }else{// the wrong parameter
        free(new_p_data);
        errno = EINVAL;
        return -1;
    }

    return 0;
}

/**
 * Delete a node from the list
 *
 * Notice that on errors 'errno' is set properly,
 * To detect errors, use the function perror().
 *
 * */
void single_list_delete(p_single_list_t list, int num)
{
    int count = 1;
    p_single_list_node_t    temp, current;

    if (list == NULL || num <= 0 || num > list->size){
        errno = EINVAL;
        return;
    }

    current = list->head;

    if (num == 1){
        temp = current;
        list->head = current->next;
    }else{
        while(count != num - 1){
            current = current->next;
            count++;
        }
        temp = current->next;

        if (temp->next == NULL)
            list->tail = current;

        current->next = temp->next;
    }

    free(temp->p_data);
    free(temp);
    list->size--;
}


/**
 *  Update an single list
 *
 *  list: the list to be destroy 
 *
 * Notice that on errors 'errno' is set properly,
 * To detect errors, use the function perror().
 *
 * */
void single_list_update(p_single_list_t list, int num, void* pnew_item, size_t n)
{
    p_single_list_node_t current;
    int count = 1;

    if (list == NULL || num <= 0 || num > list->size){
        errno = EINVAL;
        return;
    }
    current = list->head;
    while(count != num){
        current = current->next;
        count++;
    }

    // the old node an the node has the same size
    memcpy(current->p_data, pnew_item, n);
}

/**
 *  Destroy an single list
 *
 *  list: the list to be destroy 
 *
 * Notice that on errors 'errno' is set properly,
 * To detect errors, use the function perror().
 *
 * */
void single_lsit_destroy(p_single_list_t list)
{
    int count;
    p_single_list_node_t    current, ptr;

    if (list == NULL){
        errno = EINVAL;
        return;
    }

    ptr = current = list->head;
    
    for (count = 1; count <= list->size; count++){
        current = current->next;
        free(ptr->p_data);
        free(ptr);
        ptr = current;
    }

    free(list);
}


/**
 *  Search an single list
 *
 *  list: the list to be destroy 
 *  comp: a poinger that points to a function which is defined by you to compare the items you need. 
 *  On success, returns the position of the itme you want if it is in the list
 *  or return 0 if there is no such item in the list
 *  On errors -1 is returned and errno is properly set.
 *
 **/
int single_list_search(p_single_list_t list, void* p_item, int (*comp)(void*, void*))
{
    p_single_list_node_t    current;
    int count = 1;


    if (list == NULL){
        errno = EINVAL;
        return -1;
    }

    current = list->head;
    while (comp(current->p_data, p_item) != 0 && current->next != NULL){
        current = current->next;
        count++;
    }


    if (current->next == NULL && comp(current->p_data, p_item) != 0)
        return 0;

    return count;
}

void* single_list_visit(p_single_list_t list, int num)
{
    int count;
    p_single_list_node_t    current = list->head;

    if (list == NULL || num <= 0 || num > list->size){
        errno = EINVAL;
        return;
    }

    for (count = 1; count <= num; count++)
        current = current->next;

    return current->p_data;
}
void single_list_trav(p_single_list_t list, void(*func)(void*))
{
    int i;
    if (list == NULL || list->size == 0){
        errno = EINVAL;
        return;
    }
    for (i = 1; i <= list->size; i++)
        (*func)(single_list_visit(list, i));

    return;
}
