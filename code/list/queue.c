#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "list.h"

/* use single-linked list to implement queue */
typedef struct node *position;
typedef int ElementTP;

// point to the head node of the list
typedef struct HeadNode *QUEUE;
 
struct node {
    ElementTP element;
    position next;
};

/*
 * CAUTIOUS: "HeadNode" is different from "node", 
 * it's another struct
 * end: points to the last value in the queue
 */
struct HeadNode {
    ElementTP element;
    position next;
    position end;
};


/*
 * Operations
 */
QUEUE init_queue(void);
void delete_queue(QUEUE);
void enqueue(QUEUE, ElementTP);
ElementTP dequeue(QUEUE);
int queue_is_null(QUEUE);

/*
 * initiate the queue
 * malloc the head node.
 * Head node doesn't store valid data
 * head->next is the first node in the queue.
 */
QUEUE init_queue(void)
{
    QUEUE q;
    
    q = (QUEUE) malloc(sizeof(struct HeadNode));
    if (q == NULL)
    	return NULL;
    	
    q->element = 0;
    q->next  = NULL;
    q->end   = NULL;
    
    return q;
}

/*
 * dequeue all elements 
 * and then delete head node
 */
void delete_queue(QUEUE q)
{
    while (!queue_is_null(q)) {
        dequeue(q);
    }
    free(q);
}

/*
 * enqueue a value to the end of the queue 
 */
void enqueue(QUEUE q, ElementTP value)
{
    position np;
    position oldEnd;

    np = (position) malloc(sizeof(struct node));
    if (np == NULL)
    	return;
    
    np->element = value;
    np->next    = NULL;
    
    oldEnd = q->end;
    if (oldEnd)
    {
        oldEnd->next = np;
    }
    else
    {
    	q->next = np;
    }
    
    q->end = np;
}

/* 
 * dequeue the first value
 */
ElementTP dequeue(QUEUE q)
{
    ElementTP element;
    position first, newFirst;
    
    if (queue_is_null(q)) {
        printf("dequeue() on an empty queue\r\n");
        exit(1);
    } 
    else {
        first    = q->next;
        element  = first->element;     
        newFirst = first->next;
        q->next  = newFirst;
        free(first);
        return element;
    } 
}

/* check whether a queue is empty*/
int queue_is_null(QUEUE q)
{
    return (q->next == NULL);
}
    
void queue_test(void)
{
    ElementTP a;
    int i;
    QUEUE q;
    
    q = init_queue();
    printf("Queue is null? %d\r\n", queue_is_null(q));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Queue is null? %d\r\n", queue_is_null(q));
    for (i = 0; i < 3; i++) {
        a = dequeue(q);
        printf("dequeue: %d\r\n", a);
    }

    printf("Queue is null? %d\r\n", queue_is_null(q));    
    delete_queue(q);
    
    printf("=====================================================\r\n");
}
