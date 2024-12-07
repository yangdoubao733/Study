#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp;
    if((fp = fopen("love.txt","r")) != NULL){
        char a[200];
        fgets(a,200,fp);
        int len = strlen(a);
        int count=0;
        for(int i=0;i<len;i++){
            if(a[i] != ' ' && a[i] != '\0'){
                count+=1;
            }
        }
        printf("The total number of charaecters is: %d",count);
        fclose(fp);

    }
    else{
        printf("error");
    }

    return 0;
}