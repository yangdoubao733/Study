#include<stdio.h>

int *search(int n,int a[],int *max){
    max = a;
    for(int *p = a;p<(a+n);p++){
        if(*p > *max)max = p;
    }
    return max;
}

int main(){
    int n,*max;
    scanf("%d",&n);
    int a[n];
    for(int *p = a;p<(a+n);p++){
        scanf("%d",p);
    }
    max=search(n,a,max);
    printf("The largest value is %d",*max);
    return 0;
}