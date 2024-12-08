#include<stdio.h>

int main(){
    int n,temp;
    scanf("%d",&n);
    int a[n+2];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nPlease insert a new number:\n");
    int target,p;
    scanf("%d",&target);
    for(int i=0;i<n-1;i++){
        if(target < a[i]){
            p = 0;
            break;
        }
        if(a[i] <= target && a[i+1] >=target){
            p = i+1;
            break;
        }
        if(i == n-2){
            p = n;
            break;
        }
    }
    int pa=n-1;
    while(pa != p-1){
        a[pa+1] = a[pa];
        pa -= 1;
    }
    a[p] = target;
    for(int i=0;i<n+1;i++){
        printf("%d ",a[i]);
    }
    return 0;
}