#include<stdio.h>
int main(){
    double r,h;
    scanf("r=%lf, h=%lf",&r,&h);
    printf("Perimeter=%.2lf, CircleArea=%.2lf, CylinderVolume=%.2lf",3.14*r*2,3.14*r*r,3.14*r*r*h);
    return 0;
}