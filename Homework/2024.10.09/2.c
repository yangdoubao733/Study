#include<stdio.h>

int main(){
    int a[10] = {0};
    int i = 0;
    int sum = 0;
    while (sum <= 100) //输入
    {
        scanf("%d",&a[i]);
        sum += a[i];
        i += 1;
    }
    for(int i=0;i<10;i++){ //冒泡排序
        for(int j=1;j<10-i;j++){
            if(a[j-1]>a[j]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    for(int i=0;i<10;i++){ //输出
        if(a[i] != 0){
            printf("%d ",a[i]);
        }
    }
    return 0;
}