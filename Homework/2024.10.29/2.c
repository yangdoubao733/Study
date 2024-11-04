#include<stdio.h>

int arraySum(int n,int m,int a[n][m]){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum += a[i][j];
        }
    }
    return sum;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d",arraySum(n,m,a));
}