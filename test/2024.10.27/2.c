#include<stdio.h>

int jiecheng(int n){
    int r=1;
    for(int i=1;i<=n;i++){
        r *= i;
    }
    return r;
}
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    if(m<1 || n<0 || m<0 || m<n){
        printf("error!");
        return 0;
    }
    printf("%d",jiecheng(m)/(jiecheng(n)*jiecheng(m-n)));
}