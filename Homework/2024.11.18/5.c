#include<stdio.h>   

void SwapFive(int *p){
    int *temp1,temp2;
    temp1 = &temp2;
    for(int *i=p;i<p+5;i++){
        *temp1 = *i;
        *i = *(i+5);
        *(i+5) = *temp1;
    }
}

int main(){
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    SwapFive(a);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
}