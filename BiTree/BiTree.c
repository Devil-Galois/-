#include "BiTree.h"
#include <stdlib.h>
#include <stdio.h>

//ǰ����������
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

//�ݹ�ǰ�����������
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
//�ݹ��������������
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
//�ݹ�������������
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

//�ǵݹ�ǰ�����������
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
//�ǵݹ��������������
void InOrderTraverse(BiTree* pRoot)
{
	if (!*pRoot)
		return;
	Stack S = InitStack();
	BiTree p = *pRoot;
	while (p != NULL || !IsEmpty(S))  
	{
		while (p)						//��λ����������������ͬʱѹջ·�����
		{	
			Push(p, S);
			p = p->lchild;
		}
		printf("* ");                   //������֮����ջ
		p = Pop(S);
		printf("%c ", p->data);          //��ӡ����������ĸ�
		p = p->rchild;				//�ٰ���������������Ϊ��������
	}
	printf("* ");
	DestroyStack(S);
}
//�ǵݹ�������������
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
				p = p->lchild;				//��λ��������
			}
			printf("* ");					//��ڵ��
			p = Pop(S);						//��ջ���������
			p = p->rchild;					//�������������������
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

//��������һ�ö��������ͷ����пռ�
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

//�Զ���������ָ�������ĺ���
void Operation(BiTree p)
{
	printf("%c ", p->data);
}


//��ʼ��ջ
Stack InitStack()
{
	Stack pS = NULL;
	if (!(pS = (Stack)malloc(sizeof(S_top))))
		exit(-1);
	pS->next = NULL;
	return pS;
}

//ѹջ
void Push(BiTree p, Stack pS)
{
	Stack S = NULL;
	if (!(S = (Stack)malloc(sizeof(S_top))))
		exit(-1);
	S->data = p;
	S->next = pS->next;
	pS->next = S;
}
//��ջ
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
//����ջ
bool IsEmpty(Stack pS)
{
	return pS->next == NULL;
}

//��ȡջ��Ԫ��
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
//����ջ
void DestroyStack(Stack pS)
{
	while (pS->next != NULL)
		Pop(pS);
	free(pS);
	return;
}