#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    DataType a[10]={1,2,3,4,5,6,7,8,9,10};
    LinkList L,p=NULL;
    DataType value;
    int      n = 0;
    //初始化链表
    if(!InitList(&L))
        printf("Error!  Initial fails\n");
    else 
        printf("Initial successfully\n");

    //检查是否空表
    if (ListEmpty(&L))
        printf("List is empty!\n");
    else
        printf("List isn't empty!\n");
    
    //向表中插入元素
    for (int i = 0; i < 10; i++)
        InsertList(&L, L->data + 1, a[i]);
    if (GetLength(&L) == 10)
        printf("Insert successfully!\n");

    //打印出元素进行检查
    for (int i = 1; i <= 10; i++)
    {
        GetValue(&L, i, &value);
        printf("The %d element is: %d\n", i, value);
    }
    //从中搜索元素
    if (SearchElement(&L, 2, p, &n))
        printf("Search successfully,it's foot is %d!\n",n);
    else
        printf("Search fail!\n");
    if(p!=NULL)
    printf("We can get it's value from point:%d\n", p->data);

    //从其中删除元素
    if (DeleteList(&L, 2, &value))
        printf("The Deleted element is %d\n", value);
    else
        printf("Delete error!\n");

    //再次搜索元素
    if(SearchElement(&L,2,p,&n))
        printf("Search successfully,it's foot is %d!\n", n);
    else
        printf("Search fail!\n");
    //把表清空
    ClearList(&L);
    if (L->next == NULL)
        printf("Clear successfully!\n");
    else
        printf("Clear fail!\n");

    //摧毁链表
    DestroyList(&L);
    if (L == NULL)
        printf("Destroy successfully!\n");
    else
        printf("Destroy fail!\n");
        
    return 0;
}