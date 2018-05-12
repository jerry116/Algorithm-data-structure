#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

/*
 * 快速排序的基本思想是
 * 1、先从数列中取出一个数作为基准数
 * 2、分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边
 * 3、再对左右区间重复第二步，直到各区间只有一个数
 */
void quick_sort(int a[], int ac)
{
    int i;
    int j;
    int pivot;
    
	if (ac < 2)
		return;
		
	/* choose the middle element as the pivot */
	pivot = a[ac/2];
	
	/* let the smaller in the left of the pivot, and the bigger in the right of the pivot */
	for (i = 0, j = ac - 1; ; i++, j--)
	{
		while (a[i] < pivot)
			i++;
			
		while (a[j] > pivot)
			j--;
			
		if (i >= j)
			break;
		
		swap(a+i, a+j);
	}
	
	quick_sort(a, i);
	quick_sort(a+i, ac-i);
}

void quick_sort1(int a[], int ac)
{
    int pivot;
    int compare;
    
    /* choose the middle one as the pivot, and stored it in a[0] */
    swap(a + 0, a + ac/2);
    pivot = 1;

    /* compare all the element */
    for (compare = 1; compare < ac; compare++)
    {
        if (a[compare] < a[0])
        {
        	swap(a + compare, a + pivot);
        	pivot++;
        }
    }

    /* swap an element (which <= pvalue) with a[0] */
    swap(a + 0, a + pivot - 1);
    
    if (ac <= 2) {
        return;
    }
    else {
    	quick_sort1(a, pivot);
    	quick_sort1(a + pivot, ac - pivot);
    }
}

int quick_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);

	start = clock();
	quick_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the quick sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int quick_sort1_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);

	start = clock();
	quick_sort1(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the quick sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int quick_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	quick_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	quick_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	quick_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}

int quick_sort1_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	quick_sort1_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	quick_sort1_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	quick_sort1_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}
