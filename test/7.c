#include<stdio.h>
#include<string.h>

int main(){
    
    int len,word=0,sentence=0,isVoid=1;
    char a[100];
    fgets(a,sizeof(a),stdin);
    len = strlen(a);
    for(int i=0;i<len;i++){
        if(a[i] == '.')sentence+=1;
        if(a[i] == ' ' && isVoid != 1){
            isVoid = 1;
            word += 1;
        }
        if(a[i] != ' ')isVoid = 0;
    }
    if(isVoid == 1)word -= 1;
    printf("the total word is %d\nthe total sentence is %d",word+1,sentence);
    return 0;
}