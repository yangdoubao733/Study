#include<stdio.h>

int main(){
    FILE *fp1,*fp2;
    if((fp1 = fopen("Desktop1.txt","r")) != NULL && (fp2 = fopen("Desktop2.txt","w")) != NULL){
        char c;
        c=fgetc(fp1);
        while(c != EOF){
            if(c>='a' && c<='z'){
                c -= 32;
            }
            fputc(c,fp2);
            c=fgetc(fp1);
        }
    }
    return 0;
}