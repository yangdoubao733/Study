#include<stdio.h>

int main(){
    float temp;
    float score[3][4];
    printf("Please input 12 scores:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scanf("%f",&score[i][j]);
        }
    }
    float max = score[0][0]+score[0][1]+score[0][2]+score[0][3];
    for(int i=1;i<3;i++){
        temp = score[i][0]+score[i][1]+score[i][2]+score[i][3];
        if(temp > max)max = temp;
    }
    printf("The students' highest total score is:%.0f\nThe average grade for each course is ",max);
    for(int j=0;j<4;j++){
        printf("%.1f",(score[0][j]+score[1][j]+score[2][j])/3);
        if(j != 3)printf(",");
    }
    return 0;
}