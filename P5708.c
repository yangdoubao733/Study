#include<stdio.h>
#include<cmath>
int main(){
    double a,b,c,p;
    double s;
    scanf("%lf %lf %lf",&a,&b,&c);
    p=(a+b+c)*0.5;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1lf",s);
}