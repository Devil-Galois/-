#include "LinkList.h"
#include <stdlib.h>
//初始化链表，建立一个空链表
bool InitList(LinkList * pL)
{
    
    *pL= (LinkList)malloc(sizeof(Node));
    if(!*pL)
        return false;
    else 
    {
        (*pL)->data=0;         //data存储表长
        (*pL)->next=NULL;
    }
        return true;
}

//检查线性表是否为空,是则返回true
bool ListEmpty(LinkList *pL)
{
    if(!((*pL)->data))
        return true;
    else
        return false; 
}

//清空链表，并释放除头节点之外的所有内存
void ClearList(LinkList *pL)
{
    LinkList p=(*pL)->next;
    while(p)
    {
        (*pL)->next=p->next;
        free(p);
        p=(*pL)->next;
    }
    (*pL)->data=0;
    
}
//获取链表第i个元素的值(1,2,3,4,5,...)
bool GetValue(LinkList *pL,int i,DataType *element)
{
    LinkList p=(*pL)->next;
    if(i>(*pL)->data)
        return false;
    else
        for(int j=1;j<i;j++)
            p=p->next;
    *element=p->data;
    return true;
}
//向已有链表中插入新元素，插在第i个(1,2,3,...)
bool InsertList(LinkList *pL,int i,DataType element)
{
    LinkList p=NULL,q=*pL;
    if(i>((*pL)->data+1))
        return false;
    else
    {
        if(!(p=(LinkList)malloc(sizeof(Node))))
            return false;
        else
        {
            for(int j=1;j<i;j++)
                q=q->next;
            p->data=element;
            p->next=q->next;
            q->next=p;
            (*pL)->data++;       //表长增加
            return true;
        }
    }
}
//从已有链表中删除第i个元素(1,2,3,4,...)
bool DeleteList(LinkList *pL,int i,DataType* element)
{
    LinkList p=(*pL)->next,q=*pL;
    if(i>(*pL)->data)
        return false;
    else
    {
        for(int j=1;(j<i)&&(p!=NULL);j++)
        {
            q=p;
            p=p->next;
        }
        if (p != NULL)
        {
            *element = p->data;
            q->next = p->next;
            free(p);
            (*pL)->data--;
            return true;
        }
    }
}
//获取链表中元素个数
int GetLength(LinkList *pL)
{
    return (*pL)->data;
}
//在线性表中查找,i携带下标(1,2,3,4,...),Point携带地址
bool SearchElement(LinkList *pL,DataType element,LinkList Point,int *i)
{
    LinkList p=(*pL)->next;
    *i=1;
    while(p!=NULL)
    {
        if(p->data==element)
        {
            Point=p;
            return true;
        }
        else 
        {
            (*i)++;
            p=p->next;
        }
    }
    return false;
}

//销毁链表
bool DestroyList(LinkList *pL)
{
    ClearList(pL);
    free(*pL);
    *pL = NULL;
}