#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define null 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100

 
typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;
 
 
 
 //初始化循环队列
void InitQueue(SqQueue &Q){
     
    Q.base=(int *)malloc(MAXSIZE*sizeof(int));
    Q.front=0;
    Q.rear=0;
    
}
 
 
 //求队列长度
int QueueLength(SqQueue &Q)
{  
    //★★★请补全代码

}


 
int  EnQueue(SqQueue &Q,  int e) // 入队列
{
    if((Q.rear+1)%MAXSIZE==Q.front)
        return ERROR;
         
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return OK;
}
 
int DeQueue(SqQueue &Q,int &e) // 出队列
{
 
    if(Q.front==Q.rear)
        return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return OK;
}
 
int GetHead(SqQueue Q,int &e) // 取队头元素值
{
    if(Q.front==Q.rear)
        return ERROR;
    e=Q.base[Q.front];
    return OK;
}
 
 
int Baoshu(SqQueue &Q)
{
      
     //★★★请补全代码
 
}
 
int main()
{
    int n;
    int i;
    int j;
    SqQueue Q;
    InitQueue(Q);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        EnQueue(Q, i);
    j=Baoshu(Q);
    printf("\n");
    printf("%d ",j);
    return 0;
}