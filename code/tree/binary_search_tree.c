#include <stdio.h>
#include <stdlib.h>

typedef int ElementV;
typedef struct node *position;

/* node，节点 */
struct node {
	position parent;
    ElementV element;
    position lchild;
    position rchild;
};

/* root node of the tree */
typedef struct node *TREE;

/* 
 * operations (stereotype)
 * 操作
 */
void print_sorted_tree(TREE);
position find_min(TREE);
position find_max(TREE);
position find__tree_value(TREE, ElementV);
position insert_value(TREE, ElementV);
ElementV delete_tree_node(position);

int is_root(position);
int is_leaf(position);
ElementV delete_leaf(position);
void insert_node_to_nonempty_tree(TREE, position);

/*
 * print values of the tree in sorted order
 */
void print_sorted_tree(TREE t)
{
    if (t == NULL)
    	return;
    	
    print_sorted_tree(t->lchild);
    printf("%d \r\n", t->element);
    print_sorted_tree(t->rchild);
}

/*
 * search for minimum value
 * traverse lchild
 */
position find_min(TREE t)
{
    position np;
    
    np = t;
    if (np == NULL)
    	return NULL;
    	
    while (np->lchild != NULL) {
        np = np->lchild;
    }
    
    return np;
}

/*
 * search for maximum value
 * traverse rchild
 */
position find_max(TREE t)
{
    position np;
    
    np = t;
    if (np == NULL)
    	return NULL;

    while (np->rchild != NULL) {
        np = np->rchild;
    }
    
    return np;
}

/*
 * search for value
 */
position find_tree_value(TREE t, ElementV v)
{
    if (t == NULL)
    	return NULL;

    if (t->element == v) {
        return t;
    }
    else if (v < t->element) {
        return find_tree_value(t->lchild, v);
    }
    else {
    	return find_tree_value(t->rchild, v);
    }
}

/*
 * insert the value to the tree
 */
position insert_value(TREE t, ElementV v)
{
	position np;
	
	np = (position)malloc(sizeof(struct node));
	if (np == NULL)
		return NULL;
	np->element = v;
	np->parent  = NULL;
	np->lchild  = NULL;
	np->rchild  = NULL;
	
	if (t == NULL)
		t = np;
	else {
		insert_node_to_nonempty_tree(t, np);
	}
	
	return t;
}

/*
 * delete the node
 */
ElementV delete_tree_node(position np)
{
	position n;
	ElementV v;
	
	if (is_leaf(np))
	{
		return delete_leaf(np);
	}
	else
	{
		n = (np->lchild != NULL) ? find_max(np->lchild) : find_min(np->rchild);
		v = np->element;
		np->element = delete_tree_node(n);
		
		return v;
	}
}

/*
 * is root?
 */
int is_root(position np)
{
	return (np->parent == NULL);
}

/*
 * is leaf?
 */
int is_leaf(position np)
{
	return ((np->lchild == NULL) && (np->rchild == NULL));
}

/*
 * delete the leaf
 */
ElementV delete_leaf(position np)
{
	ElementV value;
	position parent;
	
	value  = np->element;
	parent = np->parent;
	
	if (!is_root(np))
	{
		if (parent->lchild == np)
		{
			parent->lchild = NULL;
		}
		else
		{
			parent->rchild = NULL;
		}
	}
	free(np);
	
	return value;
}

/*
 * insert the node to the tree
 */
void insert_node_to_nonempty_tree(TREE t, position np)
{
	if (t == NULL)
		return;
		
	if (np->element <= t->element)
	{
		if (t->lchild == NULL)
		{
			t->lchild = np;
			np->parent = t;
			return;
		}
		else
		{
			insert_node_to_nonempty_tree(t->lchild, np);
		}
	}
	else if (np->element > t->element)
	{
		if (t->rchild == NULL)
		{
			t->rchild = np;
			np->parent = t;
			return;
		}
		else
		{
			insert_node_to_nonempty_tree(t->rchild, np);
		}
	}
}

/* for testing purpose */
void binary_search_tree_test()
{
    TREE tr;
    position np;
    ElementV element;
    
    tr = NULL;
    tr = insert_value(tr, 18);
    tr = insert_value(tr, 5);
    tr = insert_value(tr, 2); 
    tr = insert_value(tr, 8);
    tr = insert_value(tr, 81);
    tr = insert_value(tr, 101);
    printf("Original:\n");
    print_sorted_tree(tr);

    np = find_tree_value(tr, 8);
    if (np != NULL) {
        delete_tree_node(np);
        printf("After deletion:\n");
        print_sorted_tree(tr);
    }
    
    printf("=====================================================\r\n");
}
