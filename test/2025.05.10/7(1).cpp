#include <stdio.h>

#include <stdlib.h>

#define ERROR 0

#define OK 1

typedef struct QNode /*定义队列单链表存储*/

{

    int data;

    struct QNode *next;

} QNode, *QueuePtr;

typedef struct LinkQueue

{

    QueuePtr front, rear;

} LinkQueue;

int InitQueue(LinkQueue &Q)

{

    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));

    if (!Q.front)

        return ERROR;

    Q.front->next = NULL;

    return OK;
}

int EnQueue(LinkQueue &Q, int e)

{

    QNode *p = (QNode *)malloc(sizeof(QNode));

    if (!p)

    {

        return ERROR;
    }

    p->data = e;

    p->next = NULL;

    Q.rear->next = p;

    Q.rear = p;

    return OK;
}

int Count_Packets(LinkQueue Q)

{
    if(!Q.front)return ERROR;
    int length=0;
    while(Q.front != Q.rear){
        Q.front = Q.front->next;
        length ++;
    }
    return length;
}

int main()

{

    LinkQueue Q;

    int a[100];

    int i = 0;

    InitQueue(Q);

    scanf("%d", &a[i]);

    while (a[i] != -1)

    {

        EnQueue(Q, a[i]);

        i++;

        scanf("%d", &a[i]);
    }

    printf("%d\n", Count_Packets(Q));

    return 0;
}