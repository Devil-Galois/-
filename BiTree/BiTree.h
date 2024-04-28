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

//����

//��ʼ��һ����ͷ������
void InitBiTree(BiTree* pRoot);

//�����������ݰ�ָ������˳����һ����
void CreateBiTree(BiTree* pRoot, DataType* array,Order oder);

//�ݹ�ǰ�����������
void PreOrderTraverse_Recursion(BiTree* pRoot);
//�ݹ��������������
void InOrderTraverse_Recursion(BiTree* pRoot);
//�ݹ�������������
void PostOrderTraverse_Recursion(BiTree* pRoot);

//�ǵݹ�ǰ�����������
void PreOrderTraverse(BiTree* pRoot);
//�ǵݹ��������������
void InOrderTraverse(BiTree* pRoot);
//�ǵݹ�������������
void PostOrderTraverse(BiTree* pRoot);

//��������һ�ö��������ͷ����пռ�
void DestroyBiTree(BiTree* pRoot);

//�Զ���������ָ�������ĺ���
void Operation();




