#include<stdio.h>

struct time
{
    int hour;
    int minute;
    int second;
};

struct time elapsed_time(struct time time1, struct time time2){
    struct time time3;
    time3.hour = time2.hour - time1.hour;
    time3.minute = time2.minute - time1.minute;
    time3.second = time2.second - time1.second;
    while(time3.second < 0){
        time3.minute -= 1;
        time3.second += 60;
    }
    while (time3.minute < 0)
    {
        time3.hour -= 1;
        time3.minute += 60;
    }
    if(time3.hour < 0){
        time3.hour += 24;
    }
    return time3;
    
}

int main(){
    struct time time1,time2,time3;
    scanf("%d:%d:%d",&time1.hour,&time1.minute,&time1.second);
    scanf("%d:%d:%d",&time2.hour,&time2.minute,&time2.second);
    time3 = elapsed_time(time1,time2);
    printf("%.2d:%.2d:%.2d",time3.hour,time3.minute,time3.second);
    return 0;

}