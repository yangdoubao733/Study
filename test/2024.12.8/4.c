#include<stdio.h>

int main(){
    int m,n,r=0;
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 1){
                int target = 1;
                for(int i0 = 0;i0<m;i0++){
                    if(a[i0][j] == 1 && i0 != i)target = 0;
                }
                for(int j0=0;j0<n;j0++){
                    if(a[i][j0] == 1 && j0 != j)target = 0;
                }
                if(target == 1)r+=1;
            }
        }
    }
    printf("%d",r);
    return 0;
}