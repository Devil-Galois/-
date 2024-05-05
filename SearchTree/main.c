#include "SearchTree.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	DataType arr[] = { 18,10,25,16,20,8,42,9,15,32, 78, 39 };
	pNode T=NULL;
	MakeEmpty(&T);  //清空树
	//插入数据
	for (int j = 0; j < 12; j++)
		Insert(arr[j], &T);
	InOrderTraverse_Recursion(&T);
	printf("\n");
	//找最大值
	printf("Max:%d\n", GetValue(FindMax(T)));
	//找最小值
	printf("Min:%d\n", GetValue(FindMin(T)));
	//删除点
	//删除9
	DeleteElement(9, &T);
	InOrderTraverse_Recursion(&T);
	printf("\n");
	//插入9
	Insert(9, &T);
	//删除8
	DeleteElement(8, &T);
	InOrderTraverse_Recursion(&T);
	printf("\n");
	//插入8
	Insert(8, &T);
	//删除10
	DeleteElement(10, &T);
	InOrderTraverse_Recursion(&T);
	return 0;
}