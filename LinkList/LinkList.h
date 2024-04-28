#include <stdlib.h>
#define true  1
#define false 0
typedef int DataType;  //链表所存数据数据类型
typedef int bool;
typedef struct Node    //链表结点
{
    DataType data;
    struct Node *next;
} Node,*LinkList;


//函数

//初始化链表，建立一个空链表
bool InitList(LinkList *L);
//检查线性表是否为空
bool ListEmpty(LinkList *L);
//清空链表，但保留头节点
void ClearList(LinkList *L);
//获取链表第i个元素的值
bool GetValue(LinkList *L,int i,DataType *element);
//向已有链表中插入新元素
bool InsertList(LinkList *L,int i,DataType element);
//从已有链表中删除元素
bool DeleteList(LinkList *L,int i,DataType *element);
//获取链表中元素个数
int GetLength(LinkList *L);
//在线性表中查找
bool SearchElement(LinkList *L,DataType element,LinkList Point,int * i);
//销毁链表,释放包括头节点在内的所有内存
bool DestroyList(LinkList *L);