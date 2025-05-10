#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define STACK_SIZE 100  //顺序栈容量 
#define  STACKINCRMENT 20
#define OK 1
#define ERROR 0

typedef int Status;
typedef char SElemType;
typedef struct
{
   SElemType *base;//栈底位置 
   SElemType *top;//栈顶位置
   int stacksize;//存储分配容量，以元素为单位。 
}SqStack;

//初始化 
//如果成功，返回OK，如果失败，返回ERROR
Status InitStack(SqStack &S)//初始化
{
   S.base=(SElemType *)malloc(STACK_SIZE*sizeof(SElemType));
   if(!S.base)
      return ERROR;
   S.top=S.base;
   S.stacksize=STACK_SIZE;
   return OK; 
}

//入栈 
// 如果成功，返回OK，如果失败，返回ERROR
Status Push(SqStack &S, SElemType e)//入栈 
{
   if(S.top-S.base == S.stacksize) return ERROR;
   *S.top++=e;
   return OK;
}

int StackEmpty(SqStack S)
{
   return (S.top==S.base);
}

//出栈 
//如果成功，返回OK，如果失败，返回ERROR
Status Pop(SqStack &S,SElemType &e)//出栈 
{
   if(S.top==S.base)return ERROR;
   e=*--S.top;
   return OK;
}

// 获取栈顶元素
//如果成功，返回OK，如果失败，返回ERROR
Status GetTop(SqStack S, SElemType &e)
{
   if(S.top == S.base)return ERROR;
   e=*(S.top-1);
   return OK;
}
 
int main()
{
   char str[100];
   gets(str);
   SqStack S;
   InitStack(S);
   int i=0,j=0;
   char temp1,temp2;
   while(str[i] != '\0'){
      GetTop(S,temp1);

      if(temp1 != str[i]){
         Push(S,str[i]);
         i++;
         j++;
      }
      else{
         temp2 = str[i];
         while(!StackEmpty(S) && temp1 == str[i]){
            Pop(S,temp1);
            GetTop(S,temp1);
            j--;
         }
         i++;
         while(str[i] == temp2)i++;
         
      }
   }
   char str2[100];
   for(int i=j-1;i>=0;i--){
      Pop(S,str2[i]);
   }
   puts(str2);
}

