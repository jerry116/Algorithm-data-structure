#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

/*
 * 希尔排序是以更大的间隔来比较和交换元素，这样，大的元素在交换的时候，可以向右移动不止一个位置，从而更快的移动乌龟元素。
 * 比如，可以将数组分为4个子数组（i=4k, i=4k+1, i=4k+2, i=4k+3），对每个子数组进行冒泡排序。
 * 比如子数组i=0，4，8，12...。此时，每次交换的间隔为4。完成对四个子数组的排序后，数组的顺序并不一定能排列好。
 * 希尔排序会不断减小间隔，重新形成子数组，并对子数组冒泡排序…… 当间隔减小为1时，就相当于对整个数组进行了一次冒泡排序。
 * 随后，数组的顺序就排列好了。
 * 希尔排序不止可以配合冒泡排序，还可以配合其他的排序方法完成。
 */
void shell_sort(int a[], int ac)
{
    int i;
    int j;
    int step;
    int flag;
    
    step = ac;
    while (step > 1)
    {
     	step /= 2;
     	do {
     	    flag = 0;
     	    for (i = 0; i < ac - step; i++)
     	    {
     	        j = i + step;
     	        if (a[j] < a[i])
     	        {
     	            swap(a + i, a + j);
     	            flag = 1;
     	        }
     	    }
     	} while (flag != 0);
    }
}

int shell_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);
	
	shell_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the shell sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int shell_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	shell_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	shell_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	shell_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}

