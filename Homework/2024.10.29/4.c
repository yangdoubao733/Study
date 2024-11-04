#include<stdio.h>
#include<string.h>

int count(char ss[]){
    int len = strlen(ss);
    int zm=0,sz=0,kg=0,qt=0;
    for(int i=0;i<len;i++){
        if(ss[i]<='z' && ss[i]>='a' || ss[i]<='Z' && ss[i]>='A')zm += 1;
        else if(ss[i]<='9' && ss[i]>='0')sz += 1;
        else if(ss[i] == ' ')kg += 1;
        else qt += 1;
    }
    printf("zm=%d sz=%d kg=%d qt=%d",zm,sz,kg,qt);
}

int main(){
    char ss[100];
    gets(ss);
    count(ss);
}