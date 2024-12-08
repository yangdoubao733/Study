#include<stdio.h>

int main(){
    int a[26] = {0};
    char c[30];
    gets(c);
    int i=0;
    int target = 0;
    while(c[i] != '\0'){
        a[c[i] - 'A'] += 1;
        if(a[c[i] - 'A'] == 1){
            printf("%c ",c[i]);
            target ++;
        }
        i++;
    }
    printf("\n%d",target);
    return 0;
}