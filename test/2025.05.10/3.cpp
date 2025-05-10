#include <stdio.h>

#include <stdlib.h>

#include <malloc.h>

#include<math.h>

#define ERROR 0

#define OK 1

#define TRUE 1

#define FALSE 0

typedef int ElemType;

typedef int Status;

// definition of node structure of singly linked list

typedef struct L_node

{

    ElemType data; // data field

    struct L_node *next; // pointer field

} LNode, *LinkList;

//===========================================

// Initialize a  singly linked list L with head node

//===========================================

Status InitLinkList(LinkList &L)

{

    L = (LNode *)malloc(sizeof(LNode)); /*申请头结点空间  */

    if (!L)
        return ERROR;

    L->next = NULL; /*初始化一个空链表  */

    return OK;
}

//===========================================

// Create a singly linked list L with head node, and with n elements 尾插法建立单链表

//===========================================

Status CreateList_L(LinkList &L, int a[], int n)

{

    LinkList q;

    q = L; /*q始终指向终端结点，开始时指向头结点*/

    for (int i = 0; i < n; i++)

    {
        LNode *p;

        p = (LNode *)malloc(sizeof(LNode)); /*申请新的结点空间 */

        if (!p)return ERROR;

        p->data = a[i];

        q->next = p;
        q = p;
    }

    q->next = NULL;

    return OK;
}

//===========================================

//  将单链表中存放的二进制数转换成一个十进制数，并返回得到的结果

//===========================================

int Bin2Dec_L(LinkList L)

{
    int length=0,r=0;
    LinkList p=L->next;
    while(p){
        length++;
        p=p->next;
    }
    p=L->next;
    for(int i=0;i<length;i++){
        r += p->data * pow(2,(length-i-1));
        p=p->next;
    }
    return r;

}

//===========================================

//  将单链表尾部插入元素1

//===========================================

Status Insert(LinkList &L)

{
    LinkList p;
    p=L;
    while(p->next)p = p->next;
    LNode *t;
    t = (LNode *)malloc(sizeof(LNode)); /*申请新的结点空间 */
    if (!t)return ERROR;
    t->data = 1;
    t->next = NULL;
    p->next = t;
    return OK;
}

//======================================

// Print the elements in a list

//=======================================

void LinkListPrint(LinkList L)

{

    LNode *p;

    for (p = L->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }

    printf("\n");
}

int main()

{

    LinkList list;

    int n, i;

    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)

    {

        scanf("%d", &a[i]);
    }

    InitLinkList(list);

    CreateList_L(list, a, n);

    LinkListPrint(list);

    int num = Bin2Dec_L(list);

    printf("%d\n ", num);

    Insert(list);

    LinkListPrint(list);

    return 0;
}