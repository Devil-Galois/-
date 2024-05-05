#include "SearchTree.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	DataType arr[] = { 18,10,25,16,20,8,42,9,15,32, 78, 39 };
	pNode T=NULL;
	MakeEmpty(&T);  //�����
	//��������
	for (int j = 0; j < 12; j++)
		Insert(arr[j], &T);
	InOrderTraverse_Recursion(&T);
	printf("\n");
	//�����ֵ
	printf("Max:%d\n", GetValue(FindMax(T)));
	//����Сֵ
	printf("Min:%d\n", GetValue(FindMin(T)));
	//ɾ����
	//ɾ��9
	DeleteElement(9, &T);
	InOrderTraverse_Recursion(&T);
	printf("\n");
	//����9
	Insert(9, &T);
	//ɾ��8
	DeleteElement(8, &T);
	InOrderTraverse_Recursion(&T);
	printf("\n");
	//����8
	Insert(8, &T);
	//ɾ��10
	DeleteElement(10, &T);
	InOrderTraverse_Recursion(&T);
	return 0;
}