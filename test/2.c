#include<stdio.h>



int main(){
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int jiecheng=1;
        for(int j=1;j<=i;j++){
            jiecheng *= j;
        }
        sum += jiecheng;
    }
    printf("The sum of factorials is:%d",sum);
    return 0;
}