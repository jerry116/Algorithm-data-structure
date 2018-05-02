#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"
#include "list.h"

typedef struct node *LIST; 
typedef struct node *position;

/* node，节点 */
struct node {
    int element;
    position next;
};
#if 0
/* 
 * operations (stereotype)
 * 操作
 */
LIST init_list(void);
void delete_list(LIST);
int is_null(LIST);
void insert_node(position, int);
void delete_node(LIST, position);
position find_last(LIST);
position find_value(LIST, int);
position find_previous(LIST, position);
void print_list(LIST);

/*
 * Traverse the list and print each element
 * 打印表
 */
void print_list(LIST L)
{
    position np;
    if (is_null(L)) {
        printf("Empty List\r\n");
        return;
    }

    np = L;
    while (np->next != NULL) { 
        np = np->next;
        printf("%p: %3d \r\n", np, np->element);
    }
    printf("\r\n");

}

/*
 * Initialize a linked list. This list has a head node
 * head node doesn't store valid element value
 * 创建表
 */
LIST init_list(void) 
{
    LIST L;
    
    L = (position) malloc(sizeof(struct node));
    if (L == NULL)
    	return NULL;
    
    L->next = NULL;
    return L;
}

/*
 * Delete all nodes in a list
 * 删除表
 */
void delete_list(LIST L)
{
    position np, next;

	if (L == NULL)
		return;
	
    np = L;
    do {
        next = np->next;
        free(np);
        np   = next;
    } while (next != NULL);    
}

/*
 * if a list only has head node, then the list is null.
 * 判断表是否为空
 */
int is_null(LIST L) 
{
	if (L == NULL)
		return 0;
	
    return ((L->next) == NULL);
}

/*
 * insert a node after position np
 * 在np节点之后，插入节点
 */
void insert_node(position np, int value) 
{
    position nodeAddr;
    
    nodeAddr = (position) malloc(sizeof(struct node));
    if (nodeAddr == NULL)
    	return;
    
    nodeAddr->element = value;
    nodeAddr->next = np->next;
    np->next = nodeAddr;    
}

/*
 * delete node at position np
 * 删除np节点
 */
void delete_node(LIST L, position np)
{
    position previous, next;
    
    if (L == NULL)
    	return;
    
    next     = np->next;
    previous = find_previous(L, np);
    if (previous != NULL) {
        previous->next = next;
        free(np); 
    }
    else {
        printf("Error: np not in the list\r\n");
    }
}

/*
 * find the last node of the list
 * 寻找表的最后一个节点
 */
position find_last(LIST L)
{
    position np;
    
    if (L == NULL)
    	return NULL;
    
    np = L;
    while (np->next != NULL) {
        np = np->next;
    }
    return np;
}

/*
 * This function serves for 2 purposes:
 * 1. find previous node 
 * 2. return NULL if the position isn't in the list
 * 寻找npTarget节点前面的节点
 */
position find_previous(LIST L, position npTarget)
{
    position np;
    
    if (L == NULL)
    	return NULL;
   
    np = L;
    while (np->next != NULL) {
        if (np->next == npTarget)
        	return np; 
        np = np->next;
    } 
    return NULL;
}

/*
 * find the first node with specific value
 * 查询
 */
position find_value(LIST L, int value) 
{
    position np;
    
    if (L == NULL)
    	return NULL;

    np = L;
    while (np->next != NULL) {
        np = np->next;
        if (np->element == value)
        	return np;
    }
    return NULL;
}

/* for testing purpose */
void slist_test()
{
    LIST L;
    position np;
    
    int i;
    int len;
    /* elements to be put into the list */
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    /* initiate a list */
    L = init_list();
    print_list(L);
    len = sizeof(a)/sizeof(a[0]);

    /* insert nodes. Insert just after head node */
    for (i = len - 1; i >= 0; i--) {
        insert_node(L, a[i]);
    }
    print_list(L);

    /* delete first node with value 5 */
    np = find_value(L, 5);
    delete_node(L, np);
    print_list(L);

    /* delete list */
    delete_list(L);

    /* initiate a list */
    L = init_list();
    print_list(L);

    /* insert nodes. Insert just after head node */
    for (i = len - 1; i >= 0; i--) {
        insert_node(L, a[i]);
    }
    print_list(L);

    /* delete list */
    delete_list(L);
    
    printf("=====================================================\r\n");
}
#endif
