#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

/* 
 * 冒泡排序时，计算机从右向左遍历数组，比较相邻的两个元素。如果两个元素的顺序是错的，那么sorry，请两位互换。
 * 如果两个元素的顺序是正确的，则不做交换。经过一次遍历，我们可以保证最小的元素(泡泡)处于最左边的位置。
 */
void bubble_sort(int a[], int ac)
{
    int i,j;
    int sign;
    
    for (j = 0; j < ac-1; j++) {
        sign = 0;
        for(i = ac-1; i > j; i--) {
            if(a[i-1] > a[i]) {
                sign = 1;
                swap(a+i, a+i-1);
            }
        }
        if (sign == 0)
        	break;
    }
}

int bubble_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;
	
	print_info(a, ac);
	
	start = clock();
	bubble_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the bubble sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int bubble_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	bubble_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	bubble_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	bubble_sort_test(a3, ac);
	printf("=====================================================\r\n");
	
	return 0;
}
