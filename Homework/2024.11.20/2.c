#include<stdio.h>

void my_strcat(char *s1,char *s2)

{
    char *head1 = s1;
    while(*head1 != '\0'){
        head1 ++;
    }
    char *head2 = s2;
    while(*head2 != '\0'){
        *head1 = *head2;
        head1++;
        head2++;
    }
    *head1 = '\0';
    printf("%s\n",s1);
}

int my_strchr(char *s, char c)

{
    char *head = s;
    while(*head != '\0'){
        if(*head == c){printf("It occurs");return 1;}
        head++;
    }
    printf("It doesn't occurs");
    return 1;

}

int main()

{
    char s1[100],s2[100];
    char c;
    gets(s1);
    gets(s2);
    scanf("%c",&c);
    my_strcat(s1,s2);
    my_strchr(s1,c);
}