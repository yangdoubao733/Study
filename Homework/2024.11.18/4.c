#include<stdio.h>

int search(int *p, int n, int x)

{
    for(int *i=p;i<p+n;i++){
        if(*i == x)return (i-p);
    }
    return -1;
}

int main()

{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x;
    scanf("%d",&x);
    int *p = a;
    int temp = search(p,n,x);
    if(temp == -1){
        printf("no found");
        return 0;
    }
     printf("%d",temp);
}