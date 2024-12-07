#include<stdio.h>
#include<stdlib.h>

int main(){
    int a;
    FILE *fp;
    fp = fopen("idata.txt","w");
    for(int i=0;i<10;i++){
        scanf("%d",&a);
        fprintf(fp,"%d ",a);
    }
    fclose(fp);
    return 0;
}