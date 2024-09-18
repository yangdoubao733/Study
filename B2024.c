#include<stdio.h>
#include<cmath>
int main(){
    double h,r;
    scanf("%lf %lf",&h,&r);
    double v = 3.14*r*r*h;
    double c = 20000/v;
    c = ceil(c);
    printf("%.0lf",c);
    return 0;
}