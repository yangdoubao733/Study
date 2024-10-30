#include<stdio.h>

int zhuanhuan(int x1,int x2,char a[1000000]){ //x1=开始 x2=结束 a为字符串
    int n=0;
    for(int i=x1;i<x2+1;i++){
        n += a[i] - 48;
        n*=10;
    }
    n /= 10;
    return n;
}

int main(){
    char a[1000000]="123";
    printf("%d",zhuanhuan(0,2,a));
}