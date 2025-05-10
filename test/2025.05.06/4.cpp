#include<stdio.h>
#include <iostream>
using namespace std;

#define MAXQSIZE 100
typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//链队列的存储结构
typedef struct QNode {
    int data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front; //队头指针
    QueuePtr rear; //队尾指针
    int QLength; //队长 
} LinkQueue;

//链队列的初始化
Status InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    Q.QLength = 0; 
    return OK;
}

//插入元素e为链队列Q的新的队尾元素
Status EnQueue(LinkQueue &Q, int e) {
    QueuePtr p;
    p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    Q.QLength++;
    return OK;
}

//删除链队列Q的队头元素，用e返回其值
Status DeQueue(LinkQueue &Q, int &e) { 
    e = Q.front->data;
    Q.front = Q.front->next;
    Q.QLength--;
    return OK;
}

//返回链队列Q的队头元素，不修改队头指针
int GetHead(LinkQueue Q) {
    if ((Q.front != Q.rear) && (Q.QLength != 0))
        return Q.front->next->data;
}

int GetSecond(LinkQueue Q) {
    if ((Q.front != Q.rear) && (Q.QLength >= 2))
        return Q.front->next->next->data;
    else return -999;
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        EnQueue(Q,temp);
    }
    while(Q.QLength >= 1){
        while(GetHead(Q) == GetSecond(Q)){
            DeQueue(Q,temp);
        }
        printf("%d ",GetHead(Q));
        DeQueue(Q,temp);
    }
    
    
}
