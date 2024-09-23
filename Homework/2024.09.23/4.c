#include<stdio.h>

int main(){
    int a,b,y;
    int a1,b1;

    scanf("%d %d",&a,&b);
    a1 = a;
    b1 = b;
    y = a%b;
    while(y != 0){ //求最大公约数
        a = b;
        b = y;
        y = a%b;

    }
    printf("%d ",b);
    printf("%d",a1*b1/b);
    return 0;
}