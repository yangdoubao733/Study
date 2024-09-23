#include<stdio.h>

int main(){
    float a=2;
    float b=1;
    float a1,b1;
    float r=0;
    int n;
    r += a/b;
    a1=a;
    b1=b;
    scanf("%d",&n);
    for (int i=2;i<=n;i++){
        a=a1+b1;
        b=a1;
        r += a/b;
        a1=a;
        b1=b;
        
    }
    printf("%.2f",r);
}