#include "SearchTree.h"
#include <stdlib.h>
#include <stdio.h>


//��ղ�����
void MakeEmpty(pNode *pRoot)
{
	if (!*pRoot)
		return;
	else
	{
		MakeEmpty(&((*pRoot)->lchild));
		MakeEmpty(&((*pRoot)->rchild));
		free(*pRoot);
	}
	return;
}
//����ĳ��Ԫ��
pNode Find(DataType element, pNode pRoot)//������������ʵ��
{
	if (!pRoot)
		return NULL;
	else if (element > pRoot->data)
		Find(element, pRoot->rchild);
	else if (element < pRoot->data)
		Find(element, pRoot->lchild);
	else return pRoot;
}
//�������ֵ
pNode FindMax(pNode pRoot)  //���������ҽڵ�
{
	pNode p = pRoot;
	if (!p)
		return NULL;
	else while (p->rchild)
	{
		p = p->rchild;
	}
	return p;
}
//������Сֵ
pNode FindMin(pNode pRoot)
{
	pNode p = pRoot;
	if (!p)
		return NULL;
	else while (p->lchild)
	{
		p = p->lchild;
	}
	return p;
}
//������ֵ
bool Insert(DataType element, pNode *pRoot)
{
	if (!(*pRoot))
	{
		if (!((*pRoot) = (pNode)malloc(sizeof(Node))))
			exit(-1);
		(*pRoot)->data = element;
		(*pRoot)->lchild = (*pRoot)->rchild = NULL;
	}
	else if (element < (*pRoot)->data)
		Insert(element, &((*pRoot)->lchild));
	else if (element > (*pRoot)->data)
		Insert(element, &((*pRoot)->rchild));
	else return false;
	return true;
}
//ɾ��������
bool  DeleteElement(DataType element, pNode* pRoot)
{
	pNode pMin=NULL,q=NULL;
	if (!(*pRoot))
	{
		printf("The element isn't exist!\n");
		return false;
	}
	else if (element < (*pRoot)->data)
		DeleteElement(element, &((*pRoot)->lchild));
	else if (element > (*pRoot)->data)
		DeleteElement(element, &((*pRoot)->rchild));
	else                                       //�ҵ�Ҫɾ���Ľ��
	{
		if ((*pRoot)->lchild && (*pRoot)->rchild)    //���������������
		{
			q = *pRoot;
			pMin = (*pRoot)->rchild;
			while (pMin->lchild)
			{
				q = pMin;
				pMin = pMin->lchild;				//�ҵ���������С��
			}
			(*pRoot)->data = pMin->data;
			q->lchild= pMin->rchild;
			free(pMin);//����������ɾ������ظ�����Сֵ
		}
		else                                  //�����û���ӻ���ֻ��һ������
		{
			pNode Temp = *pRoot;
			if ((*pRoot)->lchild == NULL)
				(*pRoot) = (*pRoot)->rchild;
			else if ((*pRoot)->rchild == NULL)
				*pRoot = (*pRoot)->rchild;
			free(Temp);
		}
		return true;
	}
}
//��ȡֵ
DataType GetValue(pNode p)
{
	return p->data;
}

//ɾ����ɾ����㣨���������ӣ�����������С���
pNode DeleteMin(pNode* pMin)
{
	pNode Temp = *pMin;
	*pMin = (*pMin)->rchild;
	free(Temp);
	return *pMin;
}

//�������
void InOrderTraverse_Recursion(pNode* pRoot)
{
	if (*pRoot == NULL)
	{
		return;
	}
	else InOrderTraverse_Recursion(&((*pRoot)->lchild));
	printf("%d ", (*pRoot)->data);
	InOrderTraverse_Recursion(&((*pRoot)->rchild));
	return;
}

