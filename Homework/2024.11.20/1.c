#include<stdio.h>

#include<string.h>

void  reverse(char *string, int length)

{
    char *tail = string+(length-1),*head = string,temp;
    while(head < tail){
        temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
}

int main()

{
    char string[100];
    int length=0;
    printf("Input a string:\n");
    gets(string);
    length = strlen(string);
    reverse(string,length);
    printf("The reverse is:\n%s", string);
}