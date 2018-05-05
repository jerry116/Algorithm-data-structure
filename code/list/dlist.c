#include <stdio.h>
#include <stdlib.h>

typedef int item; 
typedef struct node *pnode; 
typedef struct node *position;

/* node，节点 */
struct node {
    item element;
    position prev;
    position next;
};

typedef struct list {
	pnode head;
	pnode tail;
	int size;
} DLIST;

/*分配值为i的节点，并返回节点地址*/
position make_node(item i);

/*释放p所指的节点*/
void free_node(pnode p);

/*构造一个空的双向链表*/
DLIST* init_dlist();

/*摧毁一个双向链表*/
void delete_dlist(DLIST *plist);

/*返回头节点地址*/
position get_head(DLIST *plist);

/*返回尾节点地址*/
position get_tail(DLIST *plist);

/*返回链表大小*/
int get_size(DLIST *plist);

/*返回p的直接后继位置*/
position get_next(position p);

/*返回p的直接前驱位置*/
position get_previous(position p);

/*打印表*/
void print_dlist(DLIST *plist);

/*判断链表是否为空表*/
int is_empty(DLIST *plist);

/*将一个链表置为空表，释放原链表节点空间*/
void clear_list(DLIST *plist);

/*将pnode所指节点插入第一个节点之前*/
pnode insert_first(DLIST *plist, pnode node);

/*将链表第一个节点删除并返回其地址*/
pnode delete_first(DLIST *plist);

/*获得节点的数据项*/
item get_item(position p);

/*设置节点的数据项*/
void set_item(position p, item i);

/*删除链表中的尾节点并返回其地址，改变链表的尾指针指向新的尾节点*/
pnode Remove(DLIST *plist);

/*在链表中p位置之前插入新节点S*/
pnode insert_before(DLIST *plist, position p, pnode s);

/*在链表中p位置之后插入新节点s*/
pnode insert_after(DLIST *plist, position p, pnode s);

/*返回在链表中第i个节点的位置*/
pnode locate_pos(DLIST *plist, int i);

/*依次对链表中每个元素调用函数visit()*/
void list_traverse(DLIST *plist, void (*visit)());

/*分配值为i的节点，并返回节点地址*/
position make_node(item i)
{
	position ptemp = NULL;
	
	ptemp = malloc(sizeof(position));
	if (ptemp != NULL)
	{
		ptemp->element = i;
		ptemp->prev = NULL;
		ptemp->next = NULL;
	}
	
	return ptemp;
}

/*释放p所指的节点*/
void free_node(pnode p)
{
	free(p);
}

/*构造一个空的双向链表*/
DLIST* init_dlist()
{
	DLIST *plist;
	pnode head;
	
	plist = malloc(sizeof(DLIST));
	head  = make_node(0);
	if (plist != NULL)
	{
		if (head != NULL)
		{
			plist->head = head;
			plist->tail = head;
			plist->size = 0;
		}
		else
			return NULL;
	}
	
	return plist;
}

/*摧毁一个双向链表*/
void delete_dlist(DLIST *plist)
{
	clear_list(plist);  
    free(get_head(plist));  
    free(plist); 
}

/*返回头节点地址*/
position get_head(DLIST *plist)
{
	if (plist == NULL)
		return NULL;
	
	return plist->head;
}

/*返回尾节点地址*/
position get_tail(DLIST *plist)
{
	if (plist == NULL)
		return NULL;
	
	return plist->tail;
}

/*返回链表大小*/
int get_size(DLIST *plist)
{
	if (plist == NULL)
		return 0;
	
	return plist->size;
}

/*返回p的直接后继位置*/
position get_next(position p)
{
	if (p == NULL)
		return NULL;
	
	return p->next;
}

/*返回p的直接前驱位置*/
position get_previous(position p)
{
	if (p == NULL)
		return NULL;
	
	return p->prev;
}

/*
 * Traverse the list and print each element
 * 打印表
 */
void print_dlist(DLIST *plist)
{
    position np;
    
    if (is_empty(plist)) {
        printf("Empty List\r\n");
        return;
    }

    np = plist->tail;
    while (np->next != NULL) { 
        np = np->next;
        printf("%p: %3d -->\r\n", np, np->element);
    }
    printf("\r\n");
}

void print_node(item i)
{
    printf("%3d\r\n", i);
}

/*判断链表是否为空表*/  
int is_empty(DLIST *plist)  
{  
    if ((get_size(plist) == 0) && (get_tail(plist) == get_head(plist)))
        return 1;  
    else  
        return 0;  
}

/*将一个链表置为空表，释放原链表节点空间*/
void clear_list(DLIST *plist)
{
	pnode temp;
	pnode p;
	
	if (plist == NULL)
		return;
 
    p = get_tail(plist);
    while (!is_empty(plist))
    {
        temp = get_previous(p);
        free_node(p);
        p = temp;
        plist->tail = temp;
        plist->size--;
    }
}

/*将pnode所指节点插入第一个节点之前*/
pnode insert_first(DLIST *plist, pnode node)
{
	pnode head;
	
	if (is_empty(plist))
	{
		plist->tail = node;
	}
	plist->size++;
	
	head = get_head(plist);
	node->next = head->next;
	node->prev = head;
	
	if (head->next != NULL)
		head->next->prev = node;
	head->next = node;
	
	return node;
}

/*将链表第一个节点删除并返回其地址*/
pnode delete_first(DLIST *plist)
{
	position head;
	position p;
	
	if (plist == NULL)
		return NULL;
	
	head = get_head(plist);
	if (head == NULL)
		return NULL;
	
	p = head->next;
	if (p != NULL)
	{
		head->next = p->next;
		head->next->prev = head;
		plist->size--;
	}

	return p;
}

/*获得节点的数据项*/
item get_item(position p)
{
	if (p == NULL)
		return 0;
	
	return p->element;
}

/*设置节点的数据项*/
void set_item(position p, item i)
{
	if (p == NULL)
		return;
	
	p->element = i;
}

/*删除链表中的尾节点并返回其地址，改变链表的尾指针指向新的尾节点*/
pnode Remove(DLIST *plist)
{
	position p = NULL;
	
	if (is_empty(plist))
		return NULL;
	else
	{
		p = get_tail(plist);
		p->prev->next = p->next;
		plist->tail = p->prev;
		plist->size--;
		
		return p;
	}
}

/*在链表中p位置之前插入新节点S*/
pnode insert_before(DLIST *plist, position p, pnode s)
{
	s->prev = p->prev->next;
	s->next = p;
	p->prev->next = s;
	p->prev = s;
	
	plist->size++;
	
	return s;
}

/*在链表中p位置之后插入新节点s*/
pnode insert_after(DLIST *plist, position p, pnode s)
{
	s->prev = p;
	s->next = p->next;
	
	if (p->next != NULL)
		p->next->prev = s;
	p->next = s;
	
	if (p = get_tail(plist))
		plist->tail = s;
		
	plist->size++;
	
	return s;
}

/*返回在链表中第i个节点的位置*/
pnode locate_pos(DLIST *plist, int i)
{
	int count = 0;
	position p;
	
	if ((i > get_size(plist)) || (i < 1))
		return NULL;
		
	p = get_head(plist);
	while (++count <= i)
		p = p->next;
		
	return p;
}

/*依次对链表中每个元素调用函数visit()*/
void list_traverse(DLIST *plist, void (*visit)())
{
	position p;
	
	if (is_empty(plist))
		return;
	else
	{
		p = get_head(plist);
		while (p->next != NULL)
		{
			p = p->next;
			visit(p->element);
		}
	}	
}

/* for testing purpose */
void dlist_test()
{
    DLIST *plist = NULL;  
    pnode p = NULL;  
      
    plist = init_dlist();  
    p = insert_first(plist, make_node(1));  
    insert_before(plist, p, make_node(2));  
    insert_after(plist, p, make_node(3));  
  
    printf("p前驱位置的值为%d\r\n", get_item(get_previous(p)));  
    printf("p位置的值为%d\r\n", get_item(p));  
    printf("p后继位置的值为%d\r\n", get_item(get_next(p)));  
      
    printf("遍历输出各节点数据项:\r\n");  
    list_traverse(plist, print_node);  
    printf("除了头节点该链表共有%d个节点\r\n", get_size(plist));  
    free_node(delete_first(plist));  
    printf("删除第一个节点后重新遍历输出为:\r\n");  
    list_traverse(plist, print_node);  
    printf("除了头节点该链表共有%d个节点\r\n", get_size(plist));  
    delete_dlist(plist);  
    printf("链表已被销毁\r\n");  
    
    printf("=====================================================\r\n");
}
