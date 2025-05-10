#include <stdio.h>
#define MAX_SIZE 100

 

// 定义顺序表结构体

typedef struct
{
    int data[MAX_SIZE]={0};
    int length;
} SeqList;

 

 

// 判断元素是否既在 B 表中又在 C 表中

int isCommonElement(SeqList B, SeqList C, int element)

{
    int pb=0,pc=0;
    for(int i=0;i<B.length;i++){
        if(B.data[i] == element)pb=1;
    }
    for(int i=0;i<C.length;i++){
        if(C.data[i] == element)pc=1;
    }
    return pb&&pc;
}

 

// 删除 A 表中既在 B 表又在 C 表中的元素

void deleteCommonElements(SeqList &A, SeqList B, SeqList C)

{
    for(int i=0;i<A.length;i++){
        if(isCommonElement(B,C,A.data[i])){
            for(int j=i;j<A.length;j++){
                A.data[j]=A.data[j+1];
            }
            A.length--;
            i--;
        }
    }
}

 

// 打印顺序表

void printList(SeqList L)

{
    for (int i = 0; i < L.length; i++)
    {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

 

int main()

{
    SeqList La, Lb, Lc;
    printf("Please enter the length of La:\n");
    scanf("%d", &La.length);
    for (int i = 0; i < La.length; i++)
    {
        scanf("%d", &La.data[i]);

    }
    printf("Please enter the length of Lb:\n");
    scanf("%d", &Lb.length);
    for (int i = 0; i < Lb.length; i++)
    {
        scanf("%d", &Lb.data[i]);
    }
    printf("Please enter the length of Lc:\n");
    scanf("%d", &Lc.length);
    for (int i = 0; i < Lc.length; i++)
    {
        scanf("%d", &Lc.data[i]);
    }
    deleteCommonElements(La, Lb, Lc);
    printf("La after operation: ");
    printList(La);
    return 0;

}