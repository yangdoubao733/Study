#include<stdio.h>

struct student
{
    int code;
    char name[20];
    char gender[20];
    char position[100];
    float grade1;
    float grade2;
    float grade3;
};
int main(){
    struct student a;
    scanf("%d ",&a.code);
    scanf("%s %s %s",a.name,a.gender,a.position);
    scanf("%f %f %f",&a.grade1,&a.grade2,&a.grade3);
    printf("%d %s %s %s %.1f %.1f %.1f %.1f",a.code,a.name,a.gender,a.position,a.grade1,a.grade2,a.grade3,(a.grade1+a.grade2+a.grade3)/3);
    return 0;
}
