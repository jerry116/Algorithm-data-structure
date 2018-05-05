#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "util.h"

void max_heapify(int a[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	
	while (son <= end)
	{
		if ((son + 1 <= end) && (a[son] < a[son + 1]))
			son++;

		if (a[dad] > a[son])
			return;
		else
		{
			swap(a + dad, a + son);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
/*
 * 将待排序的序列构造成一个最大堆，此时序列的最大值为根节点依次将根节点与待排序序列的
 * 最后一个元素交换再维护从根节点到该元素的前一个节点为最大堆，
 * 如此往复，最终得到一个递增序列
 */
void heap_sort(int a[], int ac)
{
    int i;
    
    for (i = ac/2 - 1; i >=0; i--)
    	max_heapify(a, i, ac - 1);
    
    for (i = ac - 1; i > 0; i--)
    {
    	swap(a, a + i);
    	max_heapify(a, 0, i - 1);
    }
}

int heap_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);
	
	heap_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the heap sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int heap_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	heap_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	heap_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	heap_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}
