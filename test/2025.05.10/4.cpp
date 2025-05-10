#include <iostream>

using namespace std;

#define OK 1

#define ERROR 0

#define OVERFLOW -2

#define MAXSIZE 100

typedef int Status;

typedef char SElemType;

typedef struct
{

    SElemType *base;

    SElemType *top;

    int Stacksize;

} SqStack;

// 顺序栈的初始化，构造一个空栈S

Status InitStack(SqStack &S)

{

    S.base = new SElemType[MAXSIZE];

    if (!S.base)

        exit(OVERFLOW);

    S.top = S.base;

    S.Stacksize = MAXSIZE;

    return OK;
}

// 判断顺序栈是否为空，若为空栈，返回1；若为非空栈，返回0

int StackEmpty(SqStack S)

{
    return S.top == S.base;
}

// 顺序栈的入栈，插入元素e为新的栈顶元素

Status Push(SqStack &S, SElemType &e)

{

    if (S.top - S.base == S.Stacksize)

        return ERROR;

    *(S.top++) = e;

    return OK;
}

// 顺序栈的出栈，若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR

Status Pop(SqStack &S, SElemType &e)

{
    if(!StackEmpty(S)){
        S.top--;
        e = *S.top;
        return OK;
    }
    else return ERROR;
}

// 依次输出链栈中的数据元素，要求栈底元素最先输出

void Output(SqStack S)

{
    int length=0;
    SElemType a[MAXSIZE];
    while(!StackEmpty(S)){
        Pop(S,a[length]);
        length++;
    }
    for(int i=length-1;i>=0;i--){
        printf("%c",a[i]);
    }
}

int main()

{
    int i=0;
    SElemType temp;
    SElemType C[MAXSIZE+1];
    SqStack S;
    InitStack(S);
    cin>>C;
    while(C[i] != '\0'){
        if(C[i] == '#'){
            Pop(S,temp);
            i++;
        }
        else{
            Push(S,C[i]);
            i++;
        }
    }
    Output(S);
}