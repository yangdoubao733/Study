#include<stdio.h>
#include<math.h>

int process(int temp,int a,int n){
    temp += a * pow(10,n-1);
    if(n == 1){
        return temp;
    }
    return process(temp,a,n-1);
}


int main(){
    int a,n,r;
    scanf("%d %d",&a,&n);
    if(a<2 || a>9 || n<2 || n>9){
        printf("out of range");
        return 0;
    }
    r = process(0,a,n);
    for(int i=n-1;i>=1;i--){
        r -= process(0,a,i);
    }
    printf("%d",r);
    return 0;
}