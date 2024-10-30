#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int k[20]={1,0};
    int temp[20]={0};
    if(n == 1){printf("1");return 0;}
    for(int len=1;len<=20;len++){
        for(int i=1;i<20;i++){
            temp[0] = 1;
            temp[i] = k[i]+k[i-1];
            if(temp[i] == n){printf("%d",len+1);return 0;}
        }
        for(int i=0;i<20;i++)k[i] = temp[i];
    }
    return 0;
}