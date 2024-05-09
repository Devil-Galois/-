#include "MySort.h"
#include <stdlib.h>
#define LONG_N 1000
//插入排序
//begin
void Insert_Sort(int *array,int size)//ascending sort
{
	int temp,j;
	for (int i = 1; i < size; i++)
	{
		temp = array[i];
		for (j = i; j > 0 && temp < array[j - 1]; j--)
			array[j] = array[j - 1];
		array[j] = temp;
	}		
}
//end


//快速排序
//begin
void Quick_Sort(int* array, int size)
{
	QSort(array, 0, size - 1);
}

void QSort(int* array, int low, int high)
{
	int pivot;
	if (high > low)
	{
		while (high > low)
		{
			pivot = Partition(array, low, high);
			QSort(array, low, pivot - 1);
			low = pivot + 1;
		}
	}
}

int Partition(int* array, int low, int high)
{
	int pivotkey;
	//三数取中
	int mid = (low + high) / 2;
	if (array[low] > array[high])
		swap(array, low, high);
	if (array[mid] > array[high])
		swap(array, mid, high);
	if (array[mid] > array[low])
		swap(array, mid, low);
	pivotkey = array[low];
	int temp = pivotkey;
	while (low < high)
	{
		while (low < high && array[high] >= pivotkey)
			high--;
		array[low] = array[high];
		while (low < high && array[low] <= pivotkey)
			low++;
		array[high] = array[low];
	}
	array[low] = temp;
	return low;
}

//end


//归并排序
//begin
void Merge_Sort(int* array, int size)
{
	MSort(array, array, 0, size - 1);
}

void MSort(int* SR, int* TR1, int s, int t)
{
	int TR2[LONG_N];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		int m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}
void Merge(int* SR, int* TR, int i, int m, int n)
{
	int j, k, l;
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <=m)
	{
		for (l = 0; l <= m - i; l++)
			TR[k + l] = SR[l + i];
	}
	if (j <=n)
	{
		for (l = 0; l <= n - j; l++)
			TR[k + l] = SR[l + j];
	}
}




//end

//非递归的归并排序
//begin
void Merge_Sort_plus(int* array, int size)
{
	int* TR = (int*)malloc(sizeof(int) * size);
	if (!TR)
		exit(-1);
	int k = 1;
	while (k < size)
	{
		MergePass(array, TR, k, size);
		k = k * 2;
		MergePass(TR, array, k, size);
		k = k * 2;
	}
}

void MergePass(int* array, int* TR, int k, int size)
{
	int i=0;
	int j;
	while (i <=size - 2 * k)
	{
		Merge(array, TR, i, i + k - 1, i + 2 * k - 1);
		i += 2 * k;
	}
	if (i < size - k)
		Merge(array, TR, i, i + k - 1, size-1);
	else
		for (j = i; j < size; j++)
			TR[j] = array[j];
}
//end

//堆排序
//begin
void Heap_Sort(int* array, int size)
{
	int i;
	for (i = size / 2; i > 0; i--)	//先把所有元素构造成一个大顶堆
		HeapAdjust(array, i, size);

	for (i = size; i > 1; i--)
	{
		swap(array, i-1, 0);
		HeapAdjust(array, 1, i-1);
	}
}

void HeapAdjust(int* array, int low, int high)//把指定区间内的序列调整成大顶堆
{
	int temp, j;
	temp = array[low-1];
	for (j = 2 * low; j <=high; j *= 2)
	{
		if (j < high && array[j - 1] < array[j])
			j++;
		if (temp >= array[j-1])
			break;
		array[low - 1] = array[j-1];
		low= j;
	}
	array[low - 1] = temp;
}
//end

//希尔排序
//begin
void Shell_Sort(int* array, int size)
{
	int i, j;
	int temp;
	int increment = size;
	do
	{
		increment = increment / 3 + 1;
		for (i = increment; i < size; i++)
		{
			if (array[i] < array[i - increment])
			{
				temp = array[i];
				for (j = i - increment; j >= 0 && temp < array[j]; j -= increment)
					array[j + increment] = array[j];
				array[j + increment] = temp;
			}
		}
	} while (increment > 1);
}
//end


void swap(int* array, int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}


