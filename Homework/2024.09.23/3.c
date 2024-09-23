#include<stdio.h>
#include<string.h>


int main(){
    int a;
    int flag=0;
    int factor=2;
    char result;
    scanf("%d",&a);
    int num=a;
    printf("%d=",a);
    
    while(factor <= num/2){
        if(a == 1){
            break;
        }
        if(a%factor == 0){
            if(flag == 0){
                printf("%d",factor);
                a /= factor;
                flag = 1;
            }
            else{
                printf("*%d",factor);
                a /= factor;
            }
            
        }
        else{
            factor += 1;
        }
    }
    
    
    return 0;
}