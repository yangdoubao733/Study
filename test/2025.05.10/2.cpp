#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status; // Status 是函数返回值类型，其值是函数结果状态代码
typedef int ElemType;
typedef struct LNode

{
    ElemType data; // 结点的数据域
    struct LNode *next; // 结点的指针域
} LNode, *LinkList;

Status InitList_L(LinkList &L) // 单链表的初始化，构造一个空的单链表 L

{
    L = (LNode *)malloc(sizeof(LNode));
    if (!L) return ERROR;
    L->next = NULL;
    return OK;
}

Status Input(LinkList &L, int n) // 单链表数据元素的输入

{
    int i, data;
    LinkList p, r;
    r = L;
    for (i = 0; i < n; i++)
    {
        cin >> data;
        p = new LNode;
        if (!p) exit(OVERFLOW);
        p->data = data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return OK;
}

void Output(LinkList L) // 单链表数据元素的输出

{
    // int i = 0;
    LNode *p;
    p = L->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// 交换单链表中每两个相邻元素

Status SwapPairs(LinkList &L)

{
    LinkList p,temp1,temp2;
    p = L;
    while(p->next&&p->next->next){//还有俩能换
        temp1 = p->next;
        temp2 = p->next->next->next;
        p->next = p->next->next;
        p->next->next = temp1;
        p->next->next->next = temp2;
        p = p->next->next;
    }
    return OK;
}

int main()

{

    LinkList L;

    InitList_L(L);

    int n;

    cin >> n;

    while (n < 0)

    {

        cout << "Please input a non-negative integer.\n";

        cin >> n;
    }

    Input(L, n);

    SwapPairs(L);

    Output(L);

    return 0;
}