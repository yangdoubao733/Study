#include <stdio.h>

#include <stdlib.h>

#include <math.h>

// 函数结果状态代码

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define INFEASIBLE 0

typedef int Status;

typedef int ElemType;

// 定义结构体

typedef struct LNode

{

    ElemType data; // 数据域

    struct LNode *next; // 指针域

} LNode, *LinkList;

// 建立一个带头结点的单链表

Status InitList(LinkList &L)

{

    int x, i;

    L = (LinkList)malloc(sizeof(LNode));

    if (L == NULL)

    {

        printf("memory malloc failure\n");

        return ERROR;
    }

    L->next = NULL;

    // 根据键盘值构造链表

    LinkList r;

    r = L;

    for (i = 0;; i++)

    {

        scanf("%d", &x);

        if (x == -1)

            break;

        LinkList p = (LinkList)malloc(sizeof(LNode));

        if (!p)

        {

            printf("initial failure\n");

            return ERROR;
        }

        p->data = x;

        p->next = NULL;

        r->next = p;

        r = p;
    }

    return OK;
}



//逆序输出
Status inverseprint(LinkList p)

{
    if (p->next == NULL){
        printf("%d ", p->data);
        return OK;
    }
    inverseprint(p->next);
    printf("%d ", p->data);
    return OK;
}

//递归找最大
int findmax(LinkList L)

{
    if (L->next == NULL)
        return L->data;
    if (L->data > findmax(L->next))
        return L->data;
    else
        return findmax(L->next);
}

int main()

{

    // 初始化链表

    LinkList L;

    if (InitList(L) == ERROR)

    {

        return 0;
    }


    inverseprint(L->next); // 对应第一行打印输出

    printf("\n");

    int maxvalue = findmax(L->next);

    printf("%d\n", maxvalue);

    return 0;
}