#include<stdio.h>

int main(){
    int m,n,nonum=0;
    scanf("%d",&m);
    scanf("%d",&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        int y_max=0,target=0;
        for(int j=0;j<n;j++){
            if(a[i][j] > a[i][y_max])y_max=j;
        }
        for(int x=0;x<n;x++){
            if(a[x][y_max] < a[i][y_max])target=1;
        }
        if(target == 0)printf("a[%d][%d]=%d",i+1,y_max+1,a[i][y_max]);
        if(target == 1)nonum += 1;
    }
    if(nonum == m)printf("no");
    

    return 0;
}