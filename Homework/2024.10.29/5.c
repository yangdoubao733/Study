#include<stdio.h>
#include<string.h>

int insert(char str1[],char str2[], int pos){
    int len1=strlen(str1),len2=strlen(str2);
    if(pos<0 || pos>len1){
        printf("error");
        return 0;
    }
    char temp[100],r[500];
    int n=0;
    for(int i=pos;i<len1;i++){
        temp[n] = str1[i];
        n+=1;
    }
    temp[n] = '\0';
    int len3=strlen(temp);
    n=0;
    for(int i=0;i<len1-len3;i++){
        r[n] = str1[i];
        n+=1;
    }
    for(int i=0;i<len2;i++){
        r[n] = str2[i];
        n+=1;
    }
    for(int i=0;i<len3;i++){
        r[n] = temp[i];
        n+=1;
    }
    r[n] = '\0';
    printf("%s",r);

    
    return 0;
}

int main(){
    char str1[100],str2[100],str3[100];
    printf("Please input two strings:\n");
    gets(str1);
    
    gets(str2);
    
    int a;
    printf("Please input the position of insert:\n");
    scanf("%d",&a);
    insert(str1,str2,a);
    return 0;
}
