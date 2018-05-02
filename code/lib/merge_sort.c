#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "util.h"
#include "sort.h"

/*
 * 如果我们要将一副扑克按照数字大小排序。此前已经有两个人分别将其中的一半排好顺序。
 * 那么我们可以将这两堆扑克向上放好，假设小的牌在上面。此时，我们将看到牌堆中最上的两张牌。
 * 我们取两张牌中小的那张取出放在手中。两个牌堆中又是两张牌暴露在最上面，继续取小的那张放在手中…… 
 * 直到所有的牌都放入手中，那么整副牌就排好顺序了。这就是归并排序。
 */
void merge_sort(int a[], int ac)
{
    int i;
    int j;
    int k;
    int *ah1;
    int *ah2;
    int ac1;
    int ac2;
    int *pmerge;
    
    ac1 = ac/2;
    ac2 = ac - ac1;
    ah1 = a;
    ah2 = a + ac1;
    
    merge_sort(ah1, ac1);
    merge_sort(ah2, ac2);
    
    /* merge */
    i = 0;
    j = 0;
    k = 0;
    pmerge = (int *)malloc(sizeof(int) * ac);
    if (pmerge == NULL)
    	return;
    
    while ((i < ac1) && (j < ac2))
    {
        if (ah1[i] <= ah2[j])
        {
        	pmerge[k++] = ah1[i++];
        }	
       	else
       	{
       	    pmerge[k++] = ah2[j++];
        }
    }
    
    while (i < ac1)
    {
        pmerge[k++] = ah1[i++];
    }
    
    while (j < ac2)
    {
        pmerge[k++] = ah2[j++];
    }
    
    /* copy back */
    for (i = 0; i < ac; i++)
    {
        a[i] = pmerge[i];
    }
    
    free(pmerge);
}

int merge_sort_test(int a[], int ac)
{
	clock_t start,finish;
    double totaltime;

	print_info(a, ac);
	
	select_sort(a, ac);
	finish = clock();
	totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
	
	printf("After the merge sorting\r\n");
	print_a(a, ac);
	
	printf("程序运行的时间为: %.8f 秒\r\n", totaltime);
	
	return 0;
}

int merge_sort_test_all(void)
{
	int ac;
	int a1[] = {10,3,6,1,5,8,13,2,9,14,20,7};
	int a2[] = {1,2,3,5,6,7,8,9,10,13,14,20};
	int a3[] = {20,14,13,10,9,8,7,6,5,3,2,1};
	
	ac = sizeof(a1)/sizeof(a1[0]);
	merge_sort_test(a1, ac);
	
	ac = sizeof(a2)/sizeof(a2[0]);
	merge_sort_test(a2, ac);
	
	ac = sizeof(a3)/sizeof(a3[0]);
	merge_sort_test(a3, ac);
	
	printf("=====================================================\r\n");
	
	return 0;
}
