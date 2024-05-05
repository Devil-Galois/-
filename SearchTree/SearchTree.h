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

//����
//��ղ�����
void MakeEmpty(pNode *pRoot);
//����ĳ��Ԫ��
pNode Find(DataType element, pNode pRoot);
//�������ֵ
pNode FindMax(pNode pRoot);
//������Сֵ
pNode FindMin(pNode pRoot);
//������ֵ
bool Insert(DataType element, pNode* pRoot);
//ɾ��������
bool DeleteElement(DataType element, pNode* pRoot);
//��ȡֵ
DataType GetValue(pNode p);

//�ϴ�д�õ��������
void InOrderTraverse_Recursion(pNode* pRoot);

