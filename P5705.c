#include<stdio.h>
int main(){
    float a;
    int b;
    float c;
    scanf("%f",&a);
    b = a*10;
    c = b%10 + ((b/10)%10)*0.1 + ((b/100)%10)*0.01 + (b/1000)*0.001;
    printf("%.3f",c);
}