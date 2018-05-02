#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "list.h"

/* use single-linked list to implement stack */
typedef struct node *position;
typedef int ElementTP;

// point to the  head node of the list
typedef struct node *STACK;
 
struct node {
    ElementTP element;
    position next;
};

STACK init_stack(void);
void delete_stack(STACK);
ElementTP top(STACK);
void push(STACK, ElementTP);
ElementTP pop(STACK);
int stack_is_null(STACK);

/*
 * initiate the stack
 * malloc the head node.
 * Head node doesn't store valid data
 * head->next is the top node
 */
STACK init_stack(void)
{
    position np;
    STACK    sk;
    
    np = (position) malloc(sizeof(struct node));
    if (np == NULL)
    	return NULL;
    	
    np->next = NULL;  // sk->next is the top node
    sk = np; 
    return sk;
}

/* pop out all elements 
 * and then delete head node
 */
void delete_stack(STACK sk)
{
    while (!stack_is_null(sk)) {
        pop(sk);
    }
    free(sk);
}
/* 
 * View the top frame
 */
ElementTP top(STACK sk)
{
    return (sk->next->element);
}

/*
 * push a value into the stack
 */
void push(STACK sk, ElementTP value) 
{
    position np;  

    np = (position) malloc(sizeof(struct node));
    if (np == NULL)
    	return;
    
    np->element  = value;
    np->next     = sk->next;

    sk->next     = np; 
}

/* 
 * pop out the top value
 */
ElementTP pop(STACK sk)
{
    ElementTP element;
    position top, newTop;
    
    if (stack_is_null(sk)) {
        printf("pop() on an empty stack\r\n");
        exit(1);
    } 
    else {
        top      = sk->next;
        element  = top->element;     
        newTop   = top->next;
        sk->next     = newTop;
        free(top);
        return element;
    } 
}

/* check whether a stack is empty*/
int stack_is_null(STACK sk)
{
    return (sk->next == NULL);
}
    
void stack_test(void)
{
    ElementTP a;
    int i;
    STACK sk;
    
    sk = init_stack();
    printf("Stack is null? %d\r\n", stack_is_null(sk));
    
    push(sk, 1);
    push(sk, 2);
    push(sk, 3);
    printf("Stack is null? %d\r\n", stack_is_null(sk));
    for (i=0; i<3; i++) {
        a = pop(sk);
        printf("pop: %d\r\n", a);
    }

    printf("Stack is null? %d\r\n", stack_is_null(sk));    
    delete_stack(sk);
    
    printf("=====================================================\r\n");
}
