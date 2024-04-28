#define true  1
#define false 0

typedef int DataType;

typedef int bool;

typedef struct BiTNode
{
    DataType data;
    struct BiTNode * lchild,*rchild;
}BiTNode ,*BiTree;

typedef enum order
{
    PreOrder = 10, InOrder = 20, PostOrder = 30
}Order;

//函数

//初始化一个带头二叉树
void InitBiTree(BiTree* pRoot);

//根据已有数据按指定遍历顺序建立一个树
void CreateBiTree(BiTree* pRoot, DataType* array,Order oder);

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
void DestroyBiTree(BiTree* pRoot);

//对二叉树进行指定操作的函数
void Operation();




