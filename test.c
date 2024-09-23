#include<stdio.h>

int main(){
    int a=123;
    printf("%d\n",a/100);
    printf("%d\n",a%10);
    printf("%d\n",a-a/100*100-a%10);
    printf("%d",((a/100)*(a/100)+(a%10)*(a%10)+(a-(a/100*100-a%10))*(a-(a/100*100-a%10))));
}