#include<stdio.h>

struct student
{
    char name[10];
    float score[5];
    float average;
};


int main(){
    
    
    FILE *fp;
    fp = fopen("student_scores.txt","r");
    int n;
    fscanf(fp,"%d",&n);
    struct student student[n];
    for(int i=0;i<n;i++){
        fscanf(fp,"%s %f %f %f %f %f",student[i].name,&student[i].score[0],&student[i].score[1],&student[i].score[2],&student[i].score[3],&student[i].score[4]);
        float totalScore=0;
        for(int j=0;j<5;j++){
            totalScore += student[i].score[j];
        }
        student[i].average = totalScore / 5;
    }
    fclose(fp);
    fp = fopen("student_averages.txt","w");
    for(int i=0;i<n;i++){
        fprintf(fp,"%s %.0f %.0f %.0f %.0f %.0f Average:%.2f\n",student[i].name,student[i].score[0],student[i].score[1],student[i].score[2],student[i].score[3],student[i].score[4],student[i].average);
    }
    fclose(fp);
    return 0;
}