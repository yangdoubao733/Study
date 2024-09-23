#include<stdio.h>

int main(){
    int a1,b1,d;
    d=139;
    for(int a=0;a<=8;a++){
        for(int b=0;b<=7;b++){
            if(139-a*19-b*23 < d && 139-a*19-b*23>0){
                a1=a;
                b1=b;
                d=139-a*19-b*23;
            }
        }
    }
    printf("19m:%d\n23m:%d\n%dm",a1,b1,d);
    return 0;
}