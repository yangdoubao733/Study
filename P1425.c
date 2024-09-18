#include<stdio.h>

int main(){
    int a,b,c,d;
    int h,m;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if (a<=c){
        if(b<=d){
            h = c-a;
            m = d-b;
        }
        else{
            c -= 1;
            d += 60;
            h = c-a;
            m = d-b;
        }
       
    }
    else{
    
        if(b<d){
            c += 24;
            h = c-a;
            m = d-b;

        }
        else{
            c += 24;
            c -= 1;
            d += 60;
            h = c-a;
            m = d-b;
        }

    }
    printf("%d %d",h,m);
    return 0;
}