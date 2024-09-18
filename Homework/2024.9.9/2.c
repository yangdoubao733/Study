#include<stdio.h>
int main(){
    double f;
    scanf("%lf",&f);
    printf("celsius=%.2lf",(f-32)*5/9);
    return 0;
}