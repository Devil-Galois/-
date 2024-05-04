#include "BiTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include <assert.h>
#include <time.h>
int main()
{
	DataType* pre = "AB*D**C**";
	DataType* in = "*B*D*A*C*";
	DataType* post = "***DB**CA";
	DataType* s;
	s = pre;
	BiTree T = PreOrderCreateBiTree(&s);
	PreOrderTraverse_Recursion(&T);
	printf("\n");
	PreOrderTraverse(&T);
	printf("\n");
	InOrderTraverse_Recursion(&T);
	printf("\n");
	InOrderTraverse(&T);
	printf("\n");
	PostOrderTraverse_Recursion(&T);
	printf("\n");
	PostOrderTraverse(&T);
	printf("\n");
	T=DestroyBiTree(&T);
	assert(T == NULL);
	if (!_CrtDumpMemoryLeaks())
		printf("successfully!");
	return 0;
}