#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){ //输入
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){ //排序
        for(int j=1;j<n-i;j++){
            if(a[j-1] > a[j]){
                int temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    int move[n]; //记录每个位置的move次数
    for(int i=0;i<n;i++){
        move[i] = 0;
    }
    for(int i=1;i<n;i++){ //计算每个位置需要move几次
        while(a[i] <= a[i-1]){
            a[i] += 1;
            move[i] += 1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){ //得出总move次数
        sum += move[i];
        
    }
    printf("%d",sum);
    return 0;
}