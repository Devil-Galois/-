#pragma once
#ifndef __MySort_H__
#define __MySort_H__

#include<stdio.h>
#include<stdlib.h>
//排序函数
//begin
void Insert_Sort(int *array,int size);
void Merge_Sort(int* array, int size);
void Quick_Sort(int* array, int size);
void Merge_Sort_plus(int* array, int size);
void Heap_Sort(int* array, int size);
void Shell_Sort(int* array, int size);
//end


//需要用的函数
//begin
void HeapAdjust(int* array, int low, int high);
void MergePass(int* array, int* TR, int k, int size);
void MSort(int* SR, int* TR1, int s, int t);
void Merge(int* SR, int* TR, int i, int m, int n);
void QSort(int* array, int low, int high);
int Partition(int* array, int low, int high);
void swap(int* array, int i, int j);
//end






#endif //sort 
