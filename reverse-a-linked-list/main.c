/**
 * Reverse a linked list
 *
 * Author: Wang Long(wanglong@cse.buaa.edu.cn)
 **/

#include <stdio.h>
#include <stdlib.h>

// link list node 
struct node {
    int data;
    struct node* next;
};

/**
 * Function to reverse a linked list
 *
 * Iterative Method:
 * Iterate through the linked list. In loop, 
 * change next to prev, prev to current and current to next
 * */
static void reverse(struct node** head_ref)
{
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

/**
 * Function to push a node
 *
 *
 * */
void push(struct node** head_ref, int new_data)
{
    // allocate node
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    // put in the data
    new_node->data = new_data;

    // link the old list off the new node
    new_node->next = *head_ref;

    // move the head to point to the new node
    *head_ref = new_node;
}


/**
 * Function to print linked list
 **/
void print_list(struct node *head)
{
    struct node *temp = head;
    
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/**
 * Function to reverse a linked list in Recursive Method
 *
 * Recursive Method:
 * 1) Divide the list in two parts - first node and rest of the linked list
 * 2) Call reverse for the rest of the linked list
 * 3) Link rest to first
 * 4) Fix head pointer
 * */
void recursive_reverse(struct node** head_ref)
{
    struct node *first;
    struct node *rest;

    // empty list
    if (*head_ref == NULL)
        return;

    first = *head_ref;
    rest = first->next;

    // List has only one node
    if (rest == NULL)
        return;

    // reverse the rest linked list and put the first element at the end
    recursive_reverse(&rest);
    first->next->next = first;

    first->next = NULL;

    // Fix the head pointer
    *head_ref = rest;

}
/**
 * The main function to test above function
 *
 * */
int main(int argc, char **argv)
{
    // start with the empty list
    struct node *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);

    print_list(head);
    reverse(&head);
    print_list(head);
    recursive_reverse(&head);
    print_list(head);

    return 0;
}
