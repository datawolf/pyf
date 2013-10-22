#include <stdio.h>
#include <stdlib.h>

#include "lru.h"

// A utility function to create a new Queue node 
// the queue node will store the given 'page_number'
Node* new_node(unsigned page_number)
{
    // allocate memory and assign 'page_number'
   Node *temp = (Node*)malloc(sizeof(Node));
   temp->page_number = page_number;

   // initialize prev and next as NULL
   temp->prev = temp->next = NULL;

   return temp;
}

// A utility function to create an empty queue.
// the queue can have at most 'number_of_frames' nodes
Queue*  create_queue(int number_of_frames)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    // the queue is empty
    queue->count = 0;
    queue->front = queue->rear = NULL;

    // number of frames that can be stored in memory
    queue->number_of_frames = number_of_frames;

    return queue;
}

// A utility function to create an empty hash of given capacity
Hash* create_hash(int capacity)
{
    int i;
    // allocate memory for hash
    Hash *hash = (Hash*)malloc(sizeof(Hash));
    hash->capacity = capacity;

    // create an array of pointer for refering queue node
    hash->array = (Node**) malloc(hash->capacity * sizeof(Node*));

    // initialize all hash entries as empty
    for (i = 0; i < hash->capacity; ++i)
        hash->array[i] = NULL;

    return hash;
}


// A utility function to check if there is slot available in memory
int are_all_frames_full(Queue* queue)
{
    return queue->count == queue->number_of_frames;
}

// A utility function to check if queue is empty
int is_queue_empty(Queue *queue)
{
    return queue->rear == NULL;
}
// A utility function to delete a frame from queue
void del_queue(Queue* queue)
{
    if (is_queue_empty(queue))
        return;

    // if this is the only node in list, then change front
    if (queue->front == queue->rear)
        queue->front = NULL;

    Node* temp = queue->rear;
    queue->rear = queue->rear->prev;

    if (queue->rear)
        queue->rear->next = NULL;

    free(temp);

    queue->count--;
}

// A function to add a page with given 'page_number' to both
// queue and hash
void insert_queue(Queue* queue, Hash* hash, unsigned page_number)
{
    // is all frames are full, remvoe the page at the rear
    if (are_all_frames_full(queue))
    {
        // remvoe page from hash
        hash->array[queue->rear->page_number] = NULL;
        del_queue(queue);
    }

    // create a new node with given page number,
    // and add the new node to thr front to queue
    Node *temp = new_node(page_number);
    temp->next = queue->front;

    // if queue is empty , change both front and rear pointer
    if (is_queue_empty(queue))
        queue->rear = queue->front = temp;
    else
    {
        queue->front->prev = temp;
        queue->front = temp;
    }

    // add page entry to hash also
    hash->array[page_number] = temp;

    // increment number of full frames
    queue->count++;

}

