#include <stdio.h>

#include "lru.h"

// This function is called when a page with given 'page_number' is referenced
// from cache (or memory). there are two cases:
// 1. Frame is not there in memory, we bring it in memory and add to the front 
//    of queue
// 2. Frame is there in memory, we move the frame to front of queue
int  reference_page(Queue *queue, Hash *hash, unsigned page_number)
{
    Node   *req_page = hash->array[page_number];

    // the page is not in cache, bring it
    if (req_page == NULL)
    {
        insert_queue(queue, hash, page_number);
        return 1;
    }
    else if (req_page != queue->front)// page is there and not at front, change pointer
    {
        //unlink requested page from its current location in queue
        req_page->prev->next = req_page->next;
        if (req_page->next)
            req_page->next->prev = req_page->prev;

        // if the requested page is rear, then change rear as this node
        // will be move front
        if (req_page == queue->rear)
        {
            queue->rear = req_page->prev;
            queue->rear->next = NULL;
        }

        // put the requested page before current page
        req_page->next = queue->front;
        req_page->prev = NULL;

        // change prev of current front
        req_page->next->prev = req_page;

        // change front to the requested page
        queue->front = req_page;

        return 0;
    }
}


// the utility function to print cache frame (which has four frames) 
void print_frame(Queue *q, int is_page_fault)
{
    Node *tmp = q->front;

    if ( is_page_fault == 1)
        printf("Page Fault: ");
    else
        printf("            ");

    while (tmp != NULL)
    {
        printf("%d ", tmp->page_number);
        tmp = tmp->next;
    }

    printf("\n");
}

// Driver program to test above functions
int main(int argc, char **argv)
{
    int i;

    int n = 19;
    // let us refer pages 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0 ,1
    // http://cs.uttyler.edu/Faculty/Rainwater/COSC3355/Animations/lrupagereplacement.htm
    int ref[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int is_page_fault;

    // let cache can hold 3 pages
    Queue *q = create_queue(3);

    // let 10 different pages can be requested 
    // (pages to be referenced are numbered from 0 to 9)
    Hash *hash = create_hash(10);

    for (i = 0; i  <= n; i++)
    {
        is_page_fault = reference_page(q, hash, ref[i]);
        print_frame(q, is_page_fault); 
    }
    return 0;
}
