#include<stdio.h>
#include<string.h>

int main(){
    char a[100];
    gets(a);
    int len=strlen(a);
    char b[len+1];
    for(int i=0;i<len;i++){
        b[len-i-1] = a[i];
    }
    b[len] = '\0';
    printf("%s",b);
    return 0;
}