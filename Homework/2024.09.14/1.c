#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(a%b == 0){
        printf("a can be divided exactly by b");
    }
    else{
        printf("a can not be divided exactly by b");
    }
    return 0;
}