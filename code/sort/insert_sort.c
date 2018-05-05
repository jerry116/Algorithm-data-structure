#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

/*
 * 假设在新生报到的时候，我们将新生按照身高排好队(也就是排序)。如果这时有一名学生加入，我们将该名学生加入到队尾。
 * 如果这名学生比前面的学生低，那么就让该学生和前面的学生交换位置。这名学生最终会换到应在的位置。这就是插入排序的基本原理。
 * 对于起始数组来说，我们认为最初，有一名学生，也就是最左边的元素(i=0)，构成一个有序的队伍。
 * 随后有第二个学生(i=1)加入队伍，第二名学生交换到应在的位置；随后第三个学生加入队伍，
 * 第三名学生交换到应在的位置…… 当n个学生都加入队伍时，我们的排序就完成了。
 */
void insert_sort(int a[], int ac)
{
    int i;
    int j;
    
    for (j = 1; j <= ac-1; j++) {
        i = j - 1;
        while ((i >= 0) && (a[i + 1] < a[i]))
        {
            swap(a+i+1, a+i);
            i--;
        }
    }
}

int insert_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);
	
	insert_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the insert sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int insert_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	insert_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	insert_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	insert_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}