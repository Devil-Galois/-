#include "SearchTree.h"
#include <stdlib.h>
#include <stdio.h>


//清空查找树
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
//查找某个元素
pNode Find(DataType element, pNode pRoot)//借助于树有序实现
{
	if (!pRoot)
		return NULL;
	else if (element > pRoot->data)
		Find(element, pRoot->rchild);
	else if (element < pRoot->data)
		Find(element, pRoot->lchild);
	else return pRoot;
}
//查找最大值
pNode FindMax(pNode pRoot)  //遍历到最右节点
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
//查找最小值
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
//插入新值
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
//删除存在项
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
	else                                       //找到要删除的结点
	{
		if ((*pRoot)->lchild && (*pRoot)->rchild)    //结点上有两个孩子
		{
			q = *pRoot;
			pMin = (*pRoot)->rchild;
			while (pMin->lchild)
			{
				q = pMin;
				pMin = pMin->lchild;				//找到右子树最小点
			}
			(*pRoot)->data = pMin->data;
			q->lchild= pMin->rchild;
			free(pMin);//从右子树中删除这个重复的最小值
		}
		else                                  //结点上没孩子或者只有一个孩子
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
//获取值
DataType GetValue(pNode p)
{
	return p->data;
}

//删除待删除结点（有两个儿子）右子树的最小结点
pNode DeleteMin(pNode* pMin)
{
	pNode Temp = *pMin;
	*pMin = (*pMin)->rchild;
	free(Temp);
	return *pMin;
}

//中序遍历
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

