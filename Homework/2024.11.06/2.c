#include<stdio.h>

struct worker
{
    char* name;
    int basicWage;
    int jobPositionWage;
};

int main(){
    struct worker a,b;
    a.name = (char*)"lihong";
    a.basicWage=945;
    a.jobPositionWage=1400;
    b.name = (char*)"liuqiang";
    b.basicWage=920;
    b.jobPositionWage=1450;
    printf("%s %d\n",a.name,a.basicWage+a.jobPositionWage);
    printf("%s %d\n",b.name,b.basicWage+b.jobPositionWage);
    return 0;
}