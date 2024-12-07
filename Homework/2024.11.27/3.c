#include<stdio.h>

int main(){
    FILE *fp1,*fp2;
    if((fp1 = fopen("a.txt","a")) != NULL && (fp2 = fopen("b.txt","r")) != NULL){
        char a[200];
        fgets(a,200,fp2);
        fputs(a,fp1);
    }
    return 0;
}