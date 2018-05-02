#include <unistd.h>
#include <stdio.h>

void swap(int *pa, int *pb)
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void print_a(int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%3d ", a[i]);
	}
	printf("\r\n");
}

void print_info(int a[], int len)
{
	//printf("The array's length is %d\r\n", len);
	printf("The origin array is:\r\n");
	print_a(a, len);
}
