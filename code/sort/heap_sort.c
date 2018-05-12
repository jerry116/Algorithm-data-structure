#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "util.h"

/* 
 * 如果A[i]表示树的某个结点，则A[2*i]是其左孩子，A[2*i+1]是其右孩子。
 */
void max_heapify(int a[], int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	
	while (son <= end) /* 若子节点在范围内才能做比较 */
	{
		/* 先比较两个子节点的大小，选择最大的 */
		if ((son + 1 <= end) && (a[son] < a[son + 1]))
			son++;

		/* 如果父节点大于子节点则调整完毕，直接跳出函數 */
		if (a[dad] > a[son])
			return;
		/* 否则交换父子内容再继续子节点和孙节点比较 */
		else {
			swap(a + dad, a + son);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

/*
 * 建堆过程是对非叶子节点从下向上调用最大堆保持
 */
void build_max_heap(int a[], int ac)
{
	int i;
	
	/* 初始化，i从最后一个父节点开始调整 */
    for (i = ac/2 - 1; i >= 0; i--)
        max_heapify(a, i, ac - 1);
}
/*
 * 最大堆的特点：对于随意某个结点，该结点的值大于左孩子、右孩子的值，可是左右孩子的值没有要求。
 * 堆排序，不过是把待排序数组[0,n]抽象成堆；对这颗树从最底层节点依次向上，调用最大堆保持子流程，
 * 具体的细节是：最大堆中最大元素存储在A[0]了，交换A[0],A[n]则最大元素存储到A[n]了，
 * 把A[n]移出堆，并对[0,n-1]调用最大堆保持子流程。循环到堆大小为1时数据排序完成了。
 * 使用对进行排序的过程是先对数组建堆，然后交换最大元素到末尾，并减小堆大小，
 * 调用最大堆保持函数使得新堆恢复成最大堆，循环交换出最大元素，最后得到排序数组。
 */
void heap_sort(int a[], int ac)
{
    int i;
    
    build_max_heap(a, ac);
    
    /* 先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕 */
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
	
	start = clock();
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
