#include<stdio.h>
#include<string.h>

int main(){
    char a[100];
    gets(a);
    int n=strlen(a);
    for(int i=0;i<n;i++){
        for(int j=n;j>i;j--){
            if(a[j] > a[j-1]){
                char temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("%s",a);
    return 0;
}
