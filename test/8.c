#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    float a[n][2];
    for(int i=0;i<n;i++){
        scanf("%f %f",&a[i][0],&a[i][1]);
    }
    printf("The vertices of the %d-gon are:",n);
    for(int i=0;i<n;i++){
        printf(" (%.2f, %.2f)",a[i][0],a[i][1]);
    }
    return 0;
}