#include<stdio.h>

void sortn(int *array, int n )

{
    int a=0;
    for(int i=0;i<n;i++){
        for(int *j=array+1;j<array+n-i;j++){
            if(*j<*(j-1)){
                int *temp=&a;
                *temp = *j;
                *j = *(j-1);
                *(j-1) = *temp;
            }
        }
    }
}

int main()

{
    int n=0;
    scanf("%d",&n);
    int a[n];
    int *array=a;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sortn(array,n);
    for(int *p=a;p<a+n;p++){
        printf("%d ",*p);
    }
}