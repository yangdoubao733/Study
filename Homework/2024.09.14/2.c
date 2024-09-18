#include<stdio.h>

int main(){
    char a;
    int b;
    scanf("%c",&a);
    switch(a<='z'&&a>='a'?1:a<='Z'&&a>='A'?2:a<='9'&&a>='0'?3:4){
        case 1:printf("%c",a-32);break;
        case 2:printf("%c",a+32);break;
        case 3:b=(int)(a)-48;printf("%d",b*b);break;
    }
    return 0;
}
