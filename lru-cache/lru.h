// A C program to show implementation of LRU cache
#include <stdio.h>
#include <stdlib.h>

// A Queue node (Queue is implemented using doubly linked list)
typedef struct node
{
    struct node *prev, *next;
    unsigned page_number; // the page number stored in this node
} Node;


// A queue (A FIFO collection of Queue nodes)
typedef struct queue
{
    unsigned    count;  //number of filled frames
    unsigned    number_of_frames; // total number of frames
    Node    *front, *rear;
} Queue;

typedef struct hash 
{
    int capacity;   //how many page can be stored herer
    Node  **array;
} Hash;

// A utility function to create a new Queue node 
// the queue node will store the given 'page_number'
Node* new_node(unsigned page_number);

// A utility function to create an empty queue.
// the queue can have at most 'number_of_frames' nodes
Queue*  create_queue(int number_of_frames);

// A utility function to create an empty hash of given capacity
Hash* create_hash(int capacity);


// A utility function to check if there is slot available in memory
int are_all_frames_full(Queue* queue);

// A utility function to check if queue is empty
int is_queue_empty(Queue *queue);

// A utility function to delete a frame from queue
void del_queue(Queue* queue);

// A function to add a page with given 'page_number' to both
// queue and hash
void insert_queue(Queue* queue, Hash* hash, unsigned page_number);
