/* graph */
#include <stdio.h>
#include <stdlib.h>

#define NUM_V 5

typedef struct node *position;

/* node */
struct node {
    int element;
    position next;
};

/* 
 * operations (stereotype)
 */
void insert_edge(position, int, int);
void print_graph(position graph, int nv);

/* print the graph */
void print_graph(position graph, int nv) {
    int i;
    position p;
    for(i=1; i<nv; i++) {
        p = (graph + i)->next;
        printf("From %3d: ", i);
        while(p != NULL) {
            printf("%d->%d; ", i, p->element);
            p = p->next;
        }
        printf("\r\n");
    }
}

/*
 * insert an edge
 */
void insert_edge(position graph,int from, int to)
{
    position np;
    position nodeAddr;

    np = graph + from;

    nodeAddr = (position) malloc(sizeof(struct node));
    nodeAddr->element = to;
    nodeAddr->next    = np->next;
    np->next = nodeAddr;
}

/* for testing purpose */
void graph_test()
{
    struct node graph[NUM_V];
    int i;

    // initialize the vertices
    for(i=1; i<NUM_V; i++) {
        (graph+i)->element = i;
        (graph+i)->next    = NULL;
    }

    // insert edges
    insert_edge(graph,1,2);
    insert_edge(graph,1,4);
    insert_edge(graph,3,2);
    insert_edge(graph,4,2);
    insert_edge(graph,4,3);

    print_graph(graph,NUM_V);
    
    printf("=====================================================\r\n");
}
