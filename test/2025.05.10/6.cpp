#include <stdio.h>

#include <stdlib.h>

#define N 52

typedef struct
{

    char data[3]; // 两字符牌面 + '\0'

} ElemType;

typedef int Status;

#define TRUE 1

#define FALSE 0

#define OK 1

#define ERROR 0

#define OVERFLOW 1

/* 线性表的动态分配顺序存储结构 */

#define LIST_INIT_SIZE 52 /* 线性表存储空间的初始分配量 */

typedef struct

{

    ElemType *elem; /* 存储空间基址 */

    int length; /* 当前长度 */

    int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */

} SqList;

// 初始化线性表
Status InitList(SqList &L)

{
    L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    if(!L.elem)return OVERFLOW;
    L.listsize = LIST_INIT_SIZE;
    L.length = 0;
    return OK;
}

int Match( ElemType a, ElemType b)
{

    return (a.data[0] == b.data[0] || a.data[1] == b.data[1]); // 点数或花色相同
}

void MoveCard(SqList &L)
{
    for(int i=1;i<L.length;i++){
        if(i>2){
            if(Match(L.elem[i],L.elem[i-3])){
                L.elem[i-3] = L.elem[i];
                for(int j=i;j<L.length;j++){
                    L.elem[j] = L.elem[j+1];
                }
                L.length--;
                i=1;
            }
        }
        if(i>0){
            if(Match(L.elem[i],L.elem[i-1])){
                L.elem[i-1] = L.elem[i];
                for(int j=i;j<L.length;j++){
                    L.elem[j] = L.elem[j+1];
                }
                L.length--;
                i=1;
            }
        }
    }
}

int main()
{

    SqList L;

    // 初始化牌堆

    ElemType e;

    InitList(L);

    scanf("%s", e.data);

    while (e.data[0] != '#')
    {

        L.elem[L.length] = e;

        L.length++;

        scanf("%s", e.data);
    }

    MoveCard(L);

    // 输出结果

    printf("%d piles remaining: ", L.length);

    for (int i = 0; i < L.length; ++i)
    {

        printf("%s ", L.elem[i].data);
    }

    printf("\n");

    return 0;
}