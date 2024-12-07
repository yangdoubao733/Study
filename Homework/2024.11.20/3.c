#include<stdio.h>
#include<string.h>

int main(){
    char *day[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    char a[20];
    gets(a);
    int target = 0;
    for(int i=0;i<7;i++){
        if(strcmp(day[i],a) == 0){
            printf("%d",i+1);
            target = 1;
            break;
        }
    }
    if(target == 0)printf("-1");
    return 0;
}