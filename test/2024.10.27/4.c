#include<stdio.h>

int main(){
    int b=0;
    double average,total=0;
    double a[10];
    for (int i=0;i<10;i++){
        scanf("%lf",&a[i]);
        total += a[i];
    }
    average = total/10;
    for(int i=0;i<10;i++){
        if (a[i] >= average)b += 1;
    }
    printf("The average is %.3lfm, and the number of values greater than or equal to the average is %d\n",average,b);
    double max = a[0];
    for(int i=1;i<10;i++){
        if(a[i] > max)max = a[i];
    }
    printf("The maximum value is %.2lfm, with indices:",max);
    for(int i=0;i<10;i++){
        if(a[i] == max)printf("%d ",i);
    }
    return 0;
}
