#include <unistd.h>
#include <stdio.h>
#include "util.h"
#include "sort.h"

int main()
{	
	bubble_sort_test_all();
	insert_sort_test_all();
	quick_sort_test_all();
	select_sort_test_all();
	shell_sort_test_all();
	merge_sort_test_all();
	heap_sort_test_all();

	return 0;
}
