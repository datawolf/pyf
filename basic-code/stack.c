#include "stack.h"
/** 
 * Create a stack
 */
p_stack_t   stack_create(void)
{
    p_stack_t   stack;
    
    stack = (p_stack_t)malloc(sizeof(stack_t));

    if (stack == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    stack->top = (p_single_list_node_t)malloc(sizeof(single_list_node_t));

    if (stack->top == NULL)
    {
        free(stack);
        errno = ENOMEM;
        return NULL;
    }

    stack->size = 0;
    stack->top->p_data = NULL;
    stack->top->next = NULL;
    stack->base = stack->top;

    return stack;
}

/**
 * Push an item into the stack
 *
 * */
int push(p_stack_t stack, void* p_item, size_t n)
{
    p_single_list_node_t p;
    void *newp;

    if (stack == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    newp = malloc(n);
    if (newp == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    if (stack->size != 0)
    {
        p = (p_single_list_node_t)malloc(sizeof(single_list_node_t));
        if (p == NULL)
        {
            free(newp);
            errno = ENOMEM;
            return -1;
        }
        memcpy(newp, p_item, n);
        p->p_data = newp;
        p->next = stack->top;
        stack->top = p;
        stack->size++;
    }else
    {
        memcpy(newp, p_item,n);
        stack->top->p_data = newp;
        stack->size++;
    }

    return 0;
}

/**
 * Pop an element from the stack
 *
 * */
void pop(p_stack_t stack)
{
    p_single_list_node_t    p;

    if (stack == NULL || stack->size == 0)
    {
        errno = EINVAL;
        return;
    }

    p = stack->top;
    stack->top = p->next;
    free(p->p_data);
    free(p);
    stack->size--;
}

/**
 * Delete an stack
 *
 * */
void stack_destroy(p_stack_t stack)
{
    int count;

    if (stack == NULL )
    {
        errno = EINVAL;
        return;
    }

    for (count = stack->size; count >= 1; count--)
        pop(stack);


    free(stack);
}

/**
 * Detect whether the stack is empty
 * */
int is_empty(p_stack_t stack)
{
    if (stack == NULL )
    {
        errno = EINVAL;
        return;
    }

    return stack->size == 0;
}

/**
 * Get the first element from the stack
 *
 * */
void* top(p_stack_t stack)
{
    if (stack == NULL || stack->size == 0)
    {
        errno = EINVAL;
        return;
    }

    return stack->top->p_data;
    
}

