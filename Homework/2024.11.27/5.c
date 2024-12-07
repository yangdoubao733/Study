#include<stdio.h>

int main(){
    FILE *fp1,*fp2,*fp3;
    if((fp1 = fopen("a.txt","r")) != NULL && (fp2 = fopen("b.txt","r")) != NULL && (fp3 = fopen("c.txt","a")) != NULL){
        char a,b;
        int target = 1;
        int firstLine1=1,firstLine2=1;
        while(!feof(fp1) && !feof(fp2)){
            if(target == 1){
                a = fgetc(fp1);
                if(a == '\n'){
                    fputc(a,fp3);
                    target = 2;
                    continue;
                }
                if(a == EOF && firstLine1 == 0){
                    fputc('\n',fp3);
                    target = 2;
                    continue;
                }
                else if(a == EOF && firstLine1 != 0){
                    target = 2;
                    continue;
                }
                else{
                    firstLine1 = 0;
                }
                fputc(a,fp3);
            }
            if(target == 2){
                a = fgetc(fp2);
                if(a == '\n'){
                    fputc(a,fp3);
                    target = 1;
                    continue;
                }
                if(a == EOF && firstLine2 == 0){
                    fputc('\n',fp3);
                    target = 1;
                    continue;
                }
                else if(a == EOF && firstLine2 != 0){
                    target = 1;
                    continue;
                }
                else{
                    firstLine2 = 0;
                }
                fputc(a,fp3);
            }
        }
        while(!feof(fp1) && feof(fp2)){
            a = fgetc(fp1);
            if(a == '\n'){
                fputc(a,fp3);
                continue;
            }
            if(a == EOF){
                fputc('\n',fp3);
                continue;
            }
            fputc(a,fp3);
        }
        while(feof(fp1) && !feof(fp2)){
            a = fgetc(fp1);
            if(a == '\n'){
                fputc(a,fp3);
                continue;
            }
            if(a == EOF){
                fputc('\n',fp3);
                continue;
            }
            fputc(a,fp3);
        }
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);

    }
    return 0;
}