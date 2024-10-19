#include<stdio.h>
#include<string.h>

int main(){
    char a[51];
    gets(a);
    int n=strlen(a);
    int target=0;
    for(int i=0;i<n/2+1;i++){
        if(a[i] != a[n-i-1]){
            target=1;
        }
    }
    if(target == 0){
    printf("%s","YES");}
    else{
    printf("%s","NO");}
    return 0;
}
