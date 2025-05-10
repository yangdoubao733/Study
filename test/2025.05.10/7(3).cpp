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

    int count;

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

int CreateQueue(LinkQueue &Q, int n, int cont)

{

    int i;

    int data;

    for (i = 1; i <= n; i++)

    {

        scanf("%d", &data);

        EnQueue(Q, data);
    }

    Q.count = cont;

    return OK;
}

// 队列是否已空
int QueueEmpety(LinkQueue Q)
{
    return Q.front == Q.rear;
}

// 出队列
int DeQueue(LinkQueue &Q, int *e)

{
    if (Q.front == NULL)
        return ERROR;
    Q.front = Q.front->next;
    *e = Q.front->data;
    return OK;
}

// 学生补充的函数，实现3个队列的轮询输出，输入为队列数组q[]，队列数n以及计数初值数组w[]
void simulate_wrr(LinkQueue q[], int n, int w[])

{
    int data;

    while (q[0].count != 0 || q[1].count != 0 || q[2].count != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (q[i].count != 0 && !QueueEmpety(q[i]))
            {
                DeQueue(q[i], &data);
                printf("%d ", data);
                q[i].count--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (QueueEmpety(q[i]))
            {
                q[i].count = 0;
            }
        }
        if (q[0].count == 0 && q[1].count == 0 && q[2].count == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (!QueueEmpety(q[i]))
                {
                    q[i].count = w[i];
                }
            }
        }
    }
}

int main()

{

    LinkQueue Q[3];

    int n;

    int i;

    int weights[3];

    for (i = 0; i < 3; i++)

    {

        scanf("%d", &weights[i]);
    }

    for (i = 0; i < 3; i++)

    {

        InitQueue(Q[i]);

        scanf("%d", &n);

        CreateQueue(Q[i], n, weights[i]);
    }

    simulate_wrr(Q, 3, weights);

    return 0;
}
