#include<stdio.h>

int main(){
    int n,max_1,max_2,target;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    max_1 = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > max_1){
            max_1 = a[i];
        }
    }
    max_2 = 0;
    for(int i=0;i<n;i++){
        if(a[i] > max_2 && a[i] != max_1){
            max_2 = a[i];
            target = i;
        }
    }
    printf("%d %d",target,max_2);
}