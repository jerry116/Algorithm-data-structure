#include <unistd.h>
#include <stdio.h>
#include "util.h"
#include "sort.h"
#include "list.h"
#include "tree.h"

int main()
{	
	bubble_sort_test_all();
	insert_sort_test_all();
	quick_sort_test_all();
	select_sort_test_all();
	shell_sort_test_all();
	merge_sort_test_all();
	heap_sort_test_all();

	slist_test();
	stack_test();
	queue_test();
	dlist_test();
	
	binary_search_tree_test();
	binary_balance_tree_test();
	splay_tree_test();
	leftist_heap_test();
	
	return 0;
}
