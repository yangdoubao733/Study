#include<stdio.h>
#include<string.h>

void search(char *array, char *array_search, char *array_replace){
    for(char *i= array;i<array+100;i++){
        if(*i == *array_search){
            int target = 1;
            char *h1=i,*h2=array_search;
            char *head = i;
            while(*h1 != '\0'&& *h2 != '\0'){
                if(*h1 != *h2){
                    target = 0;
                    break;
                }
                h1++;h2++;
            }
            if(target == 1){
                int len=0;
                char *tail = h1;
                for(char *j = array_replace;*j != '\0';j++){
                    len++;
                }
                
            }
        }
    }
        
}


int main(){
    char array[100], array_search[20], array_replace[20];
    gets(array);
    gets(array_search);
    gets(array_replace);
    search(array, array_search, array_replace);
    puts(array);
    return 0;
}