#include<stdio.h>
#include<stdlib.h>

int main(){
    int date[6];
    int target,min,x,temp;
    for(int i=0;i<6;i++){
        scanf("%d",&date[i]);
    }
    scanf("%d",&target);
    min = abs(date[0]*date[1]-target);
    x=0;
    for(int i=1;i<6-1;i++){
        temp = abs(date[i]*date[i+1]-target);
        if(temp < min){
            min = temp;
            x = i;
        }
    }
    printf("%d*%d=%d",date[x],date[x+1],date[x]*date[x+1]);
    return 0;
}