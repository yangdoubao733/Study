#include "stdio.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;
//==========================
//打印单链表
//==========================
void ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}
//=======================================
//初始化单链表
//=======================================
Status InitList(LinkList &L)
{
    L = new Node;
    if(!L)
        return ERROR;
    L->next = NULL;
    return OK;
}
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}
Status GetElem(LinkList L, int i, ElemType &e)
{
    LinkList p;
    int j;
    p = L->next;
    j = 1;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i)
        return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
    int j;
    LinkList p,s;
    p = L;
    j = 1;
    while (p && j < i)
    {
       p = p->next;
       j=j+1;
    }
    if (!p || j > i)
       return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    if(!(s))
        return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
//=========================================================
//求单链表所有元素的累加和，并将该累加和作为一个新的结点插在单链表的尾部
//=========================================================
Status AddSumForChecking(LinkList &L)
{
    ElemType sum=0;
    LinkList p = L->next;
    LinkList s;
    if(!p){
        s=new Node;
        if(!(s)){
            return ERROR;
        }
        s->data = 0;
        s->next = NULL;
        L->next = s;
        return OK;
    }
    while(p->next){
        sum += p->data;
        p = p->next;
    }
    sum += p->data;
    s = new Node;
    if(!(s)){
        return ERROR;
    }
    s->data = sum;
    p->next = s;
    return OK;
}
int main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j,k,l;
    i=InitList(L);
    if(i==ERROR)
    {
        return 0;
    }
    printf("Please input the length of frame:\n");
    scanf("%d", &k);
    if (k > 0)
        printf("Please input the element of frame one by one:\n");
    for(j=1;j<=k;j++)
    {
        scanf("%d", &l);
        i=ListInsert(L,1,l);
    }
    printf("The frame is: ");
    ListTraverse(L);
    printf("The length of the frame is: %d \n",ListLength(L));
    if(OK==AddSumForChecking(L))
    {
       GetElem(L, ListLength(L), e);
       printf("The checksum added is: %d\n", e);
        printf("The length of the frame added checksum is: %d \n",ListLength(L));
        printf("The frame added checksum is: ");
        ListTraverse(L);
    }
    return 0;
}
