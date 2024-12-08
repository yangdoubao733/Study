#include<stdio.h>

int main(){
    int a,b,temp,n1,n2,n,target=0;
    scanf("%d %d",&a,&b);
    if(a < 1000 || a >= 10000 || b < 1000 || b >= 10000){
        printf("Invalid.");
        return 1;
    }
    if(a > b){
        temp=a;
        a=b;
        b=temp;
    }
    for(int i=a;i<=b;i++){
        n1 = 0;
        n = i;
        n1 += n%100;
        n2 = n;
        n2 /= 100;
        if((n1+n2)*(n1+n2) == n){
            printf("%d\n",n);
            target = 1;
        }
    }
    if(target == 0){
        printf("There is no “Lightning Strike Number” between [%d,%d].",a,b);
    }
    
    return 0;
}