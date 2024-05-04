#define true  1
#define false 0

typedef char DataType;

typedef int bool;

typedef struct BiTNode
{
    DataType data;
    struct BiTNode * lchild,*rchild;
}BiTNode ,*BiTree;


//函数

//建立一个树
BiTree PreOrderCreateBiTree(DataType* *array);
//递归前序遍历二叉树
void PreOrderTraverse_Recursion(BiTree* pRoot);
//递归中序遍历二叉树
void InOrderTraverse_Recursion(BiTree* pRoot);
//递归后序遍历二叉树
void PostOrderTraverse_Recursion(BiTree* pRoot);

//非递归前序遍历二叉树
void PreOrderTraverse(BiTree* pRoot);
//非递归中序遍历二叉树
void InOrderTraverse(BiTree* pRoot);
//非递归后序遍历二叉树
void PostOrderTraverse(BiTree* pRoot);

//后序销毁一棵二叉树并释放所有空间
BiTree DestroyBiTree(BiTree* pRoot);

//对二叉树进行指定操作的函数
void Operation(BiTree p);




//栈的实现部分
typedef struct Stack
{
    BiTree data;
    struct S_Node* next;
}S_top,*Stack;

//函数
//压栈
void Push(BiTree p, Stack pS);
//出栈
BiTree Pop(Stack pS);
//初始化空栈
Stack InitStack();
//检查空栈
bool IsEmpty(Stack pS);
//获取栈顶元素
BiTree GetTop(Stack pS);
//销毁栈
void DestroyStack(Stack pS);