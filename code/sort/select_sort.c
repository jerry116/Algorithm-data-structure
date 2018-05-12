#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

/*
 * 选择排序是先找到起始数组中最小的元素，将它交换到i=0；
 * 然后寻找剩下元素中最小的元素，将它交换到i=1的位置…… 直到找到第二大的元素，将它交换到n-2的位置。
 * 这时，整个数组的排序完成。
 */
void select_sort(int a[], int ac)
{
    int i;
    int j;
    int min_index;
    
    for (i = 0; i < ac - 1; i++)
    {
        min_index = i;
    	for (j = i + 1; j <= ac - 1; j++)
    	{
    		if (a[j] < a[min_index])
    		{
    		    min_index = j;
    		}
    	}
    	
    	if (min_index != i)
    	{
    		swap(a+i, a+min_index);
    	}
    }
}

int select_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);
	
	start = clock();
	select_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the select sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int select_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	select_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	select_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	select_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}
