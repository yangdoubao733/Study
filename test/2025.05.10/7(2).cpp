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

int CreateQueue(LinkQueue &Q, int n)

{

    int i;

    int data;

    for (i = 1; i <= n; i++)

    {

        scanf("%d", &data);

        EnQueue(Q, data);
    }

    return OK;
}

int DeQueue(LinkQueue &Q, int *e)

{
    if(Q.front == NULL)return ERROR;
    Q.front = Q.front->next;
    *e = Q.front->data;
    return OK;
}
int main()

{

    LinkQueue Q;

    int n;

    int i = 1;

    int e;

    scanf("%d", &n);

    InitQueue(Q);

    CreateQueue(Q, n);

    while (Q.front != Q.rear)

    {

        DeQueue(Q, &e);

        printf("Packet %d in queue:%d\n", i, e);

        i++;
    }

    return 0;
}