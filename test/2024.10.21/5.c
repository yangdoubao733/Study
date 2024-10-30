#include<stdio.h>

int main(){
    int n,temp,sum=0;
    printf("Please input the number of people:\n");
    scanf("%d",&n);
    if(n<=0 || n>10){
        printf("Wrong Input");
        return 0;
    }
    printf("Please input scores:\n");
    int score[n];
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp<0 || temp>100){
            printf("Wrong Input");
            return 0;
        }
        score[i] = temp;
    }
    for(int i=0;i<n;i++){
        sum += score[i];
    }
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(score[j] > score[j+1]){
                temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    }
    printf("The sum of scores is: %d\nThe average of scores is: %d\nThe sorted scores are: ",sum,sum/n);
    for(int i=0;i<n;i++)printf("%d ",score[i]);
    return 0;
}