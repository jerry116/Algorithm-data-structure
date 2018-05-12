#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "util.h"

/* 数字每个位数上由0~9组成，共10个 */
#define RADIX_BITMAX  10     //正整形位数

/*
 * 找到num的从低到高的第pos位的数据
 */
int get_num_inposition(int num, int pos)
{
    int temp = 1;
    
    for (int i = 0; i < pos - 1; i++)
        temp *= RADIX_BITMAX;
    
    return (num / temp) % RADIX_BITMAX;
}

/*
 * 基数排序, 时间复杂度O(dn)(d即表示最高位数
 */
void radix_sort(int a[], int ac)
{
	int pos;
	int i;
	int j;
	int k;
	int num;
	int index;
    int *radixArrays[RADIX_BITMAX];
    
    /* 初始化按照基数进行存放的数组 */
    for (i = 0; i < RADIX_BITMAX; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int) * (ac + 1));
        radixArrays[i][0] = 0;    /* index为0处记录这组数据的个数 */
    }
    
    for (pos = 1; pos <= RADIX_BITMAX; pos++)
    {
        /* 分配过程 */
        for (i = 0; i < ac; i++)
        {
            num = get_num_inposition(a[i], pos);
            index = ++radixArrays[num][0];
            radixArrays[num][index] = a[i];
        }
        
        /* 收集 */
        j = 0;
        for (i = 0; i < RADIX_BITMAX; i++)
        {
            for (k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }
    
    /* 释放按照基数进行存放的数组 */
    for (i = 0; i < RADIX_BITMAX; i++)
    {
        free(radixArrays[i]);
    }
}

int radix_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);
	
	start = clock();
	radix_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the radix sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int radix_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	radix_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	radix_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	radix_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}
