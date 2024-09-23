#include<stdio.h>
#include<math.h>

int main(){
    int a,n;
    int r=0;
    scanf("%d %d",&a,&n);
    for(int i=1;i<=n;i++){//从第一个数开始加
        int a1=0;
        for (int i1=0;i1<=i-1;i1++){//算第i个数
            
            a1 += pow(10,i1)*a;
        }
        r += a1;
    }
    printf("%d",r);
    return 0;
}