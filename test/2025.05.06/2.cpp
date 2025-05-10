#include <stdio.h>
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

#define ERROR -1
#define OK 1

typedef struct Lnode {
    int data;
    struct Lnode *next;
} LNode, *LinkList;

int Initlist(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        printf("Memory failure \n");
        return ERROR;
        return OK;
    }
    L->next = NULL;
    LinkList r;
    r = L;
    int x;
    int i;
    for (i = 0;; i++) {
        scanf("%d", &x);
        if (x == -1)
            break;
        LNode *p = (LinkList)malloc(sizeof(LNode));
        if (!p) {
            printf("Initialization failure ");
            return ERROR;
        }
        p->data = x;
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return OK;
}

void ListPrint(LinkList L) {
    LNode *p;
    for (p = L->next; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
}

int ListLength(LinkList L) {
    int length = 0;
    Lnode *p;
    for (p = L->next; p != NULL; p = p->next) {
        length += 1;
    }
    return length;
}

int MoveMin(LinkList &L) { //将最小的值移到最开头
    if (L->next == NULL) {
        printf("The list is empty.\n");
        return ERROR;
    }
    Lnode *pre = L,*p = L->next;
    Lnode *minpre = L,*minp = L->next;
    int min = p->data;
    while(p!=NULL){
        if(p->data<min){
            minpre = pre;
            minp = p;
            min = p->data;
        }
        pre = p;
        p = p->next;
    }
    if(minpre == L)return OK;
    minpre->next = minp->next;
    minp->next = L->next;
    L->next = minp;
    return OK;
}

int SumToNewlist(LinkList &L) {
    int sum=0;
    Lnode *p,*pre;
    p=L->next;
    while(p!=NULL){
        sum += p->data;
        pre = p;
        p = p->next;
    }
    LNode *t = (LinkList)malloc(sizeof(LNode));
    if (!t) {
        printf("Memory failure \n");
        return ERROR;
    }
    t->data = sum;
    t->next = NULL;
    pre->next = t;
    return OK;
}
int main() {
    int length;
    LinkList L;
    Initlist(L);
    printf("The original linked list is：");
    ListPrint(L);
    printf("\nThe length of list is：");
    length = ListLength(L);
    printf("%d ", length);
    MoveMin(L);
    printf("\nAfter moving the minimum, the linked list is: ");
    ListPrint(L);
    printf("\nAfter inserting the sum, the new list is: ");
    SumToNewlist(L);
    ListPrint(L);
    return 0;
}
