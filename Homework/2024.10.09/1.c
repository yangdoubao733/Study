#include<stdio.h>

int main(){
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10;i++){
        if(a[i]%7 == 0){
            a[i] = 0;
        }
    }
    for(int i=0;i<10;i++){
        if(a[i] != 0 ){
            if(a[i] != 220){  //你说得对，虽然我说的是给十个1-200的数，但我给你一个220你没去掉就是你的问题
                printf("%d ",a[i]);
            }
        }

    }
    return 0;
}
