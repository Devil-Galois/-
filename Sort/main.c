#include<assert.h>
#include<stdio.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include <stdlib.h>
#include <time.h>
#include "MySort.h"

#define LONG_N 1000

int cmp(const void*a, const void*b)//ascending order
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i;
	int array_long[LONG_N];
	int num = 10;
	while (num--)
	{
		for (i = 0; i < LONG_N; ++i)
		{
			array_long[i] = (int)(rand());
		}
		int array_long_target[LONG_N];
		int array_long_test[LONG_N];
		memcpy(array_long_target, array_long, LONG_N * sizeof(int));
		memcpy(array_long_test, array_long, LONG_N * sizeof(int));
		qsort(array_long_target, LONG_N, sizeof(int), cmp);
		Shell_Sort(array_long_test, LONG_N);   //此处修改进行测试的排序算法
		for (i = 0; i < LONG_N; ++i)
		{
			assert(array_long_test[i] == array_long_target[i]);
		}	
	}
	printf("100!\n");
	return 0;
}
