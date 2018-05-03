#include <unistd.h>
#include <stdio.h>
#include "util.h"
#include "sort.h"
#include "list.h"

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
	
	return 0;
}
