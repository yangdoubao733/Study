#include<stdio.h>
int main(){
    int hr = 7;
    int min = 50;
    int s,v,t;
    scanf("%d%d",&s,&v);
    if (s%v != 0){ //判断是否需要提前一分钟
        min -= 1;
    }
    t = s/v; // 算需要的分钟数

    min -= t%60; //算到达时的分钟
    if (t/60>=8){ //判断到没到前一天
        hr = 23;
        t -= 480;
    }
    hr -= t/60;
    if (min<0){
        hr -= 1;
        min += 60;
    }

    

    printf("%02d:%02d",hr,min);
    return 0;
}