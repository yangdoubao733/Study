#include<stdio.h>

int main(){
    char a[100];
    int start,del;
    gets(a);
    scanf("%d",&start);
    scanf("%d",&del);
    for(;start < 101;start++){
        a[start-1] = a[start+del-1];
    }
    printf("%s",a);
    return 0;
}