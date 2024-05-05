#define true 1
#define false 0

typedef int bool;
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* rchild;
	struct Node* lchild;
}Node,* pNode;

//函数
//清空查找树
void MakeEmpty(pNode *pRoot);
//查找某个元素
pNode Find(DataType element, pNode pRoot);
//查找最大值
pNode FindMax(pNode pRoot);
//查找最小值
pNode FindMin(pNode pRoot);
//插入新值
bool Insert(DataType element, pNode* pRoot);
//删除存在项
bool DeleteElement(DataType element, pNode* pRoot);
//获取值
DataType GetValue(pNode p);

//上次写好的中序遍历
void InOrderTraverse_Recursion(pNode* pRoot);

