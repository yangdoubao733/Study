#include<stdio.h>

int main(){
    char a;
    printf("please input the first letter of someday:\n");
    switch (a = getchar())
    {
    case'M':
        printf("monday");
        break;
    
    case'W':
        printf("wednesday");
        break;
    case'F':
        printf("friday");
        break;
    case'S':
        getchar();
        printf("please input second letter:\n");
        switch (a = getchar())
        {
        case 'a':
            printf("saturday");
            break;
        case 'u':
            printf("sunday");
            break;
        default:
            printf("data error!");
            break;
        }
        break;
    case'T':
        getchar();
        printf("please input second letter:\n");
        switch (a=getchar())
        {
        case'u':
            printf("tuesday");
            break;
        case'h':
            printf("thursday");
            break;
        default:
            printf("data error!");
            break;
        }
        break;
    default:
        printf("data error!");
        break;
    }
    return 0;
}