#include<stdio.h>

int main(){
    int a[10]={0};
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int left = 0;
    int right = 9;
    int max = a[0];
    for(int i=1;i<10;i++){
        if(a[i] >= max){
            max = a[i];
        }
        else{
            right = i;
        }
    }
    int min = a[9];
    for(int i=8;i>=0;i--){
        if(a[i] <= min){
            min = a[i];
        }
        else{
            left = i;
        }
    }
    printf("%d %d",left,right);
    return 0;
}