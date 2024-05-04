#include "BiTree.h"
#include <stdlib.h>
#include <stdio.h>

//前序建立二叉树
BiTree PreOrderCreateBiTree(DataType* *array)
{
	BiTree T = NULL;
	if (*(*array) != '*')
	{
		if (!(T = (BiTree)malloc(sizeof(BiTNode))))
			exit(-1);
		T->data = *(*array);
		(*array)++;
		T->lchild = PreOrderCreateBiTree(array);
		T->rchild = PreOrderCreateBiTree(array);
	}
	else (*array)++;
	return T;
}

//递归前序遍历二叉树
void PreOrderTraverse_Recursion(BiTree* pRoot)
{
	if (*pRoot == NULL)
	{
		printf("* ");
		return;
	}
	else 	Operation(*pRoot);
	PreOrderTraverse_Recursion(&((*pRoot)->lchild));
	PreOrderTraverse_Recursion(&((*pRoot)->rchild));
	return;
}
//递归中序遍历二叉树
void InOrderTraverse_Recursion(BiTree* pRoot)
{
	if (*pRoot == NULL)
	{
		printf("* ");
		return;
	}
	else InOrderTraverse_Recursion(&((*pRoot)->lchild));
	Operation(*pRoot);
	InOrderTraverse_Recursion(&((*pRoot)->rchild));
	return;
}
//递归后序遍历二叉树
void PostOrderTraverse_Recursion(BiTree* pRoot)
{
	if (*pRoot == NULL)
	{
		printf("* ");
		return;
	}
	else PostOrderTraverse_Recursion(&((*pRoot)->lchild));
	PostOrderTraverse_Recursion(&((*pRoot)->rchild));
	Operation(*pRoot);
	return;
}

//非递归前序遍历二叉树
void PreOrderTraverse(BiTree* pRoot)
{
	if (*pRoot == NULL)
		return;
	Stack S = InitStack();
	BiTree p = *pRoot;
	while (p != NULL||!IsEmpty(S))
	{
		if (p != NULL)
		{
			printf("%c ", p->data);
			Push(p, S);
			p = p->lchild;
		}
		else if (!IsEmpty(S))
		{
			printf("* ");
			p = Pop(S);
			p = p->rchild;
		}
	}
	printf("* ");
	DestroyStack(S);
}
//非递归中序遍历二叉树
void InOrderTraverse(BiTree* pRoot)
{
	if (!*pRoot)
		return;
	Stack S = InitStack();
	BiTree p = *pRoot;
	while (p != NULL || !IsEmpty(S))  
	{
		while (p)						//定位到此子树的最左结点同时压栈路径结点
		{	
			Push(p, S);
			p = p->lchild;
		}
		printf("* ");                   //到最左之后退栈
		p = Pop(S);
		printf("%c ", p->data);          //打印最近的子树的根
		p = p->rchild;				//再把子树的右子树作为子树遍历
	}
	printf("* ");
	DestroyStack(S);
}
//非递归后序遍历二叉树
void PostOrderTraverse(BiTree* pRoot)
{
	if (!*pRoot)
		return;
	Stack S = InitStack();
	Stack Data = InitStack();
	BiTree p = *pRoot;
	while (p||!IsEmpty(Data)||!IsEmpty(S))
	{
		if (p != NULL)
		{
			while (p)
			{
				Push(p, S);
				Push(p, Data);
				p = p->lchild;				//定位到最左结点
			}
			printf("* ");					//左节点空
			p = Pop(S);						//退栈到最近子树
			p = p->rchild;					//遍历最近子树的右子树
		}
		if (!p)
		{
			printf("* ");
			while (GetTop(S) != GetTop(Data))
				printf("%c ", Pop(Data)->data);
			if (!IsEmpty(S))
			{
				p = Pop(S);
				p = p->rchild;
			}
		}
	}
	DestroyStack(S);
	DestroyStack(Data);
}

//后序销毁一棵二叉树并释放所有空间
BiTree DestroyBiTree(BiTree* pRoot)
{
	BiTree t = *pRoot;
	if (t == NULL)
		return;
	if (t->lchild != NULL) {
		DestroyBiTree(&(t->lchild));
		t->lchild = NULL;
	}
	if (t->rchild != NULL) {
		DestroyBiTree(&(t->rchild));
		t->rchild = NULL;
	}
	if (t != NULL) {
		free(t);
		t = NULL;
	}
}

//对二叉树进行指定操作的函数
void Operation(BiTree p)
{
	printf("%c ", p->data);
}


//初始化栈
Stack InitStack()
{
	Stack pS = NULL;
	if (!(pS = (Stack)malloc(sizeof(S_top))))
		exit(-1);
	pS->next = NULL;
	return pS;
}

//压栈
void Push(BiTree p, Stack pS)
{
	Stack S = NULL;
	if (!(S = (Stack)malloc(sizeof(S_top))))
		exit(-1);
	S->data = p;
	S->next = pS->next;
	pS->next = S;
}
//出栈
BiTree Pop(Stack pS)
{
	BiTree temp=NULL;
	Stack S = NULL;
	if (IsEmpty(pS))
		return NULL;
	else
	{
		S = pS->next;
		pS->next = S->next;
		temp = S->data;
		free(S);
		return temp;
	}
}
//检查空栈
bool IsEmpty(Stack pS)
{
	return pS->next == NULL;
}

//获取栈顶元素
BiTree GetTop(Stack pS)
{
	Stack S = NULL;
	BiTree Temp=NULL;
	if (IsEmpty(pS))
		return NULL;
	else
	{
		S = pS->next;
		Temp = S->data;
	}
	return Temp;
}
//销毁栈
void DestroyStack(Stack pS)
{
	while (pS->next != NULL)
		Pop(pS);
	free(pS);
	return;
}