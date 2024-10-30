#include<stdio.h>
#define n 7

int main(){
    float temp,a[7];
    for(int i=0;i<7;i++){
        scanf("%f",&temp);
        if(temp > 10 || temp < 0){
            printf("Wrong Input!");
            return 0;
        }
        a[i] = temp;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(a[j-1] > a[j]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    printf("The scores after sorting are:");
    for (int i = 0; i < n; i++)
    {
        printf(" %.1f",a[i]);
    }
    printf("\nThe final score is: %.1f",(a[2]+a[3]+a[4])*2.0);
    
    return 0;
}