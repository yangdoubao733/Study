#include<stdio.h>

int main(){
    char s[51];
    char a;
    gets(s);
    scanf("%c",&a);
    int i=0;
    while(s[i] != '\0'){
        if(s[i] == a){
            for(int n=i;n<49;n++){
                s[n] = s[n+1];
            }
        }
        i++;
    }
    printf("%s",s);
    return 0;
}