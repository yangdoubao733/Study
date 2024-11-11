#include<stdio.h>

struct worker
{
    char name[20];
    int wage1;
    int wage2;
    int totalWage;
};

int main(){
    struct worker a[5];
    for(int i=0;i<5;i++){
        scanf("%s %d %d",a[i].name,&a[i].wage1,&a[i].wage2);
        a[i].totalWage = a[i].wage1+a[i].wage2;
    }
    for(int i=0;i<5;i++){
        for(int j=1;j<5-i;j++){
            if(a[j-1].totalWage > a[j].totalWage){
                struct worker temp;
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("The largest total wages are:\n%s  %d  %d  %d\n",a[4].name,a[4].wage1,a[4].wage2,a[4].totalWage);
    printf("The smallest total wages are:\n%s  %d  %d  %d\n",a[0].name,a[0].wage1,a[0].wage2,a[0].totalWage);
    return 0;
}