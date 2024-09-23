#include<stdio.h>

int main(){
    int a;
    int sum=0;
    int w=0;
    scanf("%d",&a);
    while(a != 0){
        sum += a%10;
        w+=1;
        a /= 10;
    }
    printf("%d %d",w,sum);
    return 0;
}