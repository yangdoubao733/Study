#include <stdio.h>

#include <stdbool.h>

struct date
{
    int year;
    int month;
    int day;
};

bool isEarlier(struct date date1, struct date date2) //1比2早返回1，1比2晚返回0
{
    if(date1.year < date2.year){
        return 1;
    }
    else if (date1.year == date2.year && date1.month < date2.month) 
    {
        return 1;
    }
    else if (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day)
    {
        return 1;
    }
    else if(date1.year == date2.year && date1.month == date2.month && date1.day < date2.day){
        return 1;
    }
    else{
        return 0;
    }
}

void sort(struct date testDate[], int n) //排序

{
    struct date temp;
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(!isEarlier(testDate[j-1],testDate[j])){
                
                temp = testDate[j-1];
                testDate[j-1] = testDate[j];
                testDate[j] = temp;
            }
        }
    }

}

int main()

{
    int n;
    scanf("%d",&n);
    int Early[n];
    struct date testDate[n];
    for(int i=0;i<n;i++){
        scanf("%d/%d/%d",&testDate[i].year,&testDate[i].month,&testDate[i].day);
    }
    printf("The sorted dates are as follows:\n");
    sort(testDate,n);
    for(int i=0;i<n;i++){
        printf("%d/%d/%d\n",testDate[i].year,testDate[i].month,testDate[i].day);
    }
    printf("Please enter current date:\n");
    struct date currentDay;
    scanf("%d/%d/%d",&currentDay.year,&currentDay.month,&currentDay.day);
    for(int i=0;i<n;i++){
        Early[i] = isEarlier(testDate[i],currentDay); 
    }
    int temp = Early[0];
    int target = 0;
    for(int i=1;i<n;i++){
        if(Early[i] != temp){
            target = 1;
        }   
    }
    if(temp == 0 && target == 0){
            printf("All dates are after the current date. No need to split the date array");
    }
    else if(target == 0){
        printf("All dates are before the current date. No need to split the date array");
    }
    if(target == 1){
        printf("The date array will be split into two arraies:\n");
        printf("The dates before the currentDate is:\n");
        for(int i=0;i<n;i++){
            if(Early[i] == 1){
                printf("%d/%d/%d\n",testDate[i].year,testDate[i].month,testDate[i].day);
            }
        }
        printf("The dates after the currentDate is:\n");
        for(int i=0;i<n;i++){
            if(Early[i] == 0){
                printf("%d/%d/%d\n",testDate[i].year,testDate[i].month,testDate[i].day);
            }
        }
    }
    
    return 0;
}

