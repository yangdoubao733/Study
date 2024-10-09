#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int target;
    scanf("%d",&target);
    int min;
    for(int i=0;i<n-2;i++){
        int temp = fabs(target-a[i]-a[i+1]-a[i+2]);
        
        if(i == 0){
            min = temp;
        }
        else{
            if(temp < min){
                min = temp;
            }
        }
    }
    printf("%d",min);
}