#include<stdio.h>

int main(){
    float a,b,bmi;
    printf("Please in put weight and height:\n");
    scanf("%f %f",&a,&b);
    bmi = a/(b*b);
    if(bmi<18.5)printf("You are too slim. Please Increase nutrition!");
    else if(bmi<23)printf("You have a perfect weight!");
    else if(bmi<25)printf("You are a bit of overwight!");
    else printf("You are overwight. Please try to control your weight!");
    return 0;
}