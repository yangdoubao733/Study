    #include "stdio.h"
    #include "stdlib.h"
    #include<string.h>
    #define OK 1
    #define ERROR 0
    #define TRUE 1
    #define FALSE 0
    #define MAXSIZE  20   //堆栈的最大容量
    typedef int Status;
    typedef char ElemType;
    //顺序栈的结构定义
    typedef struct
    {
        ElemType data[MAXSIZE]; //存放堆栈元素的数组
        int top;                 //top指向栈顶元素，top=-1，表示空栈
    } SqStack;
    //初始化一个空栈
    void InitStack(SqStack &S)
    {
        S.top = -1;
    }
    Status Push(SqStack &S, ElemType e)
    {
        if(S.top>=MAXSIZE)return ERROR;
        S.top+=1;
        S.data[S.top] = e;
        return OK;
    }
    Status Pop(SqStack &S, ElemType &e)
    {
        if(S.top == -1)return ERROR;
        e = S.data[S.top];
        S.top--;
        return OK;
    }
    //如果是空栈，返回1，否则返回0
    Status StackEmpty(SqStack S)
    {
        return S.top == -1;
    }
    char GetTop(SqStack S, ElemType &e)
    {
        if(S.top == -1)return ERROR;
        e = S.data[S.top];
        return OK;
    }
    int main()
    {
        char a[20], b[20];
        char temp;
        SqStack Stack;
        InitStack(Stack);
        printf("Please enter a string with a length no longer than 20:\n");
        gets(a);
        for(int i=0;i<strlen(a);i++){
            
            if(GetTop(Stack,temp) && a[i] == temp){
                while(a[i] == temp){
                    i++;
                }
                Pop(Stack,temp);
                i--;
            }
            else{
                Push(Stack,a[i]);
            }
        }
        printf("The resulting string is: ");
        int j=Stack.top;
        b[j+1]='\0';
        while(!StackEmpty(Stack)){
            Pop(Stack,temp);
            b[j]=temp;
            j--;
        }
        puts(b);
        return 0;
    }
