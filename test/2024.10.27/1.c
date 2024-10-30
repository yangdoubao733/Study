#include<stdio.h>
#include<math.h>

int main(){
    float a;
    scanf("%f",&a);
    if(a < 0) printf("f(%.2f)=%.2f",a,-a);
    else if(a < 2) printf("f(%.2f)=%.2f",a,sqrt(a+1));
    else if(a < 4) printf("f(%.2f)=%.2f",a,(a+2)*(a+2));
    else if(a < 10) printf("f(%.2f)=%.2f",a,a*2+5);
    else printf("Out of range");
    return 0;
}