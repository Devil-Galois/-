#define true  1
#define false 0

typedef char DataType;

typedef int bool;

typedef struct BiTNode
{
    DataType data;
    struct BiTNode * lchild,*rchild;
}BiTNode ,*BiTree;


//����

//����һ����
BiTree PreOrderCreateBiTree(DataType* *array);
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
BiTree DestroyBiTree(BiTree* pRoot);

//�Զ���������ָ�������ĺ���
void Operation(BiTree p);




//ջ��ʵ�ֲ���
typedef struct Stack
{
    BiTree data;
    struct S_Node* next;
}S_top,*Stack;

//����
//ѹջ
void Push(BiTree p, Stack pS);
//��ջ
BiTree Pop(Stack pS);
//��ʼ����ջ
Stack InitStack();
//����ջ
bool IsEmpty(Stack pS);
//��ȡջ��Ԫ��
BiTree GetTop(Stack pS);
//����ջ
void DestroyStack(Stack pS);